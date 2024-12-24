#include <stdio.h>
#include <stdint.h>

#include "image.h"

int main()
{
    int width = 200;
    int height = 100;

    header_t header;
    headerinfo_t info;

    header.type = 0x4D42;
    header.size = sizeof(header_t) + sizeof(headerinfo_t) + (width * height * 3);
    header.reserved = 0;
    header.offset = sizeof(header_t) + sizeof(headerinfo_t);

    info.isize = sizeof(headerinfo_t);
    info.width = width;
    info.height = height;
    info.planes = 1;
    info.bit_count = 24;
    info.compression = 0;
    info.size_image = 0;
    info.xpels_per_meter = 0;
    info.ypels_per_meter = 0;
    info.clr_important = 0;
    info.clr_used = 0;

    FILE* fp = NULL;
    fp = fopen("output.bmp", "wb");
    if(fp == NULL)
        return -1;
    fwrite(&header, sizeof(header_t), 1, fp);
    fwrite(&info, sizeof(headerinfo_t), 1, fp);

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            //uint8_t red = 0;
            uint8_t red = x * 255/width;

            uint8_t blue = 0;
            //uint8_t blue = x * 255/width;
            
            uint8_t green = 0;
            //uint8_t green = x * 255/width;
            
            fwrite(&blue, 1 , 1, fp);
            fwrite(&green, 1 , 1, fp);
            fwrite(&red, 1, 1, fp);
        }
    }
    fclose(fp);
    return 0;
}
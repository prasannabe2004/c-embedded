#include <stdint.h>

#pragma pack(push, 1)

typedef struct {
    uint16_t type;
    uint32_t size;
    uint32_t reserved;
    uint32_t offset;
} header_t;

typedef struct {
    uint32_t isize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    int32_t xpels_per_meter;
    int32_t ypels_per_meter;
    uint32_t clr_used;
    uint32_t clr_important;
} headerinfo_t;

#pragma pack(pop)
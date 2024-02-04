#ifndef EMBED_H
#include <stdint.h>

typedef struct {
    uint32_t size;
    const uint8_t* data;
} Embed;

// Embed embed = {15135, (const uint8_t*) {0x0}};

#endif /* EMBED_H */

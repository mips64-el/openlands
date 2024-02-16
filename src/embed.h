#ifndef EMBED_H
#define EMBED_H

#include <stdint.h>

typedef struct {
    uint32_t size;
    const uint8_t* data;
} Embed;

#endif /* EMBED_H */

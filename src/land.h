#ifndef LAND_H
#define LAND_H

typedef void (*Hook) (void);

typedef struct {
    Hook update;
} Land;

void land_load(Land*);
void land_update(Land*);
void land_unload(Land*);

#endif /* LAND_H */
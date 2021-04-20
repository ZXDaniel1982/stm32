#ifndef __VECTOR_H
#define __VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef void (*ListCallback)(void *);

typedef struct vElement_t {
    uint8_t index;
    void* data;
    struct vElement_t *next;
} Element_t;

typedef struct vList_t {
    uint8_t index;
    ListCallback func;
    Element_t *elementHead;
    Element_t *elementEnd;
    struct vList_t *next;
} List_t;

typedef struct {
    List_t *listHead;
    List_t *listEnd;
} Vector_t;

void Vector_Init(void);
List_t *Vector_AddList(uint8_t, ListCallback);
void *Vector_List_AddElement(List_t *, uint8_t, uint16_t);
void *Vector_List_GetElement(List_t *, uint8_t);
void Vector_List_DeleteElement(List_t *, uint8_t);
void Vector_List_WalkThrough(List_t *);

#ifdef __cplusplus
}
#endif
#endif  /* __VECTOR_H */

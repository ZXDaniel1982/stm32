#ifndef __VECTOR_H
#define __VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef void (*ListCallback)(void *);

typedef enum {
    LISTBUTTON = 1,
    LISTLABEL,
    LISTSENSOR,
    LISTTIMER
} ListObj;

typedef struct vElement_t {
    uint8_t index;
    void* data;
    struct vElement_t *last;
    struct vElement_t *next;
} Element_t;

typedef struct vSubVector_t {
    uint8_t index;
    ListCallback func;
    Element_t *elementHead;
    Element_t *elementEnd;
    struct vSubVector_t *next;
} SubVector_t;

typedef struct {
    SubVector_t *listHead;
    SubVector_t *listEnd;
} Vector_t;

void Vector_Init(void);
SubVector_t *Vector_AddList(uint8_t, ListCallback);
void *Vector_List_AddElement(SubVector_t *, uint8_t, uint16_t);
void *Vector_List_GetElement(SubVector_t *, uint8_t);
void Vector_List_DeleteElement(SubVector_t *, uint8_t);
void Vector_List_WalkThrough(SubVector_t *);

#ifdef __cplusplus
}
#endif
#endif  /* __VECTOR_H */

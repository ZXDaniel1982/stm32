#include <string.h>
#include "vector.h"

static Vector_t vector;

void Vector_Init()
{
    vector.listHead = NULL;
    vector.listEnd = NULL;
}

SubVector_t *Vector_AddList(uint8_t index, ListCallback func)
{
    SubVector_t *NewList = (SubVector_t *) malloc(sizeof(SubVector_t));

    NewList->index = index;
    NewList->func = func;
    NewList->elementHead = NULL;
    NewList->elementEnd = NULL;

    if (vector.listHead == NULL) {
        vector.listHead = NewList;
        vector.listEnd = vector.listHead;
        vector.listEnd->next = NULL;
    } else {
        vector.listEnd->next = NewList;
        vector.listEnd = NewList;
        vector.listEnd->next = NULL;
    }

    return vector.listEnd;
}

void *Vector_List_AddElement(SubVector_t *list, uint8_t index, uint16_t size)
{
    Element_t *NewElement = (Element_t *) malloc(sizeof(Element_t));
    if (NewElement == NULL) return NULL;

    NewElement->index = index;
    NewElement->data = malloc(size);
    if (NewElement->data == NULL) return NULL;

    if (list->elementHead == NULL) {
        list->elementHead = NewElement;
        list->elementEnd = list->elementHead;
        list->elementEnd->next = NULL;
    } else {
        list->elementEnd->next = NewElement;
        list->elementEnd = NewElement;
        list->elementEnd->next = NULL;
    }
    return NewElement->data;
}

void *Vector_List_GetElement(SubVector_t *list, uint8_t index)
{
    Element_t *element = list->elementHead;

    while (element) {
        if (element->index == index) {
            return element->data;
        }
        element = element->next;
    }
    return NULL;
}

void Vector_List_DeleteElement(SubVector_t *list, uint8_t index)
{
    Element_t *element = list->elementHead;

    while (element) {
        Element_t *next = element->next;
        if (element->index == index) {
            if (element->data != NULL) free(element->data);
            list->elementHead = element->next;
            free(element);
            return;
        }
        if ((next != NULL) && (next->index == index)) {
            element->next = next->next;
            if (next->data != NULL) free(next);
            free(next);
            return;
        }
        element = element->next;
    }
}

void Vector_List_WalkThrough(SubVector_t *list)
{
    Element_t *element = list->elementHead;

    if (list->func == NULL) return;

    while (element) {
        list->func(element->data);
        element = element->next;
    }
}


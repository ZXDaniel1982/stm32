#include <string.h>
#include "vector.h"

Vector_t vector;

void Vector_Init()
{
    vector.listHead = NULL;
    vector.listEnd = NULL;
}

List_t *Vector_AddList(uint8_t index)
{
    List_t *NewList = (List_t *) malloc(sizeof(List_t));

    NewList->index = index;
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

void Vector_List_AddElement(List_t *list, uint8_t index, uint16_t size, void *data)
{
    Element_t *NewElement = (Element_t *) malloc(sizeof(Element_t));
    NewElement->data = malloc(size);

    NewElement->index = index;
    memcpy(NewElement->data, data, size);

    if (list->elementHead == NULL) {
        list->elementHead = NewElement;
        list->elementEnd = list->elementHead;
        list->elementEnd->next = NULL;
        NewElement = NULL;
    } else {
        list->elementEnd->next = NewElement;
        list->elementEnd = NewElement;
        list->elementEnd->next = NULL;
        NewElement = NULL;
    }
}

void *Vector_List_GetElement(List_t *list, uint8_t index)
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

void Vector_List_DeleteElement(List_t *list, uint8_t index)
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
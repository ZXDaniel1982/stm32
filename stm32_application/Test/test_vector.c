#include <string.h>
#include "vector.h"

static SubVector_t *list1 = NULL;
static SubVector_t *list2 = NULL;
static SubVector_t *list3 = NULL;

typedef struct {
    int v1;
    int v2;
} test1_t;

typedef struct {
    int v1;
    int v2;
    int v3;
} test2_t;

static void show1(void *data)
{
    if (data == NULL) return;

    test1_t *test = (test1_t *) data;

    printf("%s, (%d, %d)\n", __func__, test->v1, test->v2);
}

static void show2(void *data)
{
    if (data == NULL) return;

    test2_t *test = (test2_t *) data;

    printf("%s, (%d, %d, %d)\n", __func__, test->v1, test->v2, test->v3);
}

void main()
{
    Vector_Init();
    list1 = Vector_AddList(1, show1);
    list2 = Vector_AddList(2, show2);
    //list3 = Vector_AddList(3);

    test1_t *test11 = (test1_t *) Vector_List_AddElement(list1, 1, sizeof(test1_t));
    test11->v1 = 11;
    test11->v2 = 21;

    test1_t *test12 = (test1_t *) Vector_List_AddElement(list1, 2, sizeof(test1_t));
    test12->v1 = 111;
    test12->v2 = 212;

    test1_t *val1 = (test1_t *)Vector_List_GetElement(list1, 1);
    printf("%d %d\n", val1->v1, val1->v2);
    test1_t *val2 = (test1_t *)Vector_List_GetElement(list1, 2);
    printf("%d %d\n", val2->v1, val2->v2);

    Vector_List_DeleteElement(list1, 1);

    test1_t *test13 = (test1_t *) Vector_List_AddElement(list1, 3, sizeof(test1_t));
    test13->v1 = 22;
    test13->v2 = 44;

    test1_t *val3 = (test1_t *)Vector_List_GetElement(list1, 1);
    if (val3 == NULL) printf("val3 is NULL\n");
    test1_t *val4 = (test1_t *)Vector_List_GetElement(list1, 2);
    printf("%d %d\n", val4->v1, val4->v2);
    test1_t *val5 = (test1_t *)Vector_List_GetElement(list1, 3);
    printf("%d %d\n", val5->v1, val5->v2);

    Vector_List_WalkThrough(list1);

    Vector_List_DeleteElement(list1, 1);
    Vector_List_DeleteElement(list1, 2);
    Vector_List_DeleteElement(list1, 3);



    test2_t *test111 = (test2_t *) Vector_List_AddElement(list2, 1, sizeof(test2_t));
    test111->v1 = 11;
    test111->v2 = 21;
    test111->v3 = 231;

    test2_t *test121 = (test2_t *) Vector_List_AddElement(list2, 2, sizeof(test2_t));
    test121->v1 = 111;
    test121->v2 = 212;
    test121->v3 = 59;

    test2_t *val11 = (test2_t *)Vector_List_GetElement(list2, 1);
    printf("%d %d %d\n", val11->v1, val11->v2, val11->v3);
    test2_t *val21 = (test2_t *)Vector_List_GetElement(list2, 2);
    printf("%d %d %d\n", val21->v1, val21->v2, val21->v3);

    Vector_List_DeleteElement(list2, 1);

    test2_t *test131 = (test2_t *) Vector_List_AddElement(list2, 3, sizeof(test2_t));
    test131->v1 = 22;
    test131->v2 = 44;
    test131->v3 = 98;

    test2_t *val31 = (test2_t *)Vector_List_GetElement(list2, 1);
    if (val31 == NULL) printf("val31 is NULL\n");
    test2_t *val41 = (test2_t *)Vector_List_GetElement(list2, 2);
    printf("%d %d %d\n", val41->v1, val41->v2, val41->v3);
    test2_t *val51 = (test2_t *)Vector_List_GetElement(list2, 3);
    printf("%d %d %d\n", val51->v1, val51->v2, val51->v3);

    val51->v1 = 789;
    val51->v2 = 456;
    val51->v3 = 123;

    test2_t *val52 = (test2_t *)Vector_List_GetElement(list2, 3);
    printf("%d %d %d\n", val52->v1, val52->v2, val52->v3);

    Vector_List_WalkThrough(list2);
    
    Vector_List_DeleteElement(list2, 1);
    Vector_List_DeleteElement(list2, 2);
    Vector_List_DeleteElement(list2, 3);

    free(list1);
    free(list2);
}

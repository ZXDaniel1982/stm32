#include "../Unity/unity.h"
#include "spc.h"

void setUp(void)
{
    printf("Test start\n");
}

void tearDown(void)
{
    printf("Test finish\n");
}

void test_func(void)
{
	TEST_ASSERT_EQUAL(Default, GetKeyType("Def"));
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test/TestFunc.c");
  RUN_TEST(test_func);

  return (UnityEnd());
}

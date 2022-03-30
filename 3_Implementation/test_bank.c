#include "unity.h"
#define PROJECT_NAME "Bank_Managment_System"
extern void test_bank();
void setUp(void)
{
}
void tearDown(void)
{
}
int main(void){
    UnityBegin(NULL);
    RUN_TEST(test_bank);
    return(UnityEnd());
}
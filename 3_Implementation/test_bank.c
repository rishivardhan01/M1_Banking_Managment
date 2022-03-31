#include "unity.h"
#define PROJECT_NAME "Bank_Managment_System"
/* Prototypes for all the test function */
/**
 * @brief testing function for banking management system
 * 
 */
extern void test_bank();
/* Required by the unity test framework */
void setUp(void)
{
}
/* Required by the unity test framework */
void tearDown(void)
{
}
/* Start of the application test */
int main(void){
    /* Initiate the unity test framework */
    UnityBegin(NULL);
    /* Run test functions */
    RUN_TEST(test_bank);
    /* Close the unity test framework */
    return(UnityEnd());
}
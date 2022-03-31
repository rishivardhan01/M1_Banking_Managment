#include "unity.h"
#include "bank_operatons.h"
#define PROJECT_NAME "BANKING_MANAGMENT_SYSTEM"
/* Prototypes for all the test functions */
/**
 * @brief testing function for file
 * 
 */
void test_file();
/**
 * @brief testing function for enqueue
 * 
 * @param tok 
 */
void test_enqueue(int tok);
/**
 * @brief testing function for tokencall
 * 
 * @return int 
 */
int test_tokencall();
/**
 * @brief testing function for details
 * 
 */
void test_details();
/**
 * @brief testing function for credit
 * 
 */
void test_credit();
/**
 * @brief testing function for debit
 * 
 */
void test_debit();
/**
 * @brief testing function for dequeue
 * 
 */
void test_dequeue();
/**
 * @brief testing function for validate
 * 
 * @param c 
 * @return int 
 */
int test_validate(int c);
/**
 * @brief testing function for ndata
 * 
 * @param c 
 */
void test_ndata(int c);
/**
 * @brief testing function for balance
 * 
 * @param line_no 
 * @return float 
 */
float test_balance(float line_no);
/**
 * @brief testing function for changebalance
 * 
 * @param line 
 * @param balance 
 */
void test_changebalance(int line,float balance);
/**
 * @brief testing function for number_of_lines
 * 
 * @return int 
 */
int test_number_of_lines();
/**
 * @brief testing function for close
 * 
 */
void test_close();
/**
 * @brief testing function for Return
 * 
 */
void test_Return();
/* Required by the unity test framework */
void setUp()
{

}
/* Required by the unity test framework */
void tearDown()
{

}
/* Start of the application test */
int main()
{
    /* Initiate the unity test framework */
    UNITY_BEGIN();
    /* Run test functions */
    RUN_TEST(test_file);
    RUN_TEST(test_enqueue);
    RUN_TEST(test_tokencall);
    RUN_TEST(test_details);
    RUN_TEST(test_credit);
    RUN_TEST(test_debit);
    RUN_TEST(test_dequeue);
    RUN_TEST(test_validate);
    RUN_TEST(test_ndata);
    RUN_TEST(test_balance);
    RUN_TEST(test_changebalance);
    RUN_TEST(test_number_of_lines);
    RUN_TEST(test_close);
    RUN_TEST(test_Return);
    /* Close the unity test framework */
    return UNITY_END;
#include "unity.h"
#include "bank_operatons.h"
#define PROJECT_NAME "BANKING_MANAGMENT_SYSTEM"
void test_file();
void test_enqueue(int tok);
int test_tokencall();
void test_details();
void test_credit();
void test_debit();
void test_dequeue();
int test_validate(int c);
void test_ndata(int c);
float test_balance(float line_no);
void test_changebalance(int line,float balance);
int test_number_of_lines();
void test_close();
void test_Return();
void setUp()
{

}
void tearDown()
{

}
int main()
{
    UNITY_BEGIN();
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
    return UNITY_END;
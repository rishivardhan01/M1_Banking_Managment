/**
 * @file bank_operations.h
 * @author Rishivardhan T R(rishivardhan.tr.2018.ece@ritchennai.edu.in)
 * @brief Header file for banking managment system
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _BANK_OPERATIONS_H_
#define _BANK_OPERATIONS_H_

/**
 * @brief SHOWS THE RECORD OF TRANSACTION DETAILS
 * @return TEXT FILE GENERATED WITH TRANSACTION DETAILS
 */
void file();

/**
 * @brief GIVES TOKEN INFORMATION
 * @return INTEGER VALUE OF TOKEN
 */
void enqueue(int operand);

/**
 * @brief GIVES TOKEN CALLING INFORMATION
 * @return INTEGER VALUE OF TOKEN
 */
int tokencall();

/**
 * @brief GIVES ACCOUNT INFORMATION
 * @return SHOWS INFORATION OF ACCOUNT DETAILS
 */
void details();

/**
 * @brief GIVES CREDIT INFORMATION
 * @return SHOWS INFORATION OF CREDITTED DETAILS
 */
void credit();

/**
 * @brief GIVES DEBIT INFORMATION
 * @return SHOWS INFORATION OF DEBITTED DETAILS
 */
void debit();

/**
 * @brief GIVES TOKEN DECALLING INFORMATION 
 * @return INTEGER VALUE OF TOKEN
 */
void dequeue();

/**
 * @brief VERIFICATION OF ACCOUNT TRANSACTION DETAILS
 * @return SHOWS VERIFIED INFORMATION
 */
int validate(int operand);

/**
 * @brief GIVES ACCOUNT DETAILS
 * @return TEXT FILE GENERATED
 */
void ndata(int operand);

/**
 * @brief GIVES BALANCE INFORMATION
 * @return TEXT FILE GENERATED
 */
float balance(int operand);

/**
 * @brief GIVES UPDATED BALANCE INFORMATION
 * @return TEXT FILE GENERATED
 */
void changebalance(int operand1,float operand2);

/**
 * @brief DOING FILE OPERATIONS FOR TEXT FILE 
 * @return TEXT FILE GENERATED
 */
int number_of_lines();

/**
 * @brief GIVES WRONG INFORMATION
 * @return BACK TO MAIN PAGE
 */
void close();

/**
 * @brief GIVES TRANSACTION DETAILS
 * @return BACK TO MAIN PAGE
 */
void Return();

#endif /* #define _BANK_MANAGMET_SYSTEM_H_ */
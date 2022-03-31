# Name of the project
PROJECT_NAME = BANKING_MANAGMENT_SYSTEM

#Doxyfile folder
DOC = documentation

#All source code files
SRC = bank.c\
src/bank_operations.c

#All test source files
TEST_SRC = src/bank_operations.c\
test/test_bank_operations.c\
unity/unity.c

TEST_OUTPUT = Test_a.out

#All include folders with header files
INC = -Iinc\
-Iunity\

#Project Output Name
PROJECT_OUTPUT = bank.out

#Document files
DOCUMENTATION_OUTPUT = documentation/html
Build:
	gcc function.c test_bank.c unity/unity.c -Iunity
Run:
	./a.out
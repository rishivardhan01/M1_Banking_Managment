/**
 * @file bank.c
 * @author Rishivardhan T R (rishivardhan.tr.2018.ece@ritchennai.edu.in)
 * @brief This is the main program where the project is run
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>


void details();
void credit();                                                              
void debit();                                                              
void close();                                                               
void enqueue(int);
void dequeue();
void file();
void ndata(int);
void Return();
void changebalance(int,float);
int validate(int);
int tokencall();
int number_of_lines();
void balance(float);

int c_total=0, d_total=0;
char text[60]="";

struct bank
{
    int token;
    int ac_no;
    char name[20];
    float amount;
    struct bank *next; 
}*front,*rear,*temp,*front1;


/* Start of the application */
/**
 * @brief Main program
 * 
 * @return int 
 */
int main()
{
    
    FILE *f;
    int t,i=1,c,temp1,b=0,d=0;
    f=fopen("PROJECT 7 - tokens.txt","r");
    fscanf(f,"%d",&t);
    fclose(f);

    front = rear = NULL;    
    file();                 
    FILE *fptr;
    printf("\n\n\t**********************************************************************************************\n");
    printf("                                           BANK MANAGEMENT SYSTEM\n");
    printf("\t**********************************************************************************************\n");
    while(1)
    {
        while(i<=t)
        {
            enqueue(i);
            i++;
        }

        if ((front != NULL) && (rear != NULL))   
        {
            while(front!=rear )                  
            {
                tokencall();
            }
            if(front==rear)                      
            {
                d=tokencall();
                if(d==3)
                    continue;
            }
        }


        f=fopen("PROJECT 7 - tokens.txt","r");
        fscanf(f,"%d",&temp1);
        fclose(f);

        
        if(t==temp1)
        {
            printf("\n\tNo more tokens in the queue\n");

            int a;
            printf("\t----------------------------------------------------------------------------------------------\n");
            printf("\n                                             QUEUE IS EMPTY......WAITING.....\n\n");
            printf("\t1. Press 0 to Exit\n\t2. Press any other key to continue\n\t3. Display transaction detail.\n\tEnter the choice ");
            scanf("%d",&a);
            system("cls");
            if(a==0)
            {
                FILE *f;
                f=fopen(text,"a");
                fprintf(f,"\n\n\tTotal Amount Credited Today    : %d\n\tTotal Amount Debited Today     : %d\n",c_total,d_total);
                fclose(f);
                break;
            }
            if(a==3)
            {
                fptr = fopen(text, "r");           
                c = fgetc(fptr);
                while (c != EOF)
                {
                    printf ("%c", c);
                    c = fgetc(fptr);
                }
                fclose(fptr);
                fptr=NULL;
                printf("\n\n");                  
                printf("\tTotal Amount Credited Today    : %d\n\tTotal Amount Debited Today     : %d\n",c_total,d_total);
                Return();
                system("cls");
            }
        }

        

        t=temp1;

    }
    printf("\n\n\n\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\tCLOSING APPLICATION\t//////////////// \n\n");
    return 0;
}


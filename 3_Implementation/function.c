#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
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

void file()
{
    char c;

    time_t mytime = time(NULL);              
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';

    

    char new_char;
    int ctr=0,i=0;                  
    while (time_str[ctr])          
    {
    

        if(time_str[ctr]==':')      
            time_str[ctr]='-';
        if(ctr==10)
            time_str[ctr]='(';
        if(ctr ==19)
            time_str[ctr]=')';
        new_char=time_str[ctr];

        if (isspace(new_char))      
        {
            text[ctr]='_';
        }
        else
        {
            if(ctr==10 || ctr==20)
            {
                text[ctr+i]='_';
                i++;
                text[ctr+i]='_';
                i++;
            }
            text[ctr+i]=time_str[ctr];
        }

        ctr++;
    }
    char extension[30] = "_Transaction_Details.txt"; 
    strcat(text,extension);

    FILE *f;
    f=fopen(text,"a");
    fprintf(f,"***********************************************      TRANSACTION LIST        *********************************************\n\n");
    fprintf(f,"|Sn.|   Time   |              Name            |           Account no.        |            Amount            |    Type    |\n");
    fprintf(f,"--------------------------------------------------------------------------------------------------------------------------\n");
    fclose(f);
}

void enqueue(int tok)
{
    if (rear == NULL)                
    {
        rear = (struct bank *)malloc(sizeof(struct bank));
        rear->next = NULL;
        rear->token = tok;
        front = rear;
    }
    else                               
    {
        temp=(struct bank *)malloc(sizeof(struct bank));
        rear->next = temp;
        temp->token = tok;
        temp->next = NULL;

        rear = temp;
    }
}

int tokencall()
{
    int c;
    FILE *fptr;
    printf("\n\n\t\t\t  \\\\\\\\\\\\\\\\\\\\\\*****     TOKEN NO. %d     *****///////////\n\n",front->token);
    printf("\t1. Transaction section.\n\t2. Next token.\n\t3. Display transaction details.\n\t4. Exit.\n\tEnter the choice: ");
    scanf("%d", &c);
    switch(c)
    {
    case 1:
        details(front->token);         
        return 0;
    case 2:
        system("cls");
        if(front==rear)                 
        {
            dequeue();
            return 0;
        }

        else                         
        {
            printf("\n                                        ***** MOVING TO NEXT NUMBER *****\n");
            dequeue();
            return 0;
        }
    case 3:
        system("cls");                  
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
        if(front==rear)
            return 3;
        return 0 ;
    case 4:
        system("cls");              
        close();
        return 0;
    default :
        system("cls");
        printf("\n\t\t\t\t\t____Enter a valid number____\n");
    }
}

void details()
{
    system("cls");
    int n;
    while(1)
    {
        printf("\n\n\t  \t\t\\\\\\\\\\\\\\\\\\\\\\*****     TOKEN NO. %d     *****///////////\n\n",front->token);
        printf("\n\n\t\t\t\t    *********** DETAILS ************\n\t1. Credit amount\n\t2. Debit amount\n\t3. Next token\n");
        printf("\tEnter your option :");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            credit();
            return;
        case 2:
            debit();
            return;
        case 3:
            system("cls");
            if(front==rear)   
            {
                dequeue();
                return;
            }

            else             
            {
                printf("\n\t\t\t\t\t***** MOVING TO NEXT NUMBER *****\n");
                dequeue();
                return ;
            }
            return;
        default:
            system("cls");
            printf("\n\t\t\t\t\t____Enter a valid number____\n");
        }
    }
}

void credit()
{
    FILE *fp;
    int a;
    a=validate(1);      
    if(a==1)            
    {
        char t[15]="";
        int i=0,j=0;
        time_t mytime = time(NULL);              
        char * time_str = ctime(&mytime);
        time_str[strlen(time_str)-1] = '\0';
        while(time_str[i])                      
        {
            if(i>10&&i<19)
            {
                t[j]=time_str[i];
                j++;
            }
            i++;
        }
        printf("\n\tAmount Credited\n");
        printf("\n\tThank you...");
        fp=fopen(text,"a");         
        fprintf(fp,"|%3d|%9s |%30s|%30d|%30.2f|%12s|\n",front->token,t,front->name,front->ac_no,front->amount,"Credited");
        fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------\n");
        fclose(fp);
        dequeue();
        Return();
        system("cls");
    }
    else            
    {
        int b;
        while(1)
        {
            printf("\t1. Move to next token\n\t2. Return to same token and enter the correct details.\n\tEnter the choice.");
            scanf("%d",&b);
            switch(b)
            {
            case 1:
                system("cls");
                dequeue();
                return;
            case 2:
                system("cls");
                return;
            default:
                system("cls");
                printf("\n\n\tEnter a valid choice.\n");
            }
        }
    }
}
void debit()
{
    int a;
    a=validate(2);          
    if(a==1)                 
    {
        dequeue();
        Return();
        system("cls");
    }
    else                    
    {
        int b;
        while(1)
        {
            printf("\t1. Move to next token\n\t2. Return to same token and enter the correct details.\n\tEnter the choice.");
            scanf("%d",&b);
            switch(b)
            {
            case 1:
                system("cls");
                dequeue();
                return;
            case 2:
                system("cls");
                return;
            }
        }
    }

}

void dequeue()                  
{
    front1=front;
    if (front1->next != NULL)   
    {
        front1 = front1->next;
        free(front);
        front = front1;
    }
    else                            {
        free(front);
        front = NULL;
        rear = NULL;
    }
}


// validating the entered account number, by searching the account number in the data file.

int validate(int c)
{
    FILE *fp;
    char ch;
    int a,b;
    float bal,change_bal=0;
    int linesCount=1,found=0;
    fp=fopen("PROJECT  7 - Account_numbers.txt","r");       
    printf("\n\tEnter the Account number          :");
    scanf("%d",&b);
    while((ch=fgetc(fp))!=EOF)                               
    {
        if(ch=='\n')                                         
        {
            fscanf(fp,"%d",&a);
            if(a==b)                                     
            {
                ndata(linesCount);                           
                front->ac_no=a;
                if(c==1)
                {
                    bal=balance(linesCount);                               
                    printf("\n\tEnter the amount to credit\t  :");
                    scanf("%f",&front->amount);
                    c_total=c_total+front->amount;
                    change_bal= bal+front->amount;
                    printf("\tBalance Updated\t\t\t  :%.2f\n",change_bal);
                    changebalance(linesCount,change_bal);
                }
                if(c==2)
                {
                    bal=balance(linesCount);                              
                    printf("\n\tEnter the amount to debit\t  :");
                    scanf("%f",&front->amount);
                    if(front->amount<=bal)
                    {
                        char t[15]="";
                        int i=0,j=0;
                        time_t mytime = time(NULL);              
                        char * time_str = ctime(&mytime);
                        time_str[strlen(time_str)-1] = '\0';
                        while(time_str[i])                      
                        {
                            if(i>10&&i<19)
                            {
                                t[j]=time_str[i];
                                j++;
                            }
                            i++;
                        }
                        change_bal= bal-front->amount;
                        d_total=d_total+front->amount;
                        printf("\tBalance Updated\t\t\t  :%.2f\n",change_bal);
                        changebalance(linesCount,change_bal);
                        printf("\n\tAmount debited.\n");
                        printf("\n\tThank you...");
                        FILE *fp;
                        fp=fopen(text,"a");                              
                        fprintf(fp,"|%3d|%9s |%30s|%30d|%30.2f|%12s|\n",front->token,t,front->name,front->ac_no,front->amount,"Debited");
                        fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------\n");
                        fclose(fp);
                    }
                    else
                    {
                        printf("\n\tThe Amount cannot be withdrawn due to Insufficient balance.");
                    }
                }
                found=1;
                break;
            }
            linesCount++;
        }
    }
    if(found==1)               
    {
        fclose(fp);
        return 1;
    }
    if(found==0)               
    {
        printf("\n\n\t\t\t\t   .......ACCOUNT NUMBER NOT FOUND......\n");
        printf("\t----------------------------------------------------------------------------------------------\n");
    }
    fclose(fp);
    return 0;
}

void ndata(int c)                                   
{
    FILE *fn;
    fn=fopen("PROJECT 7 - User_Names.txt","r");     
    int count = 0;
    char d[20];

    char line[256];
    while (fgets(line, sizeof line, fn) != NULL)    
    {
        if (count == c)                             
        {
            printf("\tAccount name\t\t\t  :%s",line);
            line[strlen(line)-1]='\0';
            strcpy(front->name,line);
            break;
        }
        else
        {
            count++;
        }
    }
    fclose(fn);

}



void balance(float line_no)
{
    FILE *f;
    char ch;
    int count=1;
    float amount;
    f=fopen("PROJECT 7 - balance.txt","r");
    while((ch=fgetc(f))!=EOF)
    {

        if(ch=='\n')                                  
        {
            fscanf(f,"%f",&amount);                    
            if(count==line_no)
            {
                printf("\tAccount balance\t\t\t  :%.2f\n",amount);
                fclose(f);
                return amount;
            }
            count++;
        }
    }
}



void changebalance(int line,float balance)      
{                                                
    int max;
    max=number_of_lines();
    FILE *fPtr,*fTemp;
    char ch;
    int  count;
    fPtr  = fopen("PROJECT 7 - balance.txt", "r");
    fTemp = fopen("replace.tmp", "a");
    count = 0;
    float temp;

    while((ch=fgetc(fPtr))!=EOF)           
    {
        if(count==0)                        
        {
            fputc(ch,fTemp);
            if(ch=='\n')
            {
                count++;
            }
        }
        if(ch=='\n')                    
        {
            fscanf(fPtr,"%f",&temp);
            if (count == line)
            {
                fprintf(fTemp,"%.2f",balance);
                if(count<max)                   
                    fprintf(fTemp,"\n");        
            }
            else
            {
                fprintf(fTemp,"%.2f",temp);
                if(count<max)
                    fprintf(fTemp,"\n");
            }
            count++;
        }
    }
    fclose(fPtr);
    fclose(fTemp);
    remove("PROJECT 7 - balance.txt");
    rename("replace.tmp", "PROJECT 7 - balance.txt");
}


int number_of_lines()
{

    FILE *fp;
    char ch;
    int linesCount=0;
    fp=fopen("PROJECT 7 - balance.txt","r");

    while((ch=fgetc(fp))!=EOF)               
    {
        if(ch=='\n')                           
            linesCount++;
    }
    fclose(fp);
    return linesCount;

}

void close()
{
    int a;
    char pass1[10]="hcl123", pass2[10];
    printf("\n\n\n\tEnter the password : ");
    scanf("%s",pass2);
    a=strcmp(pass1,pass2);
    if(a==0)
    {
        FILE *f;
        f=fopen(text,"a");
        fprintf(f,"\n\n\tTotal Amount Credited Today    : %d\n\tTotal Amount Debited Today     : %d\n",c_total,d_total);
        fclose(f);
        printf("\n\n\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\tCLOSING APPLICATION\t//////////////// \n\n");
        exit(0);
    }
    else
    {
        system("cls");
        printf("\n\n\t*****INCORRECT PASSWORD*****\n\n");
        Return();
        system("cls");
    }
}

void Return()
{
    printf("\n\t----------------------------------------------------------------------------------------------\n");
    int a;
    printf("\n\tPress any button to return <-  : ");
    scanf("%d",&a);
}
void test_bank(){
    printf("test passed");
}
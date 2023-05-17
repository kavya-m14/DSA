#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
void push(int);
void pop();
int a[MAX];
int top;
int stack[MAX];
FILE *ftptr1;
FILE *ftptr2;
FILE *ftptr3;
FILE *ftptr4;
FILE *ftptr5;
int u , l, i, count, m, j, temp, random,p;
int main ()
{

    ftptr1 = fopen("randomno.txt", "w");
    printf("Enter no. of Random Numbers to be Generated ");
    scanf ("%d", &count);

    //count = 100;

    printf("Enter the Upper limit ");
    scanf ("%d", &u);
    printf("Enter the Lower limit ");
    scanf ("%d", &l);

    int  ch,x,i;
    top=-1;
    for (i = 0; i < MAX; i++) {
      a[i]=rand();
      fprintf(ftptr1,"%d",a[i]);
   }

   fclose(ftptr1);
    while(1)
   {
      printf("1--PUSH\n");
      printf("2--POP\n");


    printf("enter the choice\n");
      scanf("%d",&ch);

     switch(ch)
      {
         case 1:ftptr5 = fopen("op.txt", "a");
                fprintf(ftptr5,"push\n");
                fclose(ftptr5);
                i=x;
                int p=a[i];
                x=x+1;
                push(p);
                break;
         case 2:ftptr5=fopen("op.txt","a");
                fprintf(ftptr5,"pop\n");
                fclose(ftptr5);
                pop();
                break;
         default:printf("invalid choice\n");
                 break;
        }
    }
}
void push(int p)
{
    ftptr2=fopen("stack.txt","a");
    ftptr4=fopen("push.txt","a");
    int x;
    if(top==MAX-1)
    {
        printf("stack is full\n");
    }
    else
    {
        x=p;
        fprintf(ftptr2,"%d  ",x);
        top++;
        stack[top]=x;
        fprintf(ftptr4,"%d  ",stack[top]);

    }
    fclose(ftptr2);
    fclose(ftptr4);


}
void pop()
{
    ftptr3=fopen("pop.txt","a");
    if(top==-1)

    {
        printf("stack is empty\n");
    }
    else
    {
        fprintf(ftptr3,"%d  ",stack[top]);
        top--;
    }
    fclose(ftptr3);

}

#include<stdio.h>
#define MAX 100
void push();
void pop();
void display();
int top;
int stack[MAX];
int a[MAX];
FILE*fp1,*fp2,*fp3,*fp4,*fp5;
main()
{
    fp1=fopen("f1.txt","w");
    int ch,x,i;
    top=-1;
    for(i=0;i<MAX;i++)
    {
        a[i]=rand();
       fprintf(fp1,"%d  ",a[i]);
    }
    fclose(fp1);

    while(1)
    {
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:fp5=fopen("f5.txt","a");
                   fprintf(fp5,"push\n");
                   fclose(fp5);
                   i=x;
                   int p=a[i];
                   x=x+1;
                   push(p);
                   break;
            case 2:fp5=fopen("f5.txt","a");
                   fprintf(fp5,"pop\n");
                   fclose(fp5);
                   pop();
                   break;
            default:printf("invalid choice\n");
                    break;
        }
    }
}
void push(int p)
{
    fp2=fopen("f2.txt","a");
    fp4=fopen("f4.txt","a");
    int x;
    if(top==MAX-1)
    {
        printf("stack is full\n");
    }
    else
    {
        x=p;
        fprintf(fp2,"%d  ",x);
        top++;
        stack[top]=x;
        fprintf(fp4,"%d  ",stack[top]);

    }
    fclose(fp2);
    fclose(fp4);


}
void pop()
{
    fp3=fopen("f3.txt","a");
    if(top==-1)

    {
        printf("stack is empty\n");
    }
    else
    {
        fprintf(fp3,"%d  ",stack[top]);
        top--;
    }
    fclose(fp3);

}

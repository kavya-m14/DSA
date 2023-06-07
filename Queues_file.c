//Queues operation using file                                                                                                                                                                                #include<stdio.h>
#include<stdlib.h>
#define SIZE 50

struct queue
{
    int  data[SIZE];
    int rear,front;
};

void enqueue(struct queue *qptr,int num)
{
    if(qptr->rear==SIZE-1)
        printf("Queue Overflow\n");
    else
    {
        qptr->rear++;
        qptr->data[qptr->rear]=num;
    }
}

int dequeue(struct queue *qptr)   //Deletes first element of a queue
{
    int num;
    if(qptr->front==qptr->rear)
        printf("Queue Underflow\n");
        //return num;
    else
    {
        qptr->front++;
        num=qptr->data[qptr->front];
    }
    return num;
}

void display(struct queue *qptr)
{
    if(qptr->front==qptr->rear)
        printf("Queue Empty\n");
    else
    {
        for(int i=qptr->front+1;i<=qptr->rear;i++)
            printf("%d\n",qptr->data[i]);
    }
}

int main()
{
    int first,last,n,a[100],ch;
    struct queue *qptr,q;
    FILE *fp,*fp1,*fp2,*fp3;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    fp=fopen("input.txt","r+");

    printf("Enter the interval\n");
    scanf("%d%d",&first,&last);
    printf("Enter number of random numbers to be generated\n ");
    scanf("%d",&n);
    int count=0;
    for(int i=0;i<n;i++)
    {

        a[i]=(rand()%(last+1-first)+first);
        fprintf(fp,"%d ",a[i]);

    }
    int element;
    //int count=n;
    while(1)
    {
        fp1=fopen("enqueue.txt","a");
        fp2=fopen("dequeue.txt","a");
         fp3=fopen("operation.txt","a");
        printf("1.Enqueue 2.Dequeue 3.Display 4.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: element=a[count];
                    count++;
                     fprintf(fp1,"%d\n",element);
                     fprintf(fp3,"%d was enqueued\n",element);
                     enqueue(qptr,element);
                     break;
            case 2: element=dequeue(qptr);
                    if(element==-1)
                        printf("Queue underflow\n");
                    else
                    {
                        printf("Dequeue element is %d\n",element);
                        fprintf(fp2,"%d\n",element);
                        fprintf(fp3,"%d was dequeued\n",element);
                    }
                    break;
            case 3: display(qptr);
                    break;

            case 4: fclose(fp);
                     fclose(fp1);
                    fclose(fp2);
                    fclose(fp3);
                    exit(0);
                    break;

        }

    }


}

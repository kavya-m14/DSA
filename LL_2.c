#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
           int data;
           struct node *next;
};
struct node *head,*newnode,*temp,*temp1;
struct node * insert(struct node *newnode,struct node *head);
main()
{
           int n;
           head=NULL;
           scanf("%d",&n);
           clock_t start ,end;
           int i;
           double cputime;

           for(i=0;i<n;i++)
           {
                      newnode=(struct node*)malloc(sizeof(struct node));
                      newnode->data=rand()%100;

                      head=insert(newnode,head);
           }

           int j;
           temp=head;
           start=clock();

            temp1=(struct node*)malloc(sizeof(struct node));
           for(i=0;i<n;i++)
           {temp=head;
                     while(temp->next!=NULL)
                     {
                                if(temp->next->data<temp->data)
                                {


                                            temp1->data=temp->data;
                                            temp->data=temp->next->data;
                                            temp->next->data=temp1->data;
                                }
                                  temp=temp->next;
                     }

           }

           end=clock();
           cputime=((double)(end-start))/CLOCKS_PER_SEC;
           FILE *fp;
           fp=fopen("san.txt","w");
           temp=head;
           while(temp!=NULL)
           {

                      fprintf(fp,"%d\n",temp->data);
                      temp=temp->next;
           }

           fprintf(fp,"time used=%lf\n",cputime);
           fclose(fp);


}
struct node * insert(struct node *newnode,struct node *head)
{
           if(head==NULL)
           {
                      head=newnode;
           head->next=NULL;
           }
           else
           {
                      newnode->next=head;
                      head=newnode;
           }
           return(head);

};


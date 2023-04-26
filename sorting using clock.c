#include<stdio.h>
#include<time.h>
void main()
{
    int i,j;
    int n;

    int temp=0;
     FILE* fp3,*fp4;
     fp3=fopen("raksha.txt","w");
     fp4=fopen("hello.txt","w");
     time_t t;
     srand((unsigned) time(&t));
     n=6;
     int p=n;
     int ar2[n];
     clock_t st,et,st2,et2;
     st=clock();


   //generating 100 random numbers//

    for(i=0;i<n;i++)
    {
        ar2[i]=rand()%1000;
        fprintf(fp3,"%d\n",ar2[i]);

    }
    et=clock();
    double time_taken1 = (double)(et-st)/CLOCKS_PER_SEC;
    printf("Time taken to generate the random numbers is\n");
    printf("%lf\n",time_taken1);



      st2=clock();

    //sorting the generated random numbers//
     for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
           if(ar2[j]>ar2[j+1])
           {
              temp=ar2[j];
               ar2[j]=ar2[j+1];
               ar2[j+1]=temp;
           }
        }
    }


    //storing the sorted random numbers into a file//


    for(i=0;i<p;i++)
    {
         fprintf(fp4,"%d\n",ar2[i]);
    }

    fclose(fp3);
    fclose(fp4);

    et2=clock();
    double time_taken = (double)(et2-st2)/CLOCKS_PER_SEC;
    printf("Time taken to execute the sorting of random numbers is\n");
    printf("%lf\n",time_taken);
}

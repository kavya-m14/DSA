// Generate random numbers and display the time taken to sort those numbers
#include <stdio.h>
#include <time.h>

int main ()
{
    clock_t t ;
    FILE *ft , *f ;
    ft = fopen("text.txt", "w");
    int a[100];
    srand ( time(0) );

    int  u , l, i, count, m, j, temp, random;
    printf("Enter no. of Random Numbers to be Generated ");
    scanf ("%d", &count);

    //count = 100;

    printf("Enter the Upper limit ");
    scanf ("%d", &u);
    printf("Enter the Lower limit ");
    scanf ("%d", &l);


    t= clock();

    for (i = 0; i < count; i++) {
      int random = (rand() % (u-l + 1))+l;
      printf("%d ", random);
      fprintf(ft , "%d ",random );
   }

   fclose(ft);

    ft = fopen("text.txt", "r");

   i = 0;
   while (i<count)
    {
        fscanf (ft , "%d", &m);
        a[i] = m ;
        i++;
    }


    for (int i = 0; i<count; i++)
    {
        for (int j = 0; j< count-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("\n\n");
    printf("sorted array : ");
    f = fopen("copy.txt", "w");
    for (int j = 0; j< count; j++)
    {

        printf("%d ", a[j]);
        fprintf(f , "%d", a[j]);
    }

     t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\n");
    printf("The Sorting took %f seconds to Execute \n", time_taken);

}

// Write a C code to read a number for the file and the number of elements is taken as the 1st number


#include <stdio.h>

int main ()
{
    FILE * ft ;
    ft = fopen ("text.txt" , "r");

    int a[1000], i=0;
    int n ,m, t ;

    fscanf (ft, "%d", &n);


    while (i<7)
    {
        fscanf (ft , "%d", &m);
        a[i] = m ;
        i++;
    }


    for (int i = 0 ; i<n ; i++)
    {
        for (int j = 0 ; j< n-i-1 ; j++)
        {
            if(a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1 ] = t;
            }
        }
    }

    printf("\n");
    for (int j = 0 ; j< n; j++)
    {

        printf("%d ", a[j]);
    }

}

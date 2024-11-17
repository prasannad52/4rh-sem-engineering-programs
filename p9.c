#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void bubblesort(int n,int a[100000])
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void selectionsort(int n,int a[100000])
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            min = j;
        }
    }
    temp = a[min];
    a[min] = a[i];
    a[i] = temp;
}
void main()
{
    int n,a[100000],i,choice;
    clock_t st,et;
    float ts;
    printf("enter number of elements in array\n");
    scanf("%d",&n);
    printf("generate random numbers\n");
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        printf("%d\t",a[i]);
    }
    printf("\nenter your choice for 1.bubble sort 2.selection sort\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        st=clock();
        bubblesort(n,a);
        et=clock();
        ts = (et-st)/CLOCKS_PER_SEC;
        printf("sorted array elements are\n");
        for(i=0;i<n;i++)
        printf("%d\t",a[i]);
        printf("total time taken is %f\n",ts);
    }
    else
    {
        st=clock();
        selectionsort(n,a);
        et=clock();
        printf("sorted array elements are\n");
        for(i=0;i<n;i++)
        printf("%d\t",a[i]);
        printf("total time taken is %f\n",ts);
    }
}
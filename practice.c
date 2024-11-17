#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
void selection(int a[100000],int n)
{
    int i,j,temp,pos;
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[pos])
            {
                pos=j;
            }
        }
        temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
    }
}
void main()
{
    int n,i,a[100000];
    float ts;
    clock_t st,et;
    printf("enter number of elements \n");
    scanf("%d",&n);
    printf("generate random numbers\n");
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        printf("%d\t",a[i]);
    }
    st=clock();
    selection(a,n);
    et=clock();
    ts=(et-st)/CLOCKS_PER_SEC;
    printf("sorted array elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf(" time complexity %f",ts);
}
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int partition(int a[100000],int low,int high)
{
    int i,j,key,temp;
    i=low;
    j=high;
    key=a[low];
    while(i<=j)
    {
        if(a[i]<=key)
        i++;
        if(a[j]>key)
        j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void quicksort(int a[100000],int low,int high)
{
    int k;
    if(low>=high)
    return;
    k=partition(a,low,high);
    quicksort(a,low,k-1);
    quicksort(a,k+1,high);
}
void main()
{
    int n,i,a[100000];
    clock_t et,st;
    float ts;
    printf("enter number of elments in array\n");
    scanf("%d",&n);
    printf("generate random numbers\n");
    for(i=1;i<=n;i++)
    {
        a[i]=rand();
        printf("%d\t",a[i]);
    }
    st=clock();
    quicksort(a,1,n);
    et=clock();
    ts=(et-st)/CLOCKS_PER_SEC;
    printf("sorted array element are\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("time taken is %f\n",ts);

}
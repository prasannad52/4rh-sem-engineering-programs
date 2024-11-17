#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[100000],int low,int high)
{
    int key,temp,i,j;
    i=low;
    j=high;
    key = a[low];
    while(i<=j){
    while(key>=a[i])
    i++;
    while(key<a[j])
    j--;
    if(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    }
    temp = a[low];
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
    int n,a[100000],i;
    clock_t st,et;
    float ts;
    printf("enter number of elements in array\n");
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
    ts = (et-st)/CLOCKS_PER_SEC;
    printf("sorted array elements are\n");
    for(i=1;i<=n;i++)
    printf("%d\t",a[i]);
    printf("total time taken is %f\n",ts);
}
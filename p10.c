#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[100000],int low,int mid,int high)
{
    int i,j,k,t[100000];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j]){
        t[k]=a[i];
        i++;
        k++;
        }
        else
        {
            t[k]=a[j];
            k++;
            j++;   
        }
    }
    while(i<=mid)
    {
        t[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        t[k]=a[j];
        k++;
        j++; 
    }
    for(i=low;i<=high;i++)
    {
        a[i]=t[i];
    }
}
void mergesort(int a[100000],int low,int high)
{
    int mid;
    if(low>=high)
    return;
    mid = (low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}
void main()
{
    int n,a[100000],i,choice;
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
    mergesort(a,1,n);
    et=clock();
    ts = (et-st)/CLOCKS_PER_SEC;
    printf("sorted array elements are\n");
    for(i=1;i<=n;i++)
    printf("%d\t",a[i]);
    printf("total time taken is %f\n",ts);
}
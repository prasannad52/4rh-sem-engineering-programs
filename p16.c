#include<stdio.h>
#include<conio.h>
int count=0;
void subsetsum(int n,int a[10],int d)
{
    int k,i,j,x[10],sum;
    for(i=1;i<=n;i++)
    {
        x[i]=0;
    }
    sum = 0;
    k=1;
    x[k]=1;
    while(1)
    {
        if(k<=n)
        {
            if(sum+a[k]==d)
            {
                printf("solution exist and %d solution is\n",count);
                count=count+1;
                for(i=1;i<=n;i++)
                {
                    if(x[i]==1)
                    {
                        printf("%d\t",a[i]);
                    }
                }
                x[k]=0;
                k=k+1;
                x[k]=1;
            }
            else if(sum+a[k]<d)
            {
                sum = sum+a[k];
                k=k+1;
                x[k]=1;
            }
            else
            {
                x[k]=0;
                k=k+1;
                x[k]=1;
            }
        }
        else
        {
            k=k-1;
            while(k!=0 && x[k]==0)
            {
                k--;
            }
            if(k==0)
            return;
            x[k]=0;
            sum = sum-a[k];
            k=k+1;
            x[k]=1;
        }
    }
}
void main()
{
    int n,a[10],i,d;
    printf("enter number of elements in array\n");
    scanf("%d",&n);
    printf("enter elements of array");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter d value\n");
    scanf("%d",&d);
    subsetsum(n,a,d);
    if(count==0)
    {
        printf("solution does not exist\n");
    }
}
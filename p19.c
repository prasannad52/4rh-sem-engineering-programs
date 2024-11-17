#include<stdio.h>
#include<stdlib.h>
int place(int x[10],int k)
{
    int i;
    for(i=1;i<k;i++)
    {
        if(x[k]==x[i] || abs(x[k]-x[i])==abs(i-k))
        {
            return 0;
        }
    }
    return 1;
}
void main()
{
    int i,n,k,count,x[10];
    printf("enter no of queens\n");
    scanf("%d",&n);
    count = 0;
    k=1;
    x[k]= 0;
    while(k!=0)
    {
        x[k]=x[k]+1;
        while(x[k]<=n && !place(x,k))
        {
            x[k]=x[k]+1;
        }
        if(x[k]<=n)
        {
            if(k==n)
            {
                count+=1;
                printf("solution exist: %d\n",count);
                for(i=1;i<=n;i++)
                {
                    printf("%d\t",x[i]);
                }
            }
            else
            {
                k=k+1;
                x[k]=0;
            }
        }
        else
        {
            k=k-1;
        }
    }
    if(count==0)
    {
        printf("no solution exist\n");
    }
}
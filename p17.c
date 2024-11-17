#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int place(int x[10],int k)
{
    int i;
    for(i=1;i<k;i++)
    {
        if(x[i]==x[k] || abs(x[i]-x[k])==abs(k-i))
        return 0;
    }
    return 1;
}
void nqueen(int n)
{
    int k,x[10],count,i;
    count=0;
    k=1;
    x[k]=0;
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
                printf("all queens are placed\n");
                for(i=1;i<=n;i++)
                printf("%d\t",x[i]);
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

}
void main()
{
    int n;
    printf("enter number of queens\n");
    scanf("%d",&n);
    nqueen(n);
}
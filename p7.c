#include<stdio.h>
#include<conio.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    else 
    return b;
}
void knapsack(int n,int w[],int p[],int m)
{
    int v[20][20],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            v[i][j] = 0;
            else if(w[i]<=j)
            v[i][j] = max(v[i-1][j],(v[i-1][j-w[i]]+p[i]));
            else 
            v[i][j] = v[i-1][j];
        }
    }
    printf("optimal solution is %d\n",v[n][m]);
}
void main()
{
    int i,n,w[10],p[10],m;
    printf("Enter number of items\n");
    scanf("%d",&n);
    printf("Enter weight of each item\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("Enter profit of each item\n");
    for(i=1;i<=n;i++)
    scanf("%d",&p[i]);
    printf("Enter the capacity of knapscack\n");
    scanf("%d",&m);
    knapsack(n,w,p,m);
}
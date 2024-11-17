#include<stdio.h>
#include<conio.h>
int min(int a,int b)
{
    if(a<b)
    return a;
    else 
    return b;
}
void flyods(int n,int a[10][10])
{
    int p[10][10],i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            p[i][j]=a[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                p[i][j] = min(p[i][j],p[i][k]+p[k][j]);
            }
        }
    }
    printf("path matrix is\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    int n,a[10][10],i,j;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter cost adjecency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    flyods(n,a);
}
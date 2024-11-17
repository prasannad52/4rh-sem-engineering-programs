#include<stdio.h>
#include<conio.h>
void warshals(int n,int a[10][10])
{
    int i,j,k,p[10][10];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            p[i][j] = a[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(p[i][j]==0)
                {
                    if(p[i][k]==1 && p[k][j]==1)
                    {
                        p[i][j]=1;
                    }
                }
            }
        }
    }
    printf("transitive closure is \n");
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
    printf("enter number of vertices\n");
    scanf("%d",&n);
    printf("enter adjecency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    warshals(n,a);
}

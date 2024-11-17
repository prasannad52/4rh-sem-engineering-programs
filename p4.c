#include<stdio.h>
#include<conio.h>
void warshals(int n,int p[50][50])
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
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
    printf("path matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++){
        printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    int i,n,j,p[50][50];
    printf("enter number of vertices\n");
    scanf("%d",&n);
    printf("eneter adjecency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&p[i][j]);
        }
    }
    warshals(n,p);
}
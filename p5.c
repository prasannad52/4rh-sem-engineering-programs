#include<stdio.h>
#include<conio.h>
int min(int a,int b)
{
    if(a<b)
    return a;
    return b;

}
void flyods(int n,int p[50][50])
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
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
    flyods(n,p);
}
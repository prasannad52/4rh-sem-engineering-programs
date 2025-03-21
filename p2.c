#include<stdio.h>
#include<conio.h>
void prims(int n,int cost[50][50],int source)
{
    int i,vis[100],d[100],p[100],sum,k,mincost,j,u,t[100][100],v;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        d[i]=cost[source][i];
        p[i]=source;
    }
    vis[source]=1;
    sum=0;
    k=1;
    for(i=1;i<=n-1;i++)
    {
        mincost=999;
        u=0;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0 && d[j]<mincost)
            {
                mincost=d[j];
                u=j;
            }
        }
        vis[u]=1;
        t[k][1]=u;
        t[k][2]=p[u];
        k++;
        sum=sum+cost[u][p[u]];
        for(v=1;v<=n;v++)
        {
            if(vis[v]==0&&cost[u][v]<d[v])
            {
                d[v]=cost[u][v];
                p[v]=u;
            }
        }

    }
    if(sum>=999)
    {
        printf("spanning tree not exist\n");
    }
    printf("spanning tree exist\n");
    for(i=1;i<=n-1;i++)
    {
        printf(" %d <- %d \n",t[i][1],t[i][2]);
    }
    printf("total cost is %d\n",sum);
}
void main()
{
    int n,cost[50][50],i,j,source,mincost;
    printf("enter number of vertices\n");
    scanf("%d",&n);
    printf("enter the cost adjecency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    mincost=999;
    source=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]!=0&&cost[i][j]<mincost)
            {
                mincost=cost[i][j];
                source=i;
            }
        }
    }
    prims(n,cost,source);
}
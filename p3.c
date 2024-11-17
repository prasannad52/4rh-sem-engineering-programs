#include<stdio.h>
#include<conio.h>
void dijkstra(int n,int cost[50][50],int source)
{
    int i,vis[100],d[100],p[100],sum,k,mincost,j,u,t[100][100],v;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        d[i]=cost[source][i];
        p[i]=source;
    }
    vis[source]=1;
    for(i=1;i<=n-1;i++)
    {
        mincost=999;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0 && d[j]<mincost)
            {
                mincost=d[j];
                u=j;
            }
        }
        vis[u]=1;
        for(v=1;v<=n;v++)
        {
            if(vis[v]==0&&d[u]+cost[u][v]<d[v])
            {
                d[v]=d[u]+cost[u][v];
                p[v]=u;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        j=i;
        while(j!=source)
        {
            printf("%d<-",j);
            j=p[j];
        }
        printf("%d",j);
        printf("::cost is %d\n",d[i]);
    }
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
    printf("enter source vertex\n");
    scanf("%d",&source);
    dijkstra(n,cost,source);
}
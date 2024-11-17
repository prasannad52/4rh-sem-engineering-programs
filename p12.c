#include<stdio.h>
#include<conio.h>
void dijkstra(int n,int cost[10][10],int source)
{
    int i,j,vis[10],d[10],p[10],u,mincost,v;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        d[i]=cost[source][i];
        p[i]=source;
    }
    vis[source]=1;
    for(i=1;i<=n-1;i++)
    {
        mincost = 999;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0 && d[j]<mincost){
            mincost = d[j];
            u = j;}
        }
    vis[u]=1;
    for(v=1;v<=n;v++)
    {
        if(vis[v]==0 && cost[u][v]+d[u]<d[v])
        {
            d[v]=cost[u][v]+d[u];
            p[v]=u;
        }
    }
    }
    printf("singles source shortest path\n");
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
    int source,n,cost[10][10],i,j;
    printf("enter number of vertices\n");
    scanf("%d",&n);
    printf("enter cost matrix\n");
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
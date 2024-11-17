#include<stdio.h>
#include<conio.h>
int find(int v,int p[10])
{
    while(p[v]!=v)
    {
        v=p[v];
    }
    return v;
}
void kruskal(int n,int cost[10][10])
{
    int count,i,j,k,p[10],u,v,vis[10],d[10],mincost,t[10][10],sum;
    sum=0;
    k=1;
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
    count=0;
    while(count<=n-1)
    {
        mincost=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<mincost)
                {
                    mincost=cost[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        if(mincost>=999)
        break;
        i=find(u,p);
        j=find(v,p);
        if(i!=j)
        {
            t[k][1]=u;
            t[k][2]=v;
            k++;
            count++;
            sum=sum+mincost;
            p[j]=i;
            p[i]=i;
        }
        cost[u][v]=cost[v][u]=999;
    }
    if(count==n-1)
    {
        printf("tree exist\n");
        for(i=1;i<=n-1;i++)
        {
            printf("%d->%d\n",t[i][1],t[i][2]);
        }
        printf("total cost %d\n",sum);
    }
    else
    printf("tree not exist\n");
}
void main()
{
    int n,cost[10][10],j,i;
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
    kruskal(n,cost);
}
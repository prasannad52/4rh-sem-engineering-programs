#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selection_sort(int a[10000], int n)
{
    int i, j, pos, temp;
    for (i=0; i<=n-2; i++)
    {
        pos = i;
        for(j=i+1; j<=n-1; j++)
        {
            if(a[j]<a[pos])
            {
                pos=j;
            }
        }
        temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
    }

}
void main()
{
    int i, n, a[10000];
    clock_t start, end;
    float d_time;
    scanf("%d", &n);
    printf("the randomly generated elements are \n");
    for(i=1; i<=n; i++)
    {
        a[i]=rand()%150;
        printf("%d\t", a[i]);
    }
    start=clock();
    selection_sort(a, n);
    end=clock();
    d_time=(end-start)/CLOCKS_PER_SEC;
    printf("the array after sorting is : ");
    for(i=1; i<=n; i++)
    {
        printf("%d", a[i]);
    }
    printf("the total time taken is %f", d_time);
}
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void main()
{
    int i,j,n=6;
    int id[]={1,2,3,4,5,6};
    int profit[]={200,180,190,300,120,100};
    int deadline[]={5,3,3,2,4,2};
    for(i=0;i<=n-2;i++)
    {
        for(j=0;j<=n-2;j++)
        {
            if(profit[j]<profit[j+1])
            {
                swap(&id[j],&id[j+1]);

                swap(&profit[j],&profit[j+1]);

                swap(&deadline[j],&deadline[j+1]);
            }
        }
    }
    int solution[5]={0},totprofit=0;
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>=0;j--)
        {
            if(solution[j]==0 && deadline[i]>=j+1)
            {
                solution[j]=id[i];
                totprofit+=profit[i];
                break;
            }
        }
    }
    printf("Solution: \n");
    for (i = 0; i < 5; i++)
    {
        printf("%d -> %d \n",i, solution[i]);
    }
    printf("\nprofit is:%d",totprofit);

}
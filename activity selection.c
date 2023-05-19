#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void actsel(int s[],int f[],int a[],int n)
{
    int i,j;
    printf("Final soln :");
    i=0;
    for(j=1;j<=n;j++)
    {
        if(s[j]>=f[i])
        {
            printf("A%d  ",a[j]);
            i=j;
        }
    }
}

int main()
{
    int i,j,n,a[10],s[10],f[10];
    printf("No of activities : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the name of the activity : ");
        scanf("%d",&a[i]);
        printf("Enter the start time of the activity : ");
        scanf("%d",&s[i]);
        printf("Enter the finish of the activity : ");
        scanf("%d",&f[i]);
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(f[j]>f[j+1])
            {
                swap(&a[j],&a[j+1]);
                swap(&f[j],&f[j+1]);
                swap(&s[j],&s[j+1]);
            }
        }
    }
    actsel(s,f,a,n);
    return 0;
}
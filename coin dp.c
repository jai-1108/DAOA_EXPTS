#include<stdio.h>
#include<limits.h>
#define N 3
#define SUM 8
int min(int a, int b){return a < b ? a : b;}

void findCoins(int coins[], int dp[][SUM+1]){
    int i = N, j= SUM, count = 0;
    while(j>0){
        if (dp[i][j] == dp[i-1][j]){
            i--;
        }
        else{
            coins[count++] = i;
            j = j - i;
        }
    }
}
int main(){
    int denominations[N] = {1,4,6};
    int dp[N+1][SUM+1], coins[SUM], count = 0;
    for (int i = 0; i <=N ; i++){
        for(int j = 0; j <= SUM; j++){
            if(j == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = INT_MAX;
            }
        }
    }
    for(int i = 1; i <=N; i++){
        for(int j = 1; j <= SUM; j++){
            if (j < denominations[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - denominations[i-1]]); 
            }
        }
    }
    printf("Number of coins required are: %d \n", dp[N][SUM]);
    findCoins(coins, dp);
    printf("actual denominations needed: ");
    for(int i = 0; i< dp[N][SUM]; i++){
        printf("%d ", denominations[coins[i] - 1]);
    }
    return 0;
}
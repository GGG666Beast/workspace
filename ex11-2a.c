#include<stdio.h>
#include<stdlib.h>
#define INF 99999
void main(){

    int *power,*cost,*used,**dp;
    int max,i,j,k,n,temp,min,flag,sum=0;

printf("Input number of  types of card:\n");
scanf("%d",&n);

power=(int *)malloc(sizeof(int)*(n+1));
cost=(int *)malloc(sizeof(int)*(n+1));
used=(int *)malloc(sizeof(int)*(n+1));

for(i=0;i<=n;i++) used[i]=0;

printf("Input power and cost of cards:\n");
power[0]=0;
cost[0]=0;

for(i=1;i<=n;i++) {
    scanf("%d",&power[i]);
    scanf("%d",&cost[i]);
}
min=INF;

for(i=1;i<=n;i++){
    for(j=i;j<=n;j++){
        if(power[j]<min){
            min=power[j];
            flag=j;
        }
    }
    temp=power[i];
    power[i]=power[flag];
    power[flag]=temp;

    temp=cost[i];
    cost[i]=cost[flag];
    cost[flag]=temp;
    min=INF;
}

printf("Input maximum cost\n->");
scanf("%d",&max);
dp=(int **)malloc(sizeof(int *)*(max+1));
for(i=0;i<=max;i++) dp[i]=(int *)malloc(sizeof(int)*(n+1));


for(i=0;i<=max;i++) dp[i][0]=0;
for(i=0;i<=n;i++) dp[0][i]=0;


for(i=1;i<=max;i++){
    for(j=1;j<=n;j++){
        if(cost[j]<=i){
            if(dp[i][j-1]<dp[i-cost[j]][j-1]+power[j]) dp[i][j]=dp[i-cost[j]][j-1]+power[j];
            else dp[i][j]=dp[i][j-1];
        }
        else dp[i][j]=dp[i][j-1];
    }
}
for(i=0;i<=max;i++){
    for(j=0;j<=n;j++){
        printf("%d ",dp[i][j]);
    }
    printf("\n");


/*     for(j=n;j>1;j--){
        for(i=max;i>1;i--){
    if(dp[i][j]>dp[i-1][j] && power[j] == dp[i][j]-dp[i-1][j]) {
        j--;
        printf("Card (Power:%d Cost:%d) is selected\n",power[j],cost[j]);
        used[j]++;
    }
    }
    }*/
    for(j=n;j>0;j--){
            if(dp[max][j]-dp[max][j-1]==power[j]) used[j]=1;
        }
    }
}


 for(i=1;i<=n;i++){
    if(used[i]==0) printf("Card (Power:%d Cost:%d) is not selected\n",power[i],cost[i]);
    else printf("Card (Power:%d Cost:%d) is selected\n",power[i],cost[i]);
}
/* 
flag=0;
for(i=max;i>0;i--){
    for(j=n;j>0;j--){
    if(dp[i][j]>dp[i-1][j])flag=i;
    break;
    }
    if(flag!=0)break;
}
*/
printf("My besk deck has %d cards (Cost: %d, Power: %d)\n",sum,flag,dp[max][n]);
}

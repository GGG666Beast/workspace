#include<stdio.h>
#include<stdlib.h>
#define INF 99999
void main(){

    int *coin,*dp;
    int pay,i,j,n,min,flag,temp;

printf("Input number of  types of coin).\n->");
scanf("%d",&n);

coin=(int *)malloc(sizeof(int)*n);

printf("Input donation of coins).\n->");
min=INF;
for(i=0;i<n;i++) scanf("%d",&coin[i]);
for(i=0;i<n;i++){
    for(j=i;j<n;j++){
        if(min>coin[j]){
            min=coin[j];
            flag=j;
        }
        temp=coin[i];
        coin[i]=min;
        coin[flag]=temp;
        min=INF;
    }
}


printf("Input how many cents should you pay?\n->");
scanf("%d",&pay);
dp=(int *)malloc(sizeof(int)*(pay+1));

for(i=0;i<=pay;i++) dp[i]=INF;
for(i=0;i<n;i++)dp[coin[i]]=1;
dp[0]=0;

for(i=0;i<=pay;i++){
    for(j=0;j<n;j++){

        if(i+coin[n]>pay)break;
        if(dp[i+coin[j]]>dp[i]+1) dp[i+coin[j]]=dp[i]+1;
    }
}
    if(dp[pay]==INF) printf("Error: you cannot pay for this value.\n");
    else printf("Totally, you used %d coins for %d cents.\n",dp[pay],pay);

}    
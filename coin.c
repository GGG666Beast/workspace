#include<stdio.h>

void main(){

    int coin[4][2]={{25,0},{10,0},{5,0},{1,0}};
    int used[4];
    int pay,i,temp,comp=0,sum=0;

    for(i=0;i<4;i++) used[i]=0;

printf("Input numbers of each cent(coin).\n->");
for(i=0;i<4;i++) scanf("%d",&coin[i][1]);

printf("Input how many cents should you pay?\n->");
scanf("%d",&pay);
temp=pay;
/*貪欲法：金額の高い硬貨から低い方へ順番に払う金額から引いていっている */
    for(i=0;i<4;i++){
        if(comp==1)break;
        while(coin[i][1]>0){

        if(coin[i][0]<pay) {
            pay-=coin[i][0];
            coin[i][1]--;
            used[i]++;
            }
        else if(coin[i][0]>pay) break;
        else{
            used[i]++;
            comp=1;
            break;
        }
        }
    }
    if(comp==0) printf("Error: you cannot pay for this value.\n");
    else {
        for(i=0;i<4;i++) {
            printf("[%dcent] %d used.\n",coin[i][0],used[i]);
            sum+=used[i];
    }
    printf("Totally, you used %d coins for %d cents.\n",sum,temp);

    }
}
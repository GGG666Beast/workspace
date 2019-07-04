#include<stdio.h>
#include<stdlib.h>

#define INFTY 99999

    int Warshall(int,int,int);
    int Floyd(int,int,int);
    int Maggs_Plotkin(int,int,int);

    int main(){
        int i,j,k;
        int **Data,n;

        printf("Input the number of data: ");
        scanf("%d",&n);

        Data=(int **)malloc(n*sizeof(int *));
        for(i=0;i<n;i++) Data[i]=(int*)malloc(n*sizeof(int));

        printf("Input the Adjacency or Distance matrix:\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&Data[i][j]);

            }

        }

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    Data[i][j]=Warshall(Data[i][j],Data[i][k],Data[k][j]);
                    //Data[i][j]=Floyd(Data[i][j],Data[i][k],Data[k][j]);
                    //d[i][j]=Maggs_Plotkin(d[i][j],d[i][k],d[k][j]);

                }        
            }       
        }           
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",Data[i][j]);
            }
            printf("\n");
        } 

        for(i=0;i<n;i++) free(Data[i]);
            free(Data);

            return 0;  
    }

int Warshall(int A_ij,int A_ik,int A_kj){
    int Ak_ij;

    return Ak_ij;
}

int Floyd(int D_ij,int D_ik,int D_kj){
    int Dk_ij;

    //Dk_ij=/*complete*/

    return Dk_ij;
}

int Maggs_Plotkin(int D_ij,int D_ik,int D_kj){
    int Dk_ij;

    //Dk_ij=/*complete*/

    return Dk_ij;
}






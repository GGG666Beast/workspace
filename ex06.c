#include<stdio.h>
#include<stdlib.h>

#define INFTY 99999

    int Warshall(int,int,int);
    int Floyd(int,int,int);
    int Maggs_Plotkin(int,int,int);
void MST_view(int **,int **,int);


    int main(){
        int i,j,k;
        int **Data,**d,n;

        printf("Input the number of data: ");
        scanf("%d",&n);

	d=(int **)malloc(n*sizeof(int *));
        Data=(int **)malloc(n*sizeof(int *));
        for(i=0;i<n;i++){
	  Data[i]=(int*)malloc(n*sizeof(int));
	  d[i]=(int*)malloc(n*sizeof(int));
	}

        printf("Input the Adjacency or Distance matrix:\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&Data[i][j]);
		

            }

        }

	for(i=0;i<n;i++){
	  for(j=0;j<n;j++){
	    d[i][j]=Data[i][j];
	  }
	}
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
		  //Data[i][j]=Warshall(Data[i][j],Data[i][k],Data[k][j]);
		   //Data[i][j]=Floyd(Data[i][j],Data[i][k],Data[k][j]);
                    d[i][j]=Maggs_Plotkin(d[i][j],d[i][k],d[k][j]);

                }        
            }       
        }
	//int x,y,max=0;
	/* for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",Data[i][j]);
		if(Data[i][j]>max && Data[i][j]<99999){
		  max=Data[i][j];
		  x=i;
		  y=j;
		  
		}
            printf("\n");

}*/
	//printf("\n%d %d %d\n",x,y,max);
	MST_view(Data,d,n);
	    

        for(i=0;i<n;i++) {
	  free(Data[i]);
	  free(d[i]);
	}
	free(d);
            free(Data);

            return 0;  
    }

int Warshall(int A_ij,int A_ik,int A_kj){
    int Ak_ij;
    Ak_ij=A_ij | A_ik & A_kj;

    return Ak_ij;
}

int Floyd(int D_ij,int D_ik,int D_kj){
    int Dk_ij;

    if(D_ij>D_ik + D_kj) Dk_ij=D_ik+D_kj;
    else Dk_ij=D_ij;

    return Dk_ij;
}

int Maggs_Plotkin(int D_ij,int D_ik,int D_kj){
    int Dk_ij;

    if(D_ik<D_kj) D_ik=D_kj;
    if(D_ij>D_ik) D_ij=D_ik;
    Dk_ij=D_ij;

    return Dk_ij;
}





void MST_view(int **D0,int **dn,int n){
  int i,j;
  int costs=0;

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){//A上で辺があったところが、A^kの全域木に採用されているなら重みを加える
      if(D0[i][j]==dn[i][j] && D0[i][j]!=INFTY){ costs += dn[i][j];
	printf("adopted(%d,%d)  cost:%d   (Data: %d  d: %d)\n",i,j,dn[i][j],D0[i][j],dn[i][j]);
      }
    }
  }
  printf("MST total weights:%d\n",costs);
}

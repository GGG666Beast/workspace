#include <stdio.h>
#include <stdlib.h>

void FindPlace(int **,int,int,int);


int block_id=1;//置いたＬ字型ブロックを個々に識別できるように

int main(int argc,char **argv){
  int i,j,n;
  int **Board;//正方格子
  int hole_x,hole_y;//１個のブロックが最初から置かれている正方格子上の場所

  if(argc!=4){//初期化関係
    fprintf(stderr,"Error: Input arguments were incorrect.\n");
    exit(1);
  }
  hole_x = atoi(argv[1]);//１個のブロックで塞いだｘ座標
  hole_y = atoi(argv[2]);//１個のブロックで塞いだｙ座標
  n = atoi(argv[3]); //正方格子のサイズ（２のべき乗にすること）

  if(!(hole_x>=0 && hole_x<n)|| !(hole_y>=0 && hole_y<n)){
    fprintf(stderr,"Error: The coodinates of blank (%d,%d) what you input was incorrect;\nThe acceptable range is 0 to %d.\n",hole_x,hole_y,n);
    exit(2);
  }

  Board = (int **)malloc(sizeof(int *)*n);
  for(i=0;i<n;i++) Board[i] = (int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==hole_y&&j==hole_x)Board[i][j]=-1;//ブロックが最初に置かれている場所は -1 とする
      else Board[i][j] = 0; // 0 の場所にＬ字型ブロックを置いていく
    }
  }

  printf("Board_Initialization:\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%2d",Board[i][j]);
      if(j!=n-1)printf(" ");
    }
    printf("\n");
  }

  FindPlace(Board,n,hole_x,hole_y);//処理本体

  printf("Print_Answer:\n");//出力
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%2d",Board[i][j]);
      if(j!=n-1)printf(" ");
    }
    printf("\n");
  }
  for(i=0;i<n;i++) free(Board[i]);
  free(Board);
  return 0;
}


void FindPlace(int **Board,int size,int h_x,int h_y){
  /*
この関数は、再帰呼び出しになるので、Boardは各部分問題の時点での大きさ(size)となる。
既にブロックが置かれている場所はh_xとh_yで指定する
Strassen と同様、コードの配置（処理の流れ）は以下のようになるはずである
極小まで分解されたときの処理（再帰の打ち切り）⇒ 部分問題用の配列確保 ⇒ 再帰に持ち込むための準備の処理 ⇒ 再帰呼び出し
  */
int i,j; 
int **A,**B,**C,**D;

size/=2;
if(size<1) return;

A=(int **)malloc(size*sizeof(int *));
B=(int **)malloc(size*sizeof(int *));
C=(int **)malloc(size*sizeof(int *));
D=(int **)malloc(size*sizeof(int *));


for(i=0;i<size;i++) {
  A[i]=(int *)malloc(size*sizeof(int));
  B[i]=(int *)malloc(size*sizeof(int));
  C[i]=(int *)malloc(size*sizeof(int));
  D[i]=(int *)malloc(size*sizeof(int));
}
  

for(i=0;i<size;i++){
  for(j=0;j<size;j++){
    A[i][j]=0;
    B[i][j]=0;
    C[i][j]=0;
    D[i][j]=0;
  }
}

  if(h_x<size && h_y<size){
    
    Board[size][size-1]=block_id;
    Board[size-1][size]=block_id;
    Board[size][size]=block_id++;

    FindPlace(A,size,h_x,h_y);
    FindPlace(B,size,0,size-1);
    FindPlace(C,size,size-1,0);
    FindPlace(D,size,0,0);
  }
  else if(h_x>=size && h_y<size){

    Board[size-1][size-1]=block_id;
    Board[size-1][size]=block_id;
    Board[size][size]=block_id++;
    
    FindPlace(A,size,size-1,size-1);
    FindPlace(B,size,h_x-size,h_y);
    FindPlace(C,size,size-1,0);
    FindPlace(D,size,0,0);
  }
  else if(h_x<size && h_y>=size){
    Board[size-1][size-1]=block_id;
    Board[size][size-1]=block_id;
    Board[size][size]=block_id++;
    
    FindPlace(A,size,size-1,size-1);
    FindPlace(B,size,0,size-1);
    FindPlace(C,size,h_x,h_y-size);
    FindPlace(D,size,0,0);
  }
  else {
    Board[size-1][size-1]=block_id;
    Board[size][size-1]=block_id;
    Board[size-1][size]=block_id++;
    
    FindPlace(A,size,size-1,size-1);
    FindPlace(B,size,0,size-1);
    FindPlace(C,size,size-1,0);
    FindPlace(D,size,h_x-size,h_y-size);
  }
  
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      if(Board[i][j]==0) Board[i][j]=A[i][j];
      if(Board[i+size][j]==0) Board[i+size][j]=B[i][j];
      if(Board[i][j+size]==0) Board[i][j+size]=C[i][j];
      if(Board[i+size][j+size]==0) Board[i+size][j+size]=D[i][j];
      
    }
  }
  for(i=0;i<size;i++){
    free(A[i]);
    free(B[i]);
    free(C[i]);
    free(D[i]);
  }
  
  free(A);
  free(B);
  free(C);
  free(D);
 
  return;
}

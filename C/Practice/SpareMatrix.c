#include<stdio.h
struct Element {
  int row, col , value;
};
void TransposeMatrix(Element mat[], int n , int transposeMatrix[]){
  for(int i =1;i<=n;i++){
    transposeMatrix[i].row = mat[i].col;
    transposeMatrix[i].col = mat[i].row;
    transposeMatrix[i].value = mat[i].value;
    for(int i = 1;i<=n;i++){
      for(int j =i+1;j<=n;j++){
        if(transposeMatrix[i].row>transposeMatrix[j].col && transposeMatrix[i].col > transposeMatrix[j].col && transposeMatrix[i].row == transposeMatrix[j].col){
          Element temp = transposeMatrix[i];
          transposeMatrix[i] = transposeMatrix[j];
          transposeMatrix[j] = temp;
        } 
      }
    }
  }
}
void PrintSpareMatrix(Element mat[], int n){
  printf("Row Col value \n");
  for(int i =0;i<=n;i++){
printf("%d %d %d",mat[i].row , mat[i].col , mat[i].value);
  }
}
int main(){
  int rows , col , nonZero;
  printf("Enter value of rows Col NonZero :");
  for(int i = 0;i<=n;i++){
    scanf("%d %d %d", &rows,&col,&nonZero);
  }
  Element mat[NonZero + 1],transpoded[NonZero +1];
  mat.row[0]=rows;
  mat.col[0] =col;
  mat.value[0] = nonZero;
  printf("Enter non Zero Elements : ")
    for(int i=1;i<=nonZero;i++){
    scanf("%d %d %d",&mat[i].row,&mat[i].col,&mat[i].value);
  }
transposeMatrix(mat,nonZero,transpoded);
  printf("Beofre")
    PrintSpareMatrix(mat,nonZero);
  PrintSpareMatrix(transpoded,nonZero);
}

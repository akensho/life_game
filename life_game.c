#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char **initMatrix(int n, int m){
  char **matrix;
  matrix = malloc(sizeof(char *) * n);
  for(int i = 0; i < n; i++){
    matrix[i] = malloc(sizeof(char) * m);
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      matrix[i][j] = '?';
    }
  }
  return matrix;
}

void printMatrix(char **matrix, int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      printf("%c ", matrix[i][j]);
    }
    printf("\n");
  }
}

void freeMatrix(char **matrix, int n){
  for(int i = 0; i < n; i++){
    free(matrix[i]);
  }
}

int main(int argc, char *argv[]){
  if( argc != 3 ){
    printf("Error: => 'ex_command' 'row' 'column'\n");
    exit(1);
  }
  const int N = atoi(argv[1]);
  const int M = atoi(argv[2]);
  char **matrix = initMatrix(N, M);
  printMatrix(matrix, N, M);
  freeMatrix(matrix, N);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char **initMatrix(int n, int m){
  char **matrix;
  srand(1234);
  matrix = malloc(sizeof(char *) * n);
  for(int i = 0; i < n; i++){
    matrix[i] = malloc(sizeof(char) * m);
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if( rand() % 2 == 0 ){
	matrix[i][j] = '*';
      }else{
	matrix[i][j] = '?';
      }
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

int countSurvivors(char **matrix, int n, int m, int x, int y){
  int res = 0;
  int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
  int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
  for(int index = 0; index < 8; index++){
    int next_x = x + dx[ index ];
    int next_y = y + dy[ index ];
    if( 0 <= next_y && next_y < n && 0 <= next_x && next_x < m ){
      if( matrix[next_y][next_x] == '*' ) res++;
    }
  }
  return res;
}

void changeNextSituation(char **matrix, int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int survivors = countSurvivors(matrix, n, m, j, i);
      if( matrix[i][j] == '*' ){
	if( survivors <= 1 || survivors >= 4 ){
	  matrix[i][j] = '?';
	}
      }else{
	if( survivors == 3 ){
	  matrix[i][j] = '*';
	}
      }
    }
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
  while( true ) {
    changeNextSituation(matrix, N, M);
    printMatrix(matrix, N, M);
  }
  freeMatrix(matrix, N);
  return 0;
}

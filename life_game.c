#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool *initField(int n, int m){
  bool *field;
  field = malloc(sizeof(bool) * n * m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      field[i * m + j] = false;
    }
  }
  return field;
}

void prinfField(){

}


int main(int argc, char *argv[]){
  if( argc != 3 ){
    printf("Error: => 'ex_command' 'row' 'column'/n");
    exit(1);
  }
  const int N = atoi(argv[1]);
  const int M = atoi(argv[2]);
  bool *field = initField(N, M);
  return 0;
}

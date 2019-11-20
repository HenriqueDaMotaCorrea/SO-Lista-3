#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>

int seconds(){
  int t = arc4random_uniform(15) + 5;
  return t;
}

int main(){

  return 0;
}
// Lista 3 - Ex 1
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

int segundos(){
  return (rand() % 16) + 5;
}

int inputN(){
  int n = 0;
  printf("Número de threads: ");
  scanf("%d", &n);
  return n;
}

void *rotinaThread(){
  int t = segundos();
  printf("Vai dormir por %d segundos\n", t);
  sleep(t);
  printf("Bom dia mundo cruel!");
  return NULL;
}

int main(void) {
  pthread_t thID;
  int numThreads = inputN();
  printf("Criando %d threads...\n", numThreads);
  pthread_create(&thID, NULL, (void*)rotinaThread(), NULL);
  printf("Nova thread criada: %ld\n", thID);
  pthread_join(thID, NULL);
  printf("Todas as threads terminaram\n");
  return 0;
}
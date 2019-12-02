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
  printf("\n>> Número de threads: ");
  scanf("%d", &n);
  return n;
}

void *rotinaThread(){
  int t = segundos();
  printf("Vai dormir por %d segundos\n", t);
  sleep(t);
  printf("\nBom dia mundo cruel!\n");
  return NULL;
}

int main(void) {
  int numThreads = inputN();
  printf("\n>> Criando %d threads...\n", numThreads);
  
  for(int i = 0; i < numThreads; i++){
    pthread_t thID;
    pthread_create(&thID, NULL, (void*)rotinaThread, NULL);
    printf("\n>> Nova thread criada: %ld\n", thID);
    pthread_join(thID, NULL);
  }
  printf("\n>> Todas as threads terminaram\n");
  return 0;
}
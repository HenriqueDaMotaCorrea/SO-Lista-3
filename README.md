# SO-Lista-3

## UFCSPA – Informática Biomédica
## Sistemas Operacionais – 19/02 – Prof. João Gluz
### Lista de Exercícios 3 – Exercícios sobre Threads

### Grupo: Fabrício Vizzotto | Gabriel Burgos | Henrique Corrêa | Luiza Pinheiro

**(1)** Desenvolva um programa que cria n threads, onde n é um número informado pelo usuário.
Após obter o valor n do usuário o programa principal imprime uma mensagem que irá criar n
threads e então cria as threads. Cada uma das threads criadas seleciona uma quantidade aleatória t
de segundos, t entre 5 e 20 segundos, imprime uma mensagem que irá dormir por t segundos, dorme
(sleep()) por esse tempo, depois imprime uma mensagem que já acordou e encerra a thread. O
programa principal (que agora é a thread principal) espera por todas as threads criadas se
encerrarem usando a função join(). Depois ele imprime uma mensagem que isso ocorreu e encerra
sua execução.

**(2)** Implemente o programa (3) da lista de exercícios 2 usando threads. Note que para controle de
acesso da memória compartilhada entre as threads, que agora simplesmente é a memória do
processo que iniciou as threads, pode-se utilizar os mutexes.

```
(3) O programa da questão (1) faz a comunicação entre os dois processos apenas uma vez por meio
da memória compartilhada. Para que as operações de leitura e conversão de texto executadas pelos
dois processos deste programa possam ser repetidas é necessário que o acesso à memória
compartilhada seja mutuamente exclusivo, ou seja, quando um processo está gravando informações
na memória compartilhada o outro processo não pode alterar ou até ler a memória compartilhada
para que não ocorram inconsistências. Assim, para permitir a repetição das operações de leitura e
conversão de texto implemente um mecanismo baseado em semáforos que garanta o acesso
mutuamente exclusivo da memória compartilhada. O programa segue em execução até o usuário
digitar uma linha vazia que não tem nenhum texto.

(1) O programa consiste em criar uma área de memória compartilhada que será utilizada por dois
processos. Um dos processos lê do teclado um texto (string) e a opção de conversão maiúscula
(uppercase) ou minúscula (lowercase), e envia ao outro processo através da memória compartilhada
essas duas informações. A memória compartilhada armazena o texto a ser convertido e a opção de
conversão e a indicação de que há um novo texto a ser convertido. O outro processo, uma vez que
detecte que há um novo texto a ser convertido na memória compartilhada, faz conversão desejada
diretamente na mesma área de memória compartilhada. Quando este processo termina a conversão
ele indica, também por uma variável na área de memória compartilhada, que o processo de
conversão terminou. O primeiro processo ao detectar que isso ocorreu, imprime o texto convertido
na tela. O programa somente faz uma leitura e conversão de texto, ou seja, após cada processo
encerrar suas tarefas ele encerra a execução. 
```

**(3)** Faça um sistema de atendimento de solicitações de criação de threads pelo usuário composto de
dois programas distintos: um programa de interface de usuário e um programa servidor que executa
as solicitações. O programa de interface de usuário oferece opções de entrada onde o usuário
fornece as seguintes informações: o nome da nova thread, quanto tempo essa thread vai rodar
(quantos segundos) e que mensagens devem ser impressas no início e no fim da execução da thread.
Quando o usuário finaliza a entrada dessas informações elas são repassadas ao programa executor
por meio de pipes ou de filas de mensagens (escolha uma das duas opções).
O programa executor recebe essas informações e cria uma nova thread passando no argumento de
entrada da thread um apontador para uma struct que contém as informações de como a thread
deverá proceder. Logo após criar a thread o programa executor envia uma resposta ao programa de
interface de usuário (também por pipe ou fila de mensagens) avisando que a thread foi criada (ou
informando que houve algum problema, se isso ocorrer). Depois disso o programa executor volta a
esperar novas solicitações do programa de interface de usuário. O programa de interface de usuário
espera pela resposta do programa executor, escreve essa mensagem na tela e depois volta a esperar
novas solicitações do usuário.
Cada nova thread criada pelo programa executor deve primeiro imprimir: seu nome, a mensagem
inicial definida pelo usuário e o número de segundos que irá dormir no terminal onde o executor
está rodando. Depois essa thread dorme pelo número de segundo definido pelo usuário. Ao final
desse tempo essa thread imprime a mensagem final definida pelo usuário e encerra sua execução.

## PROJETO DE ESTRUTURA DE DADOS - GERENCIAMENTO DE SALAS

### Descrição do Projeto:

Esse projeto consiste em um sistema de gerenciamento de alocação de turmas em salas de um colégio realizado em linguagem C++. O qual assume os parâmetros horário de início, fim e número de alunos como fatores para analisar possíveis conflitos de horários e alocação de todos os estudantes. 

O coração do projeto está presente nas seguintes classes já definidas pelo professor:
* `ReservationRequest.hpp` que recebe os argumentos para criação de disciplinas com os horários, número de alunos e realização da reserva. Essa eu não achei necessário a implementação de novos métodos.

* `ReservationSystem.hpp` que gerencia todo o sistema de alocação. Nela, foi implementada a estrutura auxiliar (`struct`) chamada `ReservationRegistro` para atuar na lista encadeada e facilitar a criação e organização das disciplinas na memória.

### Divisão dos arquivos na pasta do projeto:
* `ReservationRequest.hpp` Armazena toda estrutura da classe ReservationRequest.

* `ReservationRequest.cpp` Armazena todos os métodos que a classe ReservationRequest possui.

* `ReservationSystem.hpp` Armazena toda estrutura da classe ReservationSystem.

* `ReservationSystem.cpp` Armazena todos os métodos que a classe ReservationSystem possui.
* `main.cpp` Executa o driver code

### Instruções de Compilação

Para compilar o código, no arquivo `main.cpp` dentro da pasta com todos os outrs arquivos, eu realizei meus testes do código com a seguinte inclusão no cabeçalho:
```
#include <iostream>
#include "ReservationSystem.hpp"
using namespace std;

```
* ##### obs: Não usei o #include "ReservationRequest.hpp" pois o proprio ReservationSystem já realiza essa função.

 Para que o código fosse compilado, utilizei a própria referência do professor no terminal do `main.cpp` :
```
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system
```
* ##### g++ : Compildor padrão de C++ .
* ##### main.cpp : Arquivo que cria todas as disciplinas e roda os testes.
* ##### ReservationSystem.cpp ReservationRequest.cpp : Arquivos que guardam toda a lógica do sistema .
* ##### -o : Sinalizador do sistema (output).
* ##### reservation_system : É o arquivo executável que nasce após todo o processo, pronto para executar todo o programa main.cpp. 

## Instrução de Execução

 Por fim, para imprimir os resultados, utilze o seguinte comando no terminal:

`WINDOWS`
```
.\reservation_system.exe
```

`LINUX / MAC`
```
./reservation_system
```

## Organização Interna dos Dados (Alocação de Memória)

Para reduzir o gasto de memória do computador, a organização interna une matrizes bidimensionais e listas encadeadas para alocação de cada disciplina.

Funcionamento da alocação:

1. **A Matriz Base:** Recebe as salas e os dias, colocados nas linhas e colunas respectivmente.  `ReservationRegistro*** registro` atua como uma espécie de ponteiro que organiza cada índice da matriz para encontrar as reservas.


2. **Os Ponteiros Cabeça:** Dentro de cada célula dessa matriz, não guardamos uma aula inteira, mas sim o indicador que aponta para o endereço de memória da primeira aula daquele dia em específico. Isso é feito para padronizar o incício na hora de buscar cada aula dentro dos registros e verificar todas as condições de disponibilidade.

3. **As Listas Encadeadas:**
   As reservas reais são representadas pela `struct ReservationRegistro`. Elas funcionam como os nós de uma Lista Encadeada Simples. Cada nó guarda os dados da disciplina (nome, horários, número de alunos) e possui um ponteiro "next" que aponta para a próxima aula daquele mesmo dia.


Essa abordagem ajuda que a memória só seja gasta quando uma reserva é efetivamente criada, gasto desnecessário de espaço.

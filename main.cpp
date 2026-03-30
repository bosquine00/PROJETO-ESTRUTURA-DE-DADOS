#include <iostream>
#include "ReservationSystem.hpp"
using namespace std;


int main(){

    // configuração do sistema e salas
    int capacidades[] = {50,30,40};
    ReservationSystem sistema(3, capacidades);

    // configuração e definição das aulas a serem arranjadas
    ReservationRequest reserva1("Probabilidade", "segunda", 11, 13, 45);
    ReservationRequest reserva2("Estrutura de Dados", "segunda", 7, 9, 45);
    ReservationRequest reserva3("TACD", "quarta", 9, 11, 25);
    ReservationRequest reserva_err("Sociologia", "quarta", 10, 11, 70);

    // reservas que dão certo
    cout << "\n RESERVAS CONFIRMADAS \n";
    sistema.reserve(reserva1);  //reservando probabilidade
    sistema.reserve(reserva2);  //reservando Estrutura de Dados
    sistema.reserve(reserva3);  //reservando TACD

    // reserva com erro
    cout << "\n TENTANDO RESERVAR SOCIOLOGIA (70 alunos)\n";
    if (sistema.reserve(reserva_err)) {
        cout << "AULA MARCADA.\n";
    } else {
        cout << "ERRO NA RESERVA\n";
    }

    cout << "\n ORGANIZAÇÃO DOS HORÁRIOS \n";
    sistema.printSchedule();

    // cancelar uma matéria
    cout << "\n CANCELANDO A AULA DE PROBABILIDADE \n";
    if (sistema.cancel("Probabilidade")) cout << "Aula cancelada"; else cout << "ERRO! Aula não encontrada";

    // mostrar que probabilidade sumiu
    cout << "\n NOVA GRADE DE AULAS(SEM PROBABILIDADE) \n";
    sistema.printSchedule();
    
    // para o destrutor executar
    return 0;
}

//para rodar usei esses comandos:
// g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system
// .\reservation_system.exe
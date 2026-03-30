#include <iostream>
using namespace std;
#include "ReservationSystem.hpp"


// CONSTRUTOR RESERVTIONSYSTEM

ReservationSystem::ReservationSystem(int room_count, int * room_capacities){
    this->room_count = room_count;

    this->room_capacities = new int[room_count];
    for (int i = 0; i < room_count; i++ ){
        this-> room_capacities[i] = room_capacities[i];
    }

    this->registro = new ReservationRegistro **[room_count];
    for(int i = 0; i < room_count; i ++){
        this->registro[i] = new ReservationRegistro*[5];
        for(int j = 0; j < 5; j++){
            this->registro[i][j] = nullptr;
        }
    }
}


// DESTRUTOR RESERVETIONSYSTEM
ReservationSystem:: ~ReservationSystem(){}



// MÉTODO DE RESERVA
bool ReservationSystem::reserve(ReservationRequest request){
    
    // preparar dados
    string dia = request.getWeekday();
    string curso = request.getCourseName();
    int alunos = request.getStudentCount();
    int inicio = request.getStartHour();
    int fim = request.getEndHour();


    int dia_indice = -1;
    if (dia == "segunda") dia_indice = 0;
    else if (dia == "terca") dia_indice = 1;
    else if (dia == "quarta") dia_indice =2;
    else if (dia == "quinta") dia_indice = 3;
    else if (dia == "sexta") dia_indice = 4;

    if (dia_indice == -1) return false;

    // buscar sala
    for (int i =0; i < room_count; i++){
        // verificar capacidade
        if(room_capacities[i] >= alunos){
            bool conflito = false;
            ReservationRegistro* atual = registro[i][dia_indice];
            while(atual != nullptr){
                if (inicio < atual->end_hour && fim > atual->start_hour){
                    conflito = true;
                    break;
                }
                atual = atual->next;
            }
            // criar e fazer a reserva
            if (conflito == false){
                ReservationRegistro*novaReserva = new ReservationRegistro(curso, inicio, fim);
                if (registro[i][dia_indice] == nullptr || registro[i][dia_indice]->start_hour >= inicio) {
                    novaReserva->next = registro[i][dia_indice];
                    registro[i][dia_indice] = novaReserva;
                } else {
                    ReservationRegistro* iter = registro[i][dia_indice];
                    while (iter->next != nullptr && iter->next->start_hour < inicio) {
                        iter = iter->next;
                    }
                    novaReserva->next = iter->next; 
                    iter->next = novaReserva;       
                }
                return true;
            }
        } 
    }
    return false;
}

//MÉTODO DE CANCELAMENTO
bool ReservationSystem:: cancel(string curso){
    //iterando salas
    for (int sala = 0; sala<room_count; sala++){
        //iterando dias da semana
        for (int dia = 0; dia<5; dia++){
            //apontadores dentro da matriz com os dados na memória, onde a iteração começa no primeiro registro e seu anterior é vazio (obviamente)
            ReservationRegistro*atual = registro[sala][dia];
            ReservationRegistro * anterior = nullptr;
            while (atual != nullptr){
                //confere se o curso é o mesmo cujo o cancelamento foi solicitado
                if (atual-> course_name == curso){
                    if(anterior == nullptr){ //caso seja o primeiro registro, caso contrário...
                        registro[sala][dia] = atual -> next;
                    }
                    else{
                        anterior->next = atual->next; //cai no else e ambos avançam até quando ambos valores baterem e o registro ser removido
                    }
                    delete atual;
                    return true;    
                }
                anterior = atual;
                atual = atual->next;   
            }
        }
    }
    return false;
} 



void ReservationSystem:: printSchedule(){
    // para "reconverter" o indice para o dia da semana específico
    string dias_semana[] = {"segunda", "terca", "quarta", "quinta", "sexta"};
    
    // iterando pelas salas
    for(int sala = 0; sala < room_count; sala++){
        cout << "\n";
        cout << "SALA" << sala + 1 << "com capacidade: " << room_capacities[sala];
        cout << "\n";
        // iterando por cada dia, com o cout mostrando cada dia que foi consultado
        for(int dia = 0; dia < 5; dia++){
            ReservationRegistro*atual = registro[sala][dia];
            cout << dias_semana[dia] << "\n";
            // while para rodar até os dias acabarem
            while(atual != nullptr) {
                cout <<atual->start_hour << "h até " << atual->end_hour << "h: " << atual->course_name;
                // passar para  próxima sala
                atual = atual->next; 
            }
            cout << "\n"; 
        }
    }
}

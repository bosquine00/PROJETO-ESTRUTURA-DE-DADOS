#pragma once
#include <iostream>
using namespace std;
#include "ReservationRequest.hpp"

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;

        struct ReservationRegistro{
        std :: string course_name;
        int start_hour;
        int end_hour;
        int student_count;
        ReservationRegistro* next;
            // construtor para encurtar os testes futuros 
    ReservationRegistro(std::string nome, int comeco, int fim) {
        course_name = nome;
        start_hour = comeco;
        end_hour = fim;
        next = nullptr;
    }
    };

    // olhar para os registros como um matriz, com os indices apontando para a sala e dia
    ReservationRegistro *** registro;


public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();

};
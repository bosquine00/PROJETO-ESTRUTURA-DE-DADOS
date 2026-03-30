#include <iostream>
using namespace std;
#include "ReservationRequest.hpp"

// CONSTRUTOR ReservationRequest
ReservationRequest::ReservationRequest(string course_name, string weekday, int start_hour, int end_hour, int student_count){
    this-> course_name = course_name;
    this-> weekday = weekday;
    this-> start_hour = start_hour;
    this-> end_hour = end_hour;
    this-> student_count = student_count;
}

// DESTRUTOR ReservationRequest
ReservationRequest :: ~ReservationRequest(){   
}

string ReservationRequest::getCourseName(){
    return course_name;
}
string ReservationRequest::getWeekday(){
    return weekday;
}
int ReservationRequest::getStartHour(){
    return start_hour;
}
int ReservationRequest::getEndHour(){
    return end_hour;
}
int ReservationRequest::getStudentCount(){
    return student_count;
}
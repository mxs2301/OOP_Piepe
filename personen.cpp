#include<iostream>
#include <string>
#include"personen.h"

hfu::Person::Person() {}

hfu::Person::Person(const std::string &Firstname, const std::string &Lastname):Firstname(Firstname), Lastname(Lastname){}

hfu::Person::Person(const hfu::Person &copy):
Firstname(copy.Firstname),
Lastname(copy.Lastname)
{}

std::string hfu::Person::getFirstname() const{
    return Firstname;
}

std::string hfu::Person::getLastname() const{
    return Lastname;
}

const int hfu::Person::compare(const Person& other){
    if(this->Lastname>other.Lastname){
        return 1;
    }else if(this->Lastname == other.Lastname){
        if(this->Firstname>other.Firstname)
            return 1;
        else if(this->Firstname==other.Firstname)
            return 0;
    }
    return -1;
}

bool hfu::Person::operator<(const Person& other){
    // bool result = true;
    if(compare(other)==-1)
        return false;
    else
        return true;
}

bool hfu::Person::operator>(const Person& other){
    if(compare(other) == 1)
        return false;
    else
        return true;
}


void hfu::Person::sort(Person* input, int const& inputSize){
    for(int i = 0; i<inputSize-1; i++){
        for(int j = 0; j<inputSize-1; j++){
            if(input[j]<input[j+1]){
                hfu::Person tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;
            }
        }
    }
}


std::ostream& operator<<(std::ostream& out, hfu::Person& person){

        out << person.getFirstname() << " " << person.getLastname() << std::endl;
    return out;

}







#include "test.h"
#include "Movie.h"
#include "personen.h"
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include "Wordsequence.h"

void test_copy(){
    std::string Firstname = "Max";
    std::string Lastname = "Schopf";
    hfu::Person A(Firstname, Lastname);

    hfu::Person B(A);

    Firstname = "Michael";
    assert(A.getFirstname() == B.getFirstname());
    //std::cout << "Copy success:\t" << A.getFirstname() <<" == " << B.getFirstname() << "\n";

}

void test_movie(){
    hfu::Person director("Donald", "Duck");
    int scores[] = {4, 7, 1, 1};
    cinema::Movie scored_movie("Modern Times", 90, director, scores, 4);
    scored_movie.setScore(3,42);
    assert(scored_movie.getScore(3) == 42);

}

void test_movie_2(){
    hfu::Person director("Donald", "Duck");
    int scores[] = {4, 7, 1, 1};
    cinema::Movie scored_movie("Modern Times", 90, director, scores, 4);
    auto copy=scored_movie;
    scored_movie.setScore(3,42);
    //std::cout << copy.getScore(3);
    assert(copy.getScore(3) == 1);
}

// Test für Aufgabenblatt 7

hfu::Person* createArr(){
    hfu::Person* result = new hfu::Person[4];
    result[0]= hfu::Person("Minnie", "Maus");
    result[1] = hfu::Person("Daisy", "Duck");
    result[2] = hfu::Person("Donald", "Duck");
    result[3] = hfu::Person("Micky", "Maus");
    return result;
}





void test_sort(){
    int size = 4;
    hfu::Person* persons = createArr();
    hfu::sort(persons, size);
    assert((persons[0]).getFirstname() == "Daisy");
    assert((persons[1]).getFirstname() == "Donald");
    assert((persons[2]).getFirstname() == "Micky");
    assert((persons[3]).getFirstname() == "Minnie");

    delete[] persons;
}


void test_string(){
    int size = 4;

    std::string Arr[] = { "Go", "Kotlin", "Rust", "Julia"};
    hfu::sort(Arr, size);
    assert(Arr[0] == "Rust");
    assert(Arr[1] == "Kotlin");
    assert(Arr[2] == "Julia");
    assert(Arr[3] == "Go");

    int Ar[4] = {2, 3, 1, 4};
    hfu::sort(Ar, 4);

}

// Was ist gemeint mit ganzzahligen Arrays????

void test_Simple(){

    hfu::Person* persons = createArr();
    SimpleVector list(persons, 3);
    assert(list.getSize()==3);
    assert(list[2].getFirstname()=="Donald");
    assert(list[2].getLastname()=="Duck");
    list[2]=persons[3];
    assert(list[2].getFirstname()=="Micky");
    assert(list[2].getLastname()=="Maus");
    SimpleVector copy;

    assert(copy.getSize()==0);
    copy = list;
    assert(copy[2].getFirstname()=="Micky");
    assert(copy[2].getLastname()=="Maus");
    list[2]=persons[2];
    assert(copy[2].getFirstname()=="Micky");
    assert(copy[2].getLastname()=="Maus");
    copy=copy;
    assert(copy[2].getFirstname()=="Micky");
    assert(copy[2].getLastname()=="Maus");
    delete[] persons;
}

void runing() {
    test_string();
    test_sort();
    test_Simple();
    printf("Finished\n");
}

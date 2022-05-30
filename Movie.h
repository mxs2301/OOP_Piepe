#ifndef _MOVIE_H_
#define _MOVIE_H_
#include<iostream>
#include"personen.h"

namespace cinema{
    class Movie{

    private:
        std::string Title;
        std::string Regissuer;
        int Duration;
        int length;
        hfu::Person director;
        int *scores;



    public:
        Movie(const std::string& Title, const int& Duration, const hfu::Person& director,const int *scores, const int length);
        Movie(const std::string& Title,const std::string& Regissuer,const int& Duration);
        Movie(const Movie& copy);

        std::string getTitle();
        std::string getRegissuer();

        int getDuration();
        int getScore(int input);
        int getScoreCount();

        void setScore(int index, int score);
        int* createArr(const int *scores, const int &arrSize);

        ~Movie();

    };
};

#endif

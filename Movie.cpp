#include"Movie.h"
#include"personen.h"

cinema::Movie::Movie(const std::string& Title,const std::string& Regissuer,const int& Duration): Title(Title), Regissuer(Regissuer), Duration(Duration){}

cinema::Movie::Movie(const std::string& Title,const int& Duration, const hfu::Person& director, const int *scores,const int length):
Title(Title),
Duration(Duration),
length(length),
director(director),
scores(createArr(scores, length))
{}

cinema::Movie::Movie(const Movie& copy) :
Title(copy.Title),
Duration(copy.Duration),
length(copy.length),
director(copy.director),
scores(createArr(copy.scores, copy.length))
{}


int* cinema::Movie::createArr(const int *scores, const int &arrSize) {
    int *Arr = new int[arrSize];
    for (int i = 0; i< arrSize;i++){
    Arr[i] = scores[i];
}
    return Arr;

}

std::string cinema::Movie::getTitle(){
    return Title;
}

std::string cinema::Movie::getRegissuer(){
    return Regissuer;
}

int cinema::Movie::getDuration(){
    return Duration;
}

int cinema::Movie::getScore(int input){
    return this->scores[input];
}

int cinema::Movie::getScoreCount(){
    return length;
}

void cinema::Movie::setScore(int index, int score) {
    if (index >= length || index < 0)
        throw std::invalid_argument("Your input was either below 0 or out of the Arraybounds\n");
    this->scores[index] = score;
}

cinema::Movie::~Movie() {
    delete[] scores;
}

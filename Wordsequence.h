//
// Created by max on 28/05/22.
//

#ifndef CODE_WORDSEQUENCE_H
#define CODE_WORDSEQUENCE_H

#include "string"
#include <cstdio>
#include <cstdlib>
#include <string>
#include "personen.h"

template<typename  T>
class Wordsequence {
private:
    T* words = nullptr;
    int size = 0;


public:

    Wordsequence(T words[], int size):
            words(createArr(size, words)),
            size(size)
    {}


    Wordsequence():
            words(nullptr),
            size(0)
    {}


    Wordsequence(const Wordsequence& input):
            words(input.words),
            size(input.size)
    {}

    T* createArr(int size, const T* words){
        T* copy = new T[size];
        for(int i = 0; i<size; i++){
            copy[i] = words[i];
        }
        return copy;
    }


    Wordsequence& operator = (const Wordsequence &input){
        if(this == &input)
            return *this;
        delete[] words;
        words = new T[input.size];
        this->size = input.size;
        words = createArr(input.size, input.words);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, Wordsequence& sequence){
        for(int i = 0; i<sequence.getSize(); i++){
            out << sequence[i];
            if(i != sequence.getSize()-1){
                printf(",");
            }
            printf(" ");
        }
        return out;

    }


    T& operator[](int position){
        if(position< 0 || position >= size){
            throw new std::string("Invalid operator");
        }else{
            return words[position];
        }
    }

    T& operator[](int position)const{
        if(this->words == nullptr){
            printf("No\n");
        }else {
            return words[position];
        }

    }


    int getSize(){
        return size;
    }

    void word(int position, const T& word){
        if(this->words == nullptr || size == 0){
            printf("Nope\n");
        }else {
            this->words[position] = word;
        }
    }

    ~Wordsequence(){
        if(words != nullptr)
            delete[] words;
    }
};
typedef Wordsequence<hfu::Person> SimpleVector;

#endif //CODE_WORDSEQUENCE_H

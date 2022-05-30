#ifndef _PERSONEN_H_
#define _PERSONEN_H_

#include <iostream>
#include <string>

namespace hfu {

class Person {

private:
  std::string Firstname;
  std::string Lastname;

    const int compare(const Person &other);


public:
  Person(const std::string &Firstname, const std::string &Lastname);
  Person();
  Person(const hfu::Person &copy);

  std::string getFirstname() const;
  std::string getLastname() const;
  void sort(Person* input, const int& inputSize);

  bool operator<(const Person &other);
  bool operator>(const Person &other);

  friend std::ostream& operator<<(std::ostream& out, Person& person);
};

    template<typename T>void sort(T* Arr, const int size){
        for(int i= 0; i<size-1; i++){
            for(int j = 0; j<size-1; j++){
                if(Arr[j]<Arr[j+1]){
                    T tmp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = tmp;
                }
            }
        }
    }


} // namespace hfu

#endif

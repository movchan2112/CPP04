#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include <Brain.hpp>

class Brain;

class Animal {
protected:
    std::string _type;
    Brain*      br;
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    void getType() const;
    virtual void makeSound() const = 0;
};

#endif
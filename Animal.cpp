#include "Animal.hpp"
#include <iostream>


Animal::Animal() {
    _type = "Animal";
};

void Animal::getType() const{
    std::cout << _type << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Generic sound" << std::endl;
}

Cat::Cat() : Animal(){
    _type = "CAT";
}

// void Cat::makeSound() const {
//     std::cout << "Cat sound MEOW" << std::endl;
// }
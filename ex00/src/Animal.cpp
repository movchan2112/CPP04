#include "../inc/Animal.hpp"


Animal::Animal() {
    _type = "Animal";
};

Animal::Animal(const Animal& other) {
    _type = other._type;
};

Animal& Animal::operator=(const Animal& other){
    if(this != &other){
        this->_type = other._type;
    }
    return *this;
}

Animal::~Animal() {};

std::string Animal::getType() const{
    return _type;
}

void Animal::makeSound() const {
    std::cout << "Generic sound" << std::endl;
}


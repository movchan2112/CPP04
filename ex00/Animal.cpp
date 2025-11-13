#include "Animal.hpp"
#include <iostream>


Animal::Animal() {
    _type = "Animal";
};

Animal::Animal(std::string name) {
    _type = name;
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

void Animal::getType() const{
    std::cout << _type << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Generic sound" << std::endl;
}




////-------CAT-------////


Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}



////-------DOG-------////




Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! 🐾" << std::endl;
}

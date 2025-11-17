#include "Animal.hpp"

Animal::Animal()
: _type("Animal"), br(new Brain())
{}

Animal::Animal(const Animal& other)
{
    _type = other._type;

    if (other.br)
        br = new Brain(*other.br);
    else
        br = NULL;
}


Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        _type = other._type;
        if (br && other.br) {
            *br = *other.br;
        } else if (!br && other.br) {
            br = new Brain(*other.br);
        } else if (br && !other.br) {
            delete br;
            br = NULL;
        }
    }
    return *this;
}

Animal::~Animal() {
    if(br != NULL)
        delete br;
}

void Animal::getType() const {
    std::cout << _type << std::endl;
}

// void Animal::makeSound() const {
//     std::cout << "Generic sound" << std::endl;
// }

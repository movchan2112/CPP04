#include "Animal.hpp"

// ===== Brain =====
Brain::Brain() {
    for (size_t i = 0; i < 100; ++i) _ideas[i].clear();
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (size_t i = 0; i < 100; ++i) _ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; ++i) _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor" << std::endl;
}

// ===== Animal =====
Animal::Animal()
: _type("Animal"), br(new Brain())
{}

Animal::Animal(const std::string& name)
: _type(name), br(new Brain())
{}

Animal::Animal(const Animal& other)
: _type(other._type),
  br(other.br ? new Brain(*other.br) : NULL)
{}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        _type = other._type;
        if (br && other.br) {
            *br = *other.br;               // глубокое копирование в уже существующий Brain
        } else if (!br && other.br) {
            br = new Brain(*other.br);     // у нас нет Brain — создаём копию
        } else if (br && !other.br) {
            delete br;                     // у other нет Brain — освобождаем
            br = NULL;
        } // если оба NULL — ничего не делаем
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
    delete br; // безопасно даже если br == NULL
}

void Animal::getType() const {
    std::cout << _type << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Generic sound" << std::endl;
}

// ===== Cat =====
Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other); // важно: копируем базовую часть (включая Brain)
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

// ===== Dog =====
Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other); // тоже копируем базу
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

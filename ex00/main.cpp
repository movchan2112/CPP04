#include "Animal.hpp"
int main() {
	Animal *a = new Cat();
    a->makeSound();
    a->getType();
    Animal *d = new Dog();
    d->makeSound();
    d->getType();

    a = d;
    a->makeSound();
    a->getType();
}
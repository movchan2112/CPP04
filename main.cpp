#include "Animal.hpp"

int main()
{
    Animal A;
    A.getType();
    Cat C;
    C.getType();
    C.makeSound();

    Animal *B = new Cat();
    B->makeSound();
}
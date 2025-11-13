#include "Animal.hpp"
int main() {
	Animal *a = new Dog();
	a->makeSound();
	delete a;
}
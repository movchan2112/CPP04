#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main() {
	Animal *a = new Cat();
    delete a;

}
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Brain {
protected:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();
};

class Animal {
protected:
	std::string _type;
	Brain*      br;
public:
	Animal();
	Animal(const std::string& name);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	void getType() const;
	virtual void makeSound() const = 0;
};

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	virtual ~Cat();

	virtual void makeSound() const;
};

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual ~Dog();

	virtual void makeSound() const;
};

#endif

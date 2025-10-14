#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        // Animal(const Animal& other);
        // Animal& operator=(const Animal& other);
        virtual ~Animal();

        virtual void makeSound() const;
        void getType() const;
};


class Cat : public Animal
{
    public:
        Cat();
        // Cat(const Cat& other);
        // Cat& operator=(const Cat& other);
        virtual ~Cat();

        void makeSound() const override{
            std::cout << "Cat sound MEOW" << std::endl; };
        // const std::string& getType() const;
};

#endif
#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"
#include <iostream>

// ---- AMateria ----
AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other) {
    (void)other; // copying the type doesn't make sense per subject
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {return _type;}

void AMateria::use(ICharacter& target) {(void)target;}

// ---- Ice ----
Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const& other) : AMateria(other) {}
Ice& Ice::operator=(Ice const& other) { (void)other; return *this; }
Ice::~Ice() {}

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

// ---- Cure ----
Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const& other) : AMateria(other) {}
Cure& Cure::operator=(Cure const& other) { (void)other; return *this; }
Cure::~Cure() {}

AMateria* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

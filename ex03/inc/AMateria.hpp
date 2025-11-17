#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "config.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string _type;
public:
    AMateria(std::string const & type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

class Ice : public AMateria {
public:
    Ice();
    Ice(Ice const& other);
    Ice& operator=(Ice const& other);
    virtual ~Ice();
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

class Cure : public AMateria {
public:
    Cure();
    Cure(Cure const& other);
    Cure& operator=(Cure const& other);
    virtual ~Cure();
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP

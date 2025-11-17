#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "config.hpp"

class Character: public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[INVENTORY_SIZE];
    AMateria* _floor[FLOOR];
public:
    Character(std::string const& name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    virtual void use(int idx, ICharacter& target);
    virtual std::string const& getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
};

#endif // CHARACTER_HPP

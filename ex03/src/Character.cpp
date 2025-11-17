#include "../inc/Character.hpp"
#include "../inc/ICharacter.hpp"
#include <iostream>

// ---- Character ----
Character::Character(std::string const& name) : _name(name) {
    for(int i = 0; i < INVENTORY_SIZE; i++)
        _inventory[i] = NULL;
    for(int i = 0; i < FLOOR; i++)
        _floor[i] = NULL;
}

Character::Character(Character const& other)
: _name(other._name) {
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (other._inventory[i]) _inventory[i] = other._inventory[i]->clone();
        else                     _inventory[i] = NULL;
    }
    for (int i = 0; i < FLOOR; ++i) _floor[i] = NULL;
}

Character& Character::operator=(Character const& other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < INVENTORY_SIZE; ++i) {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
        for (int i = 0; i < FLOOR; ++i) {
            delete _floor[i];
            _floor[i] = NULL;
        }
        for (int i = 0; i < INVENTORY_SIZE; ++i) {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        delete _inventory[i];
        _inventory[i] = NULL;
    }
    for (int i = 0; i < FLOOR; ++i) {
        delete _floor[i];
        _floor[i] = NULL;
    }
}

std::string const& Character::getName() const{
    return _name;
}

void Character::use(int idx, ICharacter& target){
    if(idx >= 0 && idx < INVENTORY_SIZE){
        if(_inventory[idx] != NULL){
            _inventory[idx]->use(target);
            return;
        }
        else
            std::cout << "Empty slot" << std::endl;
    }
    else
        std::cout << "Wrong index in use" << std::endl;
}

void Character::equip(AMateria* m){
    if(!m){
        std::cout << "AMateria is NULL" << std::endl;
        return;
    }
    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(_inventory[i] == m)
        {
            std::cout << "Can't equip twice same pointer" << std::endl;
            return;
        }
    }
    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(_inventory[i] == NULL){
            _inventory[i] = m;
            std::cout << "Equipped at position " << i << std::endl;
            return;
        }
    }
    std::cout << "No space for Materia" << std::endl;
}

void Character::unequip(int idx){
    int pos = -1;
    for(int i = 0; i < FLOOR; i++){
        if(_floor[i] == NULL){
            pos = i;
            break;
        }
    }
    if(pos != -1){
        if(idx >= 0 && idx < INVENTORY_SIZE)
        {
            if(_inventory[idx] != NULL){
                _floor[pos] = _inventory[idx];
                _inventory[idx] = NULL;
            }
            else{
                std::cout << "Empty slot" << std::endl;
            }
        }
        else{
            std::cout << "Wrong index in unequip" << std::endl;
            return;
        }
    }
    else{
        std::cout << "Full floor" << std::endl;
    }
}

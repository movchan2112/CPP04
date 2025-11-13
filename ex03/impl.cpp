#include "all.hpp"

// ---- AMateria ----
AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other) {
	(void)other;
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
				std::cout << "Unequipped" << std::endl;
				return;
			}
			else{
				std::cout << "Empty slot" << std::endl;
				return;
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


// ----- MateriaSource -----
MateriaSource::MateriaSource(){
	for(int i = 0; i < TEMPLATES_SIZE; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& other) {
    for (int i = 0; i < TEMPLATES_SIZE; ++i) _templates[i] = NULL;     // сначала обнулим
    for (int i = 0; i < TEMPLATES_SIZE; ++i) {
        if (other._templates[i])
            _templates[i] = other._templates[i]->clone();              // глубокая копия шаблонов
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
	if (this != &other) {
		for (int i = 0; i < TEMPLATES_SIZE; ++i) {
			delete _templates[i];
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < TEMPLATES_SIZE; ++i) {
		delete _templates[i];
		_templates[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* m){
	if(!m)
		return;
	for(int i = 0; i < TEMPLATES_SIZE; i++)
	{
		if(_templates[i] == NULL)
		{
			_templates[i] = m->clone();
			std::cout << "Learned " << m->getType() << std::endl;
			return;
		}
	}
	delete(m);
	std::cout << "No space in templates" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for(int i = 0; i < TEMPLATES_SIZE; i++)
	{
		if(_templates[i] != NULL)
			if(type == _templates[i]->getType())
			{
				std::cout << "Created "<< _templates[i]->getType() << std::endl;
				return _templates[i]->clone();
			}
	}
	std::cout << "Learn this type {" << type << "} of Materia first " << std::endl;
	return NULL;
};

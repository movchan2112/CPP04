#include "inc/MateriaSource.hpp"
#include "inc/Character.hpp"
#include "inc/AMateria.hpp"

int main(){
	
	// MateriaSource *src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// AMateria *a;
	// ICharacter *m = new Character("Goblin");
	// a = src->createMateria("cure");
	
	// m->equip(a);
	// m->use(0,*m);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
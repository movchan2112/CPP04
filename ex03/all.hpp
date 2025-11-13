#ifndef HEADER_CPP
#define HEADER_CPP


#include <string>
#include <iostream>

#define INVENTORY_SIZE 4
#define FLOOR 100
#define TEMPLATES_SIZE 4

static const std::string M_TYPES[] = {"ice","cure"};
static const int M_COUNTER = 2;

class AMateria;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria* _templates[TEMPLATES_SIZE];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const& other);
		MateriaSource& operator=(MateriaSource const& other);
		~MateriaSource();

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

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

#endif

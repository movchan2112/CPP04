#include "../inc/MateriaSource.hpp"
#include <iostream>

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
            _templates[i] = NULL;
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
            delete(m);
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

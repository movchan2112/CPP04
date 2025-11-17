#include "../inc/Brain.hpp"

Brain::Brain() {
    for (size_t i = 0; i < 100; ++i) _ideas[i].clear();
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (size_t i = 0; i < 100; ++i) _ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; ++i) _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor" << std::endl;
}

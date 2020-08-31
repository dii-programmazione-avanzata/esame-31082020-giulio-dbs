
#include "Individual.h"

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

Individual::Individual(const int *genes, int size): size(size) {
    this->genes = new int[size];
    std::memcpy(this->genes, genes, size * sizeof(int));
}

Individual::Individual(const Individual& other): Individual(other.genes, other.size) {
}

int Individual::fitness() const {
    int fit = 0;
    for (int i = 0; i < size; i++)
    {
        fit += genes[i];
    }
    return fit;
}

std::string Individual::toString() const {
    std::stringstream ss;
    ss << "Individual({";
    for (int i = 0; i < size; i++)
    {
        ss << genes[i];
        if (i < size - 1)
        {
            ss << ", ";
        }
    }
    ss << "}, " << size << ")";
    return ss.str();
}

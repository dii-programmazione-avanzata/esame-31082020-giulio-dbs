
#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>

class Individual
{
protected:
    int size;
    int *genes = nullptr;

public:
    Individual(const int *genes, int n);

    Individual(const Individual& other);

    ~Individual() { delete[] genes; }

    int getSize() const { return size; }

    int *getGenes() const { return genes; }

    int fitness() const;

    std::string toString() const;
};

#endif

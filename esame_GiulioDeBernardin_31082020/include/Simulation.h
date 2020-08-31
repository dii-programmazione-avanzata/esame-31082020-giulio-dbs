
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Individual.h"

enum CrossoverType { co_cut_n_join };

class Simulation
{
protected:
    int pool_size;
    Individual **pool = nullptr;
    int generation = 0;

public:
    Simulation(Individual *pool, int pool_size);

    ~Simulation() { delete[] pool; };

    void run(int sample, CrossoverType ct, int max_iter);

    void crossover(int sample, CrossoverType ct);

    void pickTwo(Individual **left, Individual **right) const;

    void cut_n_join(Individual **sample_pool, int sample);

    void find_less_fitted(Individual **less_fitted, int n) const;

    int fittest_score() const;

    void printStep();
};

#endif

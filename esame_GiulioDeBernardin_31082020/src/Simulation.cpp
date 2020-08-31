
#include "Simulation.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "Individual.h"

Simulation::Simulation(Individual *pool, int pool_size): pool_size(pool_size) {
    this->pool = new Individual*[pool_size];
    for (int i = 0; i < pool_size; i++)
    {
        this->pool[i] = &pool[i];
    }
}

void Simulation::run(int sample, CrossoverType ct, int max_iter) {
    std::cout << "Population of " << pool_size << " individual(s).\n\n";

    printStep();

    for (int i = 0; i < max_iter; i++)
    {
        generation++;
        crossover(sample, ct);
        printStep();
    }
    std::cout << "Simulation reached `max_iter` iterations" << std::endl;
}

void Simulation::crossover(int sample, CrossoverType ct) {
    auto sample_pool = new Individual*[sample];
    switch (ct)
    {
        case co_cut_n_join:
            cut_n_join(sample_pool, sample);
            break;
    }

    auto less_fitted = new Individual*[sample];
    find_less_fitted(less_fitted, sample);

    for (int i = 0; i < sample; i ++)
    {
        *less_fitted[i] = *sample_pool[i];
    }
    delete[] less_fitted;
    delete[] sample_pool;
}

void Simulation::pickTwo(Individual **left, Individual **right) const {
    int i1 = std::rand() % pool_size;
    int i2 = std::rand() % (pool_size - 1);
    if (i1 == i2) i2++;
    *left = pool[i1];
    *right = pool[i2];
}

void Simulation::cut_n_join(Individual **sample_pool, int sample) {
    for (int i = 0; i < sample; i++)
    {
        Individual *left, *right;
        pickTwo(&left, &right);

        auto l_genes = left->getGenes();
        auto r_genes = right->getGenes();

        int l_size = left->getSize();
        int r_size = right->getSize();

        int l_slice = rand() % l_size;
        int r_slice = rand() % r_size;

        int new_size = l_slice + (r_size - r_slice);

        auto new_genes = new int[new_size];

        for (int j = 0; j < new_size; j++)
        {
            if (j < l_slice)
            {
                new_genes[j] = l_genes[j];
            }
            else
            {
                new_genes[j] = r_genes[j];
            }

        }

        sample_pool[i] = new Individual(new_genes, new_size);
        delete[] new_genes;
    }
}

void Simulation::find_less_fitted(Individual **less_fitted, int n) const {
    auto temp_pool = new Individual*[pool_size];

    std::memcpy(temp_pool, pool, pool_size * sizeof pool[0]);

    std::sort(temp_pool, temp_pool + (pool_size - 1), [](auto a, auto b) {
            return a->fitness() < b->fitness();
    });

    std::memcpy(less_fitted, temp_pool, n * sizeof temp_pool[0]);
    delete[] temp_pool;
}

int Simulation::fittest_score() const {
    int score = 0;
    for (int i = 0; i < pool_size; i++)
    {
        int fitness = pool[i]->fitness();
        if (fitness > score) score = fitness;
    }
    return score;
}

void Simulation::printStep() {
    std::cout << "Generation: " << generation << "\n";
    std::cout << "Fittest score: " << fittest_score() << "\n";
    std::cout << "==Genetic Pool==\n";
    for (int i = 0; i < pool_size; i++)
    {
        std::cout << "> Individual " << i << " | ";
        std::cout << pool[i]->toString() << " |\n";
    }
    std::cout << "================\n\n";
}


#include <iostream>

#include "Individual.h"
#include "Simulation.h"

int main()
{
    //create population
    const int gene_pool[5][5] = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
    };

    Individual individual_1(gene_pool[0], 5);
    Individual individual_2(gene_pool[1], 5);
    Individual individual_3(gene_pool[2], 5);
    Individual individual_4(gene_pool[3], 5);
    Individual individual_5(gene_pool[4], 5);

    Individual pool[5] = {
        individual_1,
        individual_2,
        individual_3,
        individual_4,
        individual_5
    };

    Simulation sim(pool, 5);

    sim.run(1, co_cut_n_join, 10);
}

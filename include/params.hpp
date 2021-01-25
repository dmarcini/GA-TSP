#ifndef PARAMS_HPP_
#define PARAMS_HPP_

#include <cstdlib>


class Params
{
public:
    static int iterations_number;

    static size_t population_size;
    // crossover probability
    static double pk;
    // mutation probability
    static double pm;
};


#endif // PARAMS_HPP_

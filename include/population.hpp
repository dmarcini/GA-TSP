#ifndef POPULATION_HPP_
#define POPULATION_HPP_

#include "specimen.hpp"

#include "graph.hpp"


class Population
{
public:
    Population(int chromosome_size);

    size_t size() { return specimens_.size(); }

    void generate_specimens(int size);

    void add_specimen(const Specimen &pecimen);
    Specimen get_specimen(int number);
    Specimen get_random_specimen();
    void pop_specimen();

    void sort(const Graph &graph);
private:
    std::vector<Specimen> specimens_;

    int chromosome_size_;
};


#endif // POPULATION_HPP_

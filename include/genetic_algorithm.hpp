#ifndef GENETIC_ALGORITHM_HPP_
#define GEENTIC_ALGORITHM_HPP_

#include <functional>
#include <vector>
#include <string>
#include <tuple>

#include "graph.hpp"
#include "population.hpp"


using GA = class GeneticAlgorithm;

class GeneticAlgorithm
{
public:
    using LoadDataFcntPtr = 
        std::function<std::vector<std::vector<int>>(const std::string&)>;

    void load_data(const std::string &path, LoadDataFcntPtr load_data);

    void enter_stop_criterium();
    void enter_algorithm_parameters();

    void start();
private:
    std::tuple<Specimen, Specimen> cross_specimens(const Specimen &specimen1,
                                                   const Specimen &specimen2);
    void cross_all_specimens();
    void mutate_specimen(Specimen &specimen);
    void mutate_all_specimens();
    void do_selection();

    double get_double_parameter(std::string_view param);
    int get_int_parameter(std::string_view param);

    Graph graph_;
    Population population_;
};


#endif // GENETIC_ALGORITHM_HPP_

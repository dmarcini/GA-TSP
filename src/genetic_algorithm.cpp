#include "genetic_algorithm.hpp"

#include <tuple>
#include <iostream>
#include <string>

#include "scanner.hpp"
#include "rand.hpp"

#include "params.hpp"


void GA::load_data(LoadDataFcntPtr load_data)
{
    utility::Scanner scanner(std::cin);

    std::cout << "\nEnter graph path: ";

    while (!scanner.has_next()) {
        std::cout << "\nEnter graph path: ";
    }

    graph_.load(load_data(scanner.next()));

    population_.chromosome_size() = graph_.size();
}


void GA::enter_stop_criterium()
{
    Params::iterations_number = get_int_parameter("iterations number");
}


void GA::enter_algorithm_parameters()
{
    Params::population_size = 
        static_cast<size_t>(get_int_parameter("population size"));
    Params::pk = get_double_parameter("crossover probability");
    Params::pm = get_double_parameter("mutation probability");
}


void GA::start()
{
    population_.generate_specimens(Params::population_size);

    for (int i {0}; i < Params::iterations_number; ++i) {
        cross_all_specimens();
        mutate_all_specimens();
        do_selection();

        int path_length {
            graph_.calculate_path_length(population_.get_specimen(0).chromosome())
        };

        if (graph_.path().length() > path_length) {
            graph_.path().route() = population_.get_specimen(0).chromosome();
            graph_.path().length() = path_length;
        }
    }

    graph_.print_path();
}


std::tuple<Specimen, Specimen> GA::cross_specimens(const Specimen &specimen1,
                                                   const Specimen &specimen2)
{
    Specimen new_specimen1(graph_.size());
    Specimen new_specimen2(graph_.size());

    size_t k1 {utility::rand<size_t>(0, graph_.size())};
    size_t k2 {utility::rand<size_t>(k1 + 1, graph_.size())};

    for (size_t i {k1}; i <= k2; ++i) {
        new_specimen1.gen(i) = specimen2.gen(i);
        new_specimen2.gen(i) = specimen1.gen(i);
    }

    size_t old_specimens_gen_index {k2 + 1};
    size_t new_specimen1_gen_index {k2 + 1};
    size_t new_specimen2_gen_index {k2 + 1};

    for (size_t i {0}; i < graph_.size(); ++i) {
        old_specimens_gen_index = 
            (old_specimens_gen_index >= 
             graph_.size()) ? 0 : old_specimens_gen_index;
        new_specimen1_gen_index = 
            (new_specimen1_gen_index >= 
             graph_.size()) ? 0 : new_specimen1_gen_index;
        new_specimen2_gen_index = 
            (new_specimen2_gen_index >= 
             graph_.size()) ? 0 : new_specimen2_gen_index;

        if (!new_specimen1.contains_gen(specimen1.gen(old_specimens_gen_index))) {
            new_specimen1.gen(new_specimen1_gen_index++) = 
                specimen1.gen(old_specimens_gen_index);
        }

        if (!new_specimen2.contains_gen(specimen2.gen(old_specimens_gen_index))) {
            new_specimen2.gen(new_specimen2_gen_index++) = 
                specimen2.gen(old_specimens_gen_index);
        }

        ++old_specimens_gen_index;
    }

    return std::make_tuple(new_specimen1, new_specimen2);
}


void GA::cross_all_specimens()
{
    for (size_t i {0}; i < Params::population_size; ++i) {
        if ((utility::rand(0, 100000) / 100000.0) > Params::pk) {
            continue;
        }

        Specimen specimen1 {population_.get_random_specimen()};
        Specimen specimen2 {population_.get_random_specimen()};

        auto new_specimens {cross_specimens(specimen1, specimen2)};

        population_.add_specimen(std::get<0>(new_specimens));
        population_.add_specimen(std::get<1>(new_specimens));
    }
}


void GA::mutate_specimen(Specimen &specimen)
{
    int k1 {utility::rand(0, graph_.size())};
    int k2 {utility::rand(k1, graph_.size())};

    std::vector<int> subchromosome;

    for (int i {k2}; i > k1; --i) {
        subchromosome.push_back(specimen.gen(i));
    }

    int gen_index {0};

    for (int i {k1 + 1}; i <= k2; ++i) {
        specimen.gen(i) = subchromosome[gen_index++];
    }
}


void GA::mutate_all_specimens()
{
    for (size_t i {0}; i < population_.size(); ++i) {
        if ((utility::rand(0, 100000) / 100000.0) > Params::pm) {
            continue;
        }

        mutate_specimen(population_.get_specimen(i));
    }
}


void GA::do_selection()
{
    population_.sort(graph_);

    while (population_.size() > Params::population_size) {
        population_.pop_specimen();
    }
}


double GA::get_double_parameter(std::string_view parameter)
{
    utility::Scanner scanner(std::cin);

    std::cout << "\nEnter " << parameter << ": ";

    while (!scanner.has_next_double()) {
        std::cout << parameter << " have to be double!\n";
        std::cout << "\nEnter " << parameter << ": ";
    }

    return scanner.next_double();
}


int GA::get_int_parameter(std::string_view parameter)
{
    utility::Scanner scanner(std::cin);

    std::cout << "\nEnter " << parameter << ": ";

    while (!scanner.has_next_int()) {
        std::cout << parameter << " have to be integer!\n";
        std::cout << "\nEnter " << parameter << ": ";
    }

    return scanner.next_int();
}


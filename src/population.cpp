#include "population.hpp"

#include <algorithm>
#include <random>
#include <tuple>

#include "rand.hpp"

#include "specimen.hpp"
#include "graph.hpp"


void Population::generate_specimens(int size)
{
    for (int i {0}; i < size; ++i) {
        std::vector<int> chromosome;

        for (int j {0}; j < chromosome_size_; ++j) {
            chromosome.push_back(j);
        }

        std::shuffle(chromosome.begin(), chromosome.end(),
                     std::mt19937{std::random_device{}()});
    
        specimens_.emplace_back(chromosome);
    }
}


void Population::add_specimen(const Specimen &specimen)
{
    specimens_.push_back(specimen);
}


Specimen& Population::get_specimen(int number)
{
    return specimens_[number];
}


Specimen Population::get_random_specimen()
{
    return specimens_[utility::rand(0, specimens_.size())];
}


void Population::pop_specimen()
{
    specimens_.pop_back();
}


void Population::sort(const Graph &graph)
{
    std::vector<std::tuple<int, int>> ranking;

    for (size_t i {0}; i < specimens_.size(); ++i) {
        int path_length {
            graph.calculate_path_length(specimens_[i].chromosome())
        };

        ranking.emplace_back(i, path_length);
    }

    std::sort(ranking.begin(), ranking.end(), 
              [](const std::tuple<int, int> &e1,
                 const std::tuple<int, int> &e2) {
        return std::get<1>(e1)  < std::get<1>(e2);
    });
}

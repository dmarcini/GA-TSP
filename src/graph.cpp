#include "graph.hpp"

#include <utility>
#include <iostream>


void Graph::load(const std::vector<std::vector<int>> &matrix)
{
    edges_ = matrix;

    for (size_t i {0}; i < matrix.size(); ++i) {
        path_.route().push_back(i);
    }
}


void Graph::print_path()
{
    std::cout << "Visited cities:\n";
    std::cout << path_.route()[0];

    for (size_t i {1}; i < path_.route().size(); ++i) {
        std::cout << " -> " << path_.route()[i];
    }

    std::cout << "\nPath length: " << path_.length() << "\n\n";
}


int Graph::calculate_path_length(const std::vector<int> &route) const
{
    int path_length {0};

    for (size_t i {0}; i < route.size() - 1; ++i) {
        path_length += distance(route[i], route[i + 1]);
    }

    return path_length;
}

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <iostream>
#include <limits>

#include "path.hpp"


class Graph
{
public:
    void load(const std::vector<std::vector<int>> &matrix);

    size_t size() { return edges_.size(); }

    Path& path() { return path_; }

    int& distance(size_t x, size_t y) { return edges_[x][y]; }

    void print_path();
private:
    std::vector<std::vector<int>> edges_;

    Path path_;
};


#endif // GRAPH_HPP_

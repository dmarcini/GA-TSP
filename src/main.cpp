#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <utility>

#include "menu.hpp"


std::vector<std::vector<int>> load_data(const std::string &path)
{
    std::ifstream ifs(path);
    std::vector<std::vector<int>> matrix;
    int size;

    ifs >> size;

    for (int i {0}; i < size; ++i) {
        matrix.push_back({});

        for (int j {0}; j < size; ++j) {
            int value;

            ifs >> value;

            matrix[i].push_back(value);         
        }
    }

    return matrix;
}

int main() {
    utility::Menu menu("\nTraveling Salesman Problem - "
                       "Genetic Algorithm");

    bool was_data_loaded {false};

    menu.append({"Load data", [&was_data_loaded]() { 

        was_data_loaded = true;
    }});
    menu.append({"Enter stop criterium", []() {

    }});
    menu.append({"Enter algorithm parameters", []() {

    }});
    menu.append({"Start", [&was_data_loaded]() {
        if (!was_data_loaded) {
            std::cout << "\nFirst load data!\n";
            return;
        }
    }});

    menu.show();
}

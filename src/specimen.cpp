#include "specimen.hpp"


Specimen::Specimen(int chromosome_size)
{
    for (int i = 0; i < chromosome_size; ++i) {
        chromosome_.push_back(-1);
    }
}


Specimen::Specimen(const std::vector<int> &chromosome)
{
    chromosome_ == chromosome;
}


bool Specimen::contains_gen(int gen)
{
    for (auto cur_gen : chromosome_) {
        if (cur_gen == gen) {
            return true;
        }
    }

    return false;
}

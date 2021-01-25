#include "specimen.hpp"


Specimen::Specimen(int chromosome_size)
    : chromosome_(chromosome_size, -1)
{
}


Specimen::Specimen(const std::vector<int> &chromosome)
    : chromosome_(chromosome)
{
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

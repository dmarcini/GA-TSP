#ifndef SPECIMEN_HPP_
#define SPECIMEN_HPP_

#include <vector>


class Specimen
{
public:
    Specimen(int chromosome_size);
    Specimen(std::vector<int> &&chromosome);

    int& gen(int number) { return chromosome_[number]; }

    bool contains_gen(int gen);
private:
    std::vector<int> chromosome_;
};


#endif // SPECIMEN_HPP_

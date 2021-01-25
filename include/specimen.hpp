#ifndef SPECIMEN_HPP_
#define SPECIMEN_HPP_

#include <vector>


class Specimen
{
public:
    Specimen(int chromosome_size);
    Specimen(const std::vector<int> &chromosome);

    std::vector<int> chromosome() { return chromosome_; }
    std::vector<int> chromosome() const { return chromosome_; }

    int& gen(int number) { return chromosome_[number]; }
    int gen(int number) const { return chromosome_[number]; }  

    bool contains_gen(int gen);
private:
    std::vector<int> chromosome_;
};


#endif // SPECIMEN_HPP_

#ifndef NEMETAL_HPP
#define NEMETAL_HPP
#include <ElementChimic.hpp>

class Nemetal : public ElementChimic
{
    
public:
    Nemetal();
    ~Nemetal();
    Nemetal(const Nemetal &e) = delete;
    Nemetal &operator=(const Nemetal &e);
};

#endif
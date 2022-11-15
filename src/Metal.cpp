#include <iostream>
#include <Metal.hpp>

Metal::Metal() : ElementChimic(13, 27, "Al")
{
}
//ITEM12
Metal::Metal(int masa, int numar, std::string simbol, int duritate) : ElementChimic(masa, numar, simbol), duritate(duritate)
{
}
//ITEM12
Metal &Metal::operator=(const Metal &e)
{
    if (this == &e)
    {
        std::cout << "Assignment to self" << std::endl;
        return *this;
    }
    std::cout << "Copy Assignment Operator in metal" << std::endl;
    //ElementChimic::operator=(e);
    this->duritate = e.duritate;
    return *this;
}

Metal::~Metal()
{
    std::cout << "Metal sters" << std::endl;
}

void Metal::setMasaAtomica(int masa)
{
    std::cout << "S-a apelat metoda din subclasa Metal: " << masa <<std::endl;
}

//ITEM 12
void Metal::printDuritate()
{
    std::cout << this->duritate << std::endl;
}
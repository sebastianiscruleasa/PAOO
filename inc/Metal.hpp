#ifndef METAL_HPP
#define METAL_HPP
#include <ElementChimic.hpp>

class Metal : public ElementChimic
{

private:
    int duritate=10; //ITEM12


public:
    Metal();
    Metal(int masa, int numar, std::string simbol, int duritate); //ITEM12
    ~Metal();    
    Metal(const Metal &e) = delete;
    Metal &operator=(const Metal &e);
    void setMasaAtomica(int masa);
    void printDuritate(); //ITEM12
};

#endif
#ifndef ELEMENTCHIMIC_HPP
#define ELEMENTCHIMIC_HPP

class ElementChimic
{
private:
    int masaAtomica;
    int numarAtomic;
    std::string nume;

public:
    ElementChimic();
    ElementChimic(int masa, int numar, std::string simbol);
    virtual ~ElementChimic();
    ElementChimic(const ElementChimic &e);
    ElementChimic &operator=(const ElementChimic &e);
    ElementChimic &operator+=(const ElementChimic &e); //ITEM 10
    void setMasaAtomica(int masa);
    int getMasaAtomica();
    void setNumarAtomic(int numar);
    int getNumarAtomic();
    void setNume(std::string simbol);
    std::string getNume();
};

#endif 
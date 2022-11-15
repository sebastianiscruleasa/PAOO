#include <iostream>
#include <ElementChimic.hpp>
#include <Metal.hpp>
#include <Nemetal.hpp>

int main()
{
    ElementChimic el;
    Metal m;
    Nemetal n;

    ElementChimic el2(12, 24, "Mg");

    {
        ElementChimic el3;
    }

    ElementChimic e3 = el;
    ElementChimic e4(el);

    el2 = e3;

    std::cout << m.getMasaAtomica() << " " + m.getNume() << std::endl;
    el.setMasaAtomica(12);
    std::cout << el.getMasaAtomica() << std::endl;
    m.setMasaAtomica(13);
    std::cout << m.getMasaAtomica() << std::endl;
    std::cout << el2.getNume() << std::endl;


    std::cout << "TEMA 2" << std::endl;

    //ITEM 10
    ElementChimic e5(8, 16, "O");
    ElementChimic e6(11, 23, "Na");
    ElementChimic e7(1, 1, "H");
    e7 += e6 += e5;
    std::cout << e7.getNumarAtomic() << std::endl;
    std::cout << e7.getMasaAtomica() << std::endl;

    //ITEM 11
    e5=e6;
    e7=e7;

    //ITEM12
    Metal m1(13, 27, "Al",3);
    Metal m2(26, 56 ,"Fe",6);
    m1=m2;
    std::cout << m1.getNumarAtomic() << std::endl;
    m1.printDuritate();

}
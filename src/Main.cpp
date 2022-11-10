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

}
#include <iostream>
#include <ElementChimic.hpp>
#include <Metal.hpp>
#include <Nemetal.hpp>
#include <memory>

using namespace std;

ElementChimic* factoryMethod(){
    return (new ElementChimic);
}

//ITEM14
class Eprubeta{
    private:
        int lungime = 100;
        bool folosita = false;

    public:

    Eprubeta(int lungime){
        std::cout<<"Constructor eprubeta"<<std::endl;
        this->lungime = lungime;
    }

    Eprubeta(const Eprubeta &e){
        std::cout<<"Copy Constructor eprubeta"<<std::endl;
        this->lungime = e.lungime;
        this->folosita = e.folosita;
    }

    ~Eprubeta(){
        std::cout<<"Eprubeta stearsa"<<std::endl;
    }

    int getDimensiune(){
        return this->lungime;
    }

    bool getFolosita(){
        return this->folosita;
    }

    void setFolosita(bool folosita){
        this->folosita = folosita;
    }

    void esteEprubetaFolosita(){
        if(this->folosita == false) 
            std::cout<<"Eprubeta cu lungime de " << this->lungime <<  " NU este folosita in acest moment"<<std::endl;
        else
            std::cout<<"Eprubeta cu lungime de " << this->lungime << " este folosita in acest moment"<<std::endl;
    }
};

void lock(Eprubeta &e){
    std::cout<<"Eprubeta cu lungime de " << e.getDimensiune() << " a fost luata de cineva"<<std::endl;
    e.setFolosita(true);
}

void unlock(Eprubeta &e){
    std::cout<<"Eprubeta cu lungime de " << e.getDimensiune() << " este inapoi la locul ei"<<std::endl;
    e.setFolosita(false);
}

class Chimist{
    private:
        Eprubeta &eprubeta;
    public:
    Chimist(Eprubeta &e):eprubeta(e){
        lock(eprubeta);
    }
    ~Chimist(){
        unlock(eprubeta);
    }
};

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


    std::cout << "TEMA 3" << std::endl;

    //ITEM 13
    {
        auto_ptr<ElementChimic> hidrogen1(factoryMethod());
        auto_ptr<ElementChimic> hidrogen2(hidrogen1);
        //hidrogen1->getNumarAtomic();  //SEGMENTATION FAULT
    }

    {
        unique_ptr<ElementChimic> hidrogen1(factoryMethod());
        //unique_ptr<ElementChimic> hidrogen2(hidrogen1);
        unique_ptr<ElementChimic> hidrogen2 = move(hidrogen1);
        std::cout << hidrogen2->getNumarAtomic() << std::endl; 
    }

    {
        shared_ptr<ElementChimic> hidrogen1(factoryMethod());
        std::cout << "Hidrogen1 " << hidrogen1.use_count() << std::endl;
        shared_ptr<ElementChimic> hidrogen2(hidrogen1);
        std::cout << "Hidrogen1 " << hidrogen1.use_count() << std::endl;
        shared_ptr<ElementChimic> hidrogen3 = move(hidrogen1);
        std::cout << "Hidrogen1 " << hidrogen1.use_count() << std::endl;
        std::cout << "Hidrogen3 " << hidrogen3.use_count() << std::endl;
        //hidrogen1->getNumarAtomic();   //SEGMENTATION FAULT
    }

    //ITEM 14
    Eprubeta e(200);
    Chimist *chimist = new Chimist(e);
    e.esteEprubetaFolosita();
    delete chimist;
    e.esteEprubetaFolosita();
    lock(e);
    e.esteEprubetaFolosita();
    unlock(e);
    e.esteEprubetaFolosita();

}
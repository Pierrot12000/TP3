#include <iostream>
#include "Magasin.h"
#include "Produit.h"

int main()
{
    Magasin magasin("Lidl");
    std::cout << magasin.getname() << std::endl;
    Produit iphone15("Iphone 15", "Le tout dernier et le MEILLEUR des iphones jamais produit", 20, 9999.98);
    std::cout << iphone15 << " coute seulement " << iphone15.getprix() << " euros" << std::endl;
    magasin.addproduct(iphone15); //le nouvel iphone 15 est désormais disponible chez lidl omg j'achète
    magasin.update("Iphone 15", iphone15.getqtt()); //en plus il y a du stock !
    magasin.search("Iphone 15");
}
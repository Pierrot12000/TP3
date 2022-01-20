#include <iostream>
#include "Magasin.h"
#include "Produit.h"

int main()
{
    Magasin magasin("Lidl");
    std::cout << magasin.getname() << std::endl;
    Produit iphone14("apple_iphone", "le tout dernier et le MEILLEUR des iphones jamais produit", 20, 9999.98);
    std::cout << iphone14 << " coute seulement " << iphone14.getprix() << " euros" << std::endl;
}
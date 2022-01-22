#include <iostream>
#include "Magasin.h"
#include "Produit.h"
#include "Client.h"

int main()
{
    Magasin magasin("Lidl");
    std::cout << magasin.getname() << std::endl;
    Produit iphone15("Iphone 15", "Le tout dernier et le MEILLEUR des iphones jamais produit", 20, 9999.98);
    Produit twingo("Twingo", "Twingo sport rs 610cv avec jantes alu", 2, 15245);
    std::cout << iphone15 << " coute seulement " << iphone15.getprix() << " euros" << std::endl;
    magasin.addproduct(iphone15); //le nouvel iphone 15 est désormais disponible chez lidl omg j'achète
    magasin.addproduct(twingo);
    magasin.update("Iphone 15", iphone15.getqtt()); //en plus il y a du stock !
    magasin.update("Twingo", twingo.getqtt());
    magasin.searchproduct("Iphone 15");
    Client client1("Dubois", "Pierre");
    client1.addpanier(iphone15, 1);
    client1.addpanier(twingo, 2);
    std::cout << client1;

    std::cout << std::endl;

    magasin.addclient(client1);
    magasin.dispclient();
    magasin.changeqtt("Iphone 15", 3, client1);
    magasin.delprod("Iphone 15", client1);
    std::cout << client1;
}
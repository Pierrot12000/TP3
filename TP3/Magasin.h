#pragma once
#include <vector>
#include <string>
class Magasin
{
public:
	Magasin(std::string name);
	std::string getname();
private:
	std::string _name;
	/*std::vector <Produits> _produits;
	std::vector <Client> _clients;
	std::vector<Commande> _commandes;  // les tableaux ne sont pas ajoutés au debut car les classes produit client et commande n'existent pas encore*/
};


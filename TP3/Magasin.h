#pragma once
#include <vector>
#include <string>
#include "Produit.h"
class Magasin
{
public:
	Magasin(std::string name);
	std::string getname();
	void addproduct(Produit prod); //permet d'ajouter un produit
	void display(); //permet d'afficher tout les produits
	void search(std::string name); //permet de chercher un produit dans le magasin
	void update(std::string name, int qtt); //permet de mettre a jour la quantitée d'un produit
private:
	std::string _name;
	std::vector <Produit> _produit;
	/*std::vector <Client> _clients;
	std::vector<Commande> _commandes;  // les tableaux ne sont pas ajoutés au debut car les classes produit client et commande n'existent pas encore*/
};


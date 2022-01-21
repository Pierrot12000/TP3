#pragma once
#include<string>
#include<vector>
#include"Produit.h"
class Client
{
public:
	Client(std::string nom, std::string prenom);
	std::string getnom();
	std::string getprenom();
	std::vector <Produit> getpanier();
	std::vector <int> getqtt();
	void addpanier(Produit prod, int qtt);
	void delpanier(); //supprime tout le panier
	void changeqtt(std::string nom, int qtt); //fonction qui permet de changer la quantitée d'un article
	void delprod(std::string nom); //supprimer un element du panier
	friend std::ostream& operator<<(std::ostream& os, const Client& client);

private:
	std::string _nom;
	std::string _prenom;
	std::vector <Produit> _panier;
	std::vector <int> _qtt; //tableau contenant les quantitées respectives de chaque produit du panier
};


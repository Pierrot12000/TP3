#pragma once
#include<string>
#include<vector>
#include"Produit.h"
class Client
{
public:
	Client(std::string nom, std::string prenom, int id);
	std::string getnom();
	std::string getprenom();
	std::vector <Produit> getpanier();
	std::vector <int> getqtt();
	int getid(); //retourne l'identifiant du client
	void addpanier(Produit prod, int qtt);
	void delpanier(); //supprime tout le panier
	void changeqtt(std::string nom, int qtt); //fonction qui permet de changer la quantitée d'un article
	void delprod(std::string nom); //supprimer un element du panier
	friend std::ostream& operator<<(std::ostream& os, const Client& client);

private:
	std::string _nom;
	std::string _prenom;
	int _id; //identifiant unique
	std::vector <Produit> _panier;
	std::vector <int> _qtt; //tableau contenant les quantitées respectives de chaque produit du panier
};
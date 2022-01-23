#pragma once
#include <vector>
#include "Produit.h"
#include "Client.h"
class Commande
{
public:
	Commande(Client &client, int id);
	bool getstatus();
	int getid();
	int getidclient();
	void setstatus(bool status);
	void addproduct(Produit produit, int qtt);
	friend std::ostream& operator<<(std::ostream& os, const Commande& commande);
private:
	Client _client;
	int _idcommande; //identifiant de la commande au cas ou un client fasse plusieurs commandes
	int _id; //identifiant du client
	std::vector <Produit> _produits; //tableau des produits commandés
	std::vector <int> _qtt; //tableau contenant les quantitées respectives de chaque produit de la commande
	bool _status; //status de la commande, true=commande prête
};
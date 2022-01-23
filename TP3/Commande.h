#pragma once
#include <vector>
#include "Produit.h"
#include "Client.h"
class Commande
{
public:
	Commande(Client &client);
	bool getstatus();
	void setstatus(bool status);
	void addproduct(Produit produit, int qtt);
	friend std::ostream& operator<<(std::ostream& os, const Commande& commande);
private:
	Client _client;
	std::vector <Produit> _produits; //tableau des produits command�s
	std::vector <int> _qtt; //tableau contenant les quantit�es respectives de chaque produit de la commande
	bool _status; //status de la commande, true=commande pr�te
};


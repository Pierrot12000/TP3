#include "Commande.h"

Commande::Commande(Client& client)
	:_client(client), _status(false)
{
}

bool Commande::getstatus()
{
	return _status;
}

void Commande::setstatus(bool status)
{
	_status = status;
}

void Commande::addproduct(Produit produit, int qtt)
{
	_produits.push_back(produit);
	_qtt.push_back(qtt);
}

std::ostream& operator<<(std::ostream& os, const Commande& commande)
{
	Client clientcopie = commande._client;
	std::vector<Produit> _produits2=commande._produits;
	std::vector<int> _qtt2 = commande._qtt;
	os << "Le client " << clientcopie.getnom() << " " << clientcopie.getprenom() << "possede la commande suivante :" << std::endl;
	for (int a = 0; a < _produits2.size(); a++)
	{
		os << _produits2[a].getname() << " * " << _qtt2[a] << std::endl;
	}
	if (commande._status == true)
	{
		os << "Cette commande a ete preparee" << std::endl;
	}
	else
	{
		os << "Cette commande est en cours de preparation" << std::endl;
	}
}
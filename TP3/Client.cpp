#include "Client.h"

Client::Client(std::string nom, std::string prenom)
	:_nom(nom), _prenom(prenom)
{
}

std::string Client::getnom()
{
	return _nom;
}

std::string Client::getprenom()
{
	return _prenom;
}

std::vector<Produit> Client::getpanier()
{
	return _panier;
}

std::vector<int> Client::getqtt()
{
	return _qtt;
}

void Client::addpanier(Produit prod, int qtt)
{
	_panier.push_back(prod);
	_qtt.push_back(qtt);
}

void Client::delpanier()
{
	_panier.clear();
	_qtt.clear();
}

std::ostream& operator <<(std::ostream& os, const Client& client)
{
	std::vector <Produit> copie;
	std::vector <int> copie2;
	copie = client._panier; //je copie le tableau car j'avais des erreurs au moment d'appeller les focntions getter des produits du panier
	copie2 = client._qtt; //meme chose ici
	os << client._nom << " " << client._prenom << " possede le panier suivant:" << std::endl;
	for (int a = 0; a < client._panier.size(); a++)
	{
		os << copie[a].getname() << " * " << copie2[a] << std::endl;
	}
	return os;
}

void Client::changeqtt(std::string nom, int qtt)
{
	bool z = false;
	for (int a = 0; a < _panier.size(); a++)
	{
		if (_panier[a].getname().compare(nom) == 0) //si il y a un element du panier qui correspond au nom indiqué
		{
			z = true;
			_qtt[a] = qtt; //on change la quantitée du produit correspondant dans le panier
		}
	}
	if (z == false)
	{
		std::cout << "Aucun element dans votre panier ne correspond a ce nom, verifiez l'ortographe" << std::endl;
	}
}

void Client::delprod(std::string nom)
{
	bool z = false;
	for (int a = 0; a < _panier.size(); a++)
	{
		if (_panier[a].getname().compare(nom) == 0) //si il y a un element du panier qui correspond au nom indiqué
		{
			z = true;
			_panier.erase(_panier.begin() + a); //on efface l'élément du panier
			_qtt.erase(_qtt.begin() + a); //on efface egalement la quantitée correspondante
		}
	}
}
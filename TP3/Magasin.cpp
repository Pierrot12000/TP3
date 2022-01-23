#include "Magasin.h"
Magasin::Magasin(std::string name)
	:_name(name)
{
}

std::string Magasin::getname()
{
	return _name;
}

void Magasin::addproduct(Produit &prod)
{
	_produit.push_back(prod);
}

void Magasin::display()
{
	for (int a = 0; a < _produit.size(); a++)
	{
		std::cout << _produit[a].getname() << std::endl;
	}
}

void Magasin::searchproduct(std::string name)
{
	bool z = false;
	for (int a = 0; a < _produit.size(); a++)
	{
		if (_produit[a].getname().compare(name) == 0) //si le nom recherché correspond a un element du tableau
		{
			z = true;
			std::cout << "Il reste " << _produit[a].getqtt() << " " << _produit[a].getname() << " en stock, a un prix de " << _produit[a].getprix() << " euros" << std::endl;
			std::cout << _produit[a].getdescription() << std::endl;
		}
	}
	if (z == false)
	{
		std::cout << "Le produit que vous cherchez n'existe pas. Verifiez l'ortographe ou essayez un autre magasin" << std::endl;
	}
}

void Magasin::update(std::string name, int qtt)
{
	for (int a = 0; a < _produit.size(); a++)
	{
		if (_produit[a].getname().compare(name) == 0) //si le nom recherché correspond a un element du tableau
		{
			_produit[a].setqtt(qtt);
		}
	}
}

void Magasin::addclient(Client &client)
{
	_clients.push_back(client);
}

void Magasin::dispclient()
{
	std::cout << "Les clients du magasin sont :" << std::endl;
	for (int a = 0; a < _clients.size(); a++)
	{
		std::cout << _clients[a].getnom() << " " << _clients[a].getprenom() << std::endl;
	}
}

void Magasin::searchclient(std::string name)
{
	bool z = false;
	for (int a = 0; a < _clients.size(); a++)
	{
		if (_clients[a].getnom().compare(name) == 0 || _clients[a].getprenom().compare(name) == 0)
		{
			z = true;
			std::cout << "Le client " << _clients[a].getnom() << " " << _clients[a].getprenom() << " fait bien parti du magasin" << std::endl;
		}
	}
	if (z == false)
	{
		std::cout << "Le client que vous cherchez n'appartient pas a ce magasin. Verifiez l'ortographe" << std::endl;
	}
}

void Magasin::addpanier(Produit produit, int qtt, Client &client)
{
	client.addpanier(produit, qtt);
}

void Magasin::delprod(std::string name, Client &client)
{
	client.delprod(name);
}

void Magasin::changeqtt(std::string name, int qtt, Client &customer)
{
	customer.changeqtt(name, qtt);
}
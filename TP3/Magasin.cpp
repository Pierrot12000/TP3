#include "Magasin.h"
Magasin::Magasin(std::string name)
	:_name(name)
{
}

std::string Magasin::getname()
{
	return _name;
}

void Magasin::addproduct(Produit prod)
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

void Magasin::search(std::string name)
{
	bool z = false;
	for (int a = 0; a < _produit.size(); a++)
	{
		if (_produit[a].getname().compare(name) == 0) //si le nom recherché correspond a un element du tableau
		{
			z = true;
			std::cout << "Le produit que vous cherchez est bien " << _produit[a].getname() << std::endl;
			std::cout << _produit[a].getdescription() << std::endl;
			std::cout << "Il reste " << _produit[a].getqtt() << " produits en stock, a un prix de " << _produit[a].getprix() << " euros" << std::endl;
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
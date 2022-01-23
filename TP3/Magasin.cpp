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
	_id.push_back(client.getid());
}

void Magasin::dispclient()
{
	std::cout << "Les clients du magasin sont :" << std::endl;
	for (int a = 0; a < _clients.size(); a++)
	{
		std::cout << _clients[a].getnom() << " " << _clients[a].getprenom() << std::endl;
	}
}

void Magasin::searchclient(int id)
{
	bool z = false;
	for (int a = 0; a < _clients.size(); a++)
	{
		if (_id[a] == id) //si l'identifiant correspond a un enregistré dans le magasin
		{
			z = true;
			std::cout << "Le client " << _clients[a].getnom() << " " << _clients[a].getprenom() << " fait bien parti du magasin" << std::endl; //on affiche le nom et le prénom du client correspondant a cet identifiant
		}
	}
	if (z == false)
	{
		std::cout << "Le client que vous cherchez n'appartient pas a ce magasin. Verifiez l'ortographe" << std::endl;
	}
}

void Magasin::addpanier(Produit& produit, int qtt, Client &client)
{
	bool z = false;
	for (int a = 0; a < _produit.size(); a++)
	{
		if (_produit[a].getname().compare(produit.getname()) == 0)//on cherche dans notre tableau de produit le produit correspondant a celui demandé en comparant les nom
		{
			if (produit.getqtt() >= qtt)//si il y a asser de stocks
			{
				z = true;
				client.addpanier(produit, qtt); //on ajoute le produit au panier
				produit.setqtt(produit.getqtt() - qtt); //et on retire la quantité équivalente aux stocks
			}

		}
	}
	if (z == false)
	{
		std::cout << "Le produit que vous cherchez n'est pas dans le magasin ou est en rupture de stocks" << std::endl;
	}
}

void Magasin::delprod(Produit& produit, Client &client)
{
	for (int a = 0; a < _produit.size(); a++)
	{
		if (_produit[a].getname().compare(produit.getname()) == 0)//on cherche dans notre tableau de produit le produit correspondant a celui demandé en comparant les nom
		{
			for (int b = 0; b < client.getqtt().size(); b++)
			{
				if (client.getpanier()[b].getname().compare(produit.getname()) == 0) //en gros la on cherche a quelle emplacement du tableau du panier du client est situé le produit
				{
					_produit[a].setqtt(_produit[a].getqtt() + client.getqtt()[b]); //une fois l'emplacement trouvé (ici b), on ajoute aux stocks la quantité, puisque que le client n'en veux plus
					client.delprod(client.getpanier()[b].getname());
				}
			}
		}
	}
}

void Magasin::changeqtt(Produit& produit, int qtt, Client &client)
{
	for (int a = 0; a < _produit.size(); a++)
	{
		if (_produit[a].getname().compare(produit.getname()) == 0)//on cherche dans notre tableau de produit le produit correspondant a celui demandé en comparant les nom
		{
			for (int b = 0; b < client.getqtt().size(); b++)
			{
				if (client.getpanier()[b].getname().compare(produit.getname()) == 0)
				{
					if (produit.getqtt() >= _produit[a].getqtt() + client.getqtt()[b] - qtt) //si il y a assez de stocks
					{
						_produit[a].setqtt(_produit[a].getqtt() + client.getqtt()[b] - qtt); //on ajoute l'ancienne valeur aux stocks et on enlève la nouvelle
						client.changeqtt(client.getpanier()[b].getname(), qtt);
					}
					else
					{
						std::cout << "Le produit que vous cherchez n'est pas dans le magasin ou est en rupture de stocks" << std::endl;
					}
				}
			}
		}
	}
}

void Magasin::commander(Client& client, int id)
{
	Commande commande(client, id); //on créer la commande du client
	for (int a = 0; a < client.getpanier().size(); a++)
	{
		commande.addproduct(client.getpanier()[a], client.getqtt()[a]); //on rempli la commande avec les produits qui sont dans le panier du client
	}
	_commandes.push_back(commande); //on ajoute cette commande a la liste des commandes du magasin
	client.delpanier(); //on vide le panier du client
}

void Magasin::statuscommande(int id, bool status)
{
	bool z = false;
	for (int a = 0; a < _commandes.size(); a++)
	{
		if (_commandes[a].getid() == id)
		{
			z = true;
			_commandes[a].setstatus(status);
		}
	}
}

void Magasin::dispcommandes()
{
	for (int a = 0; a < _commandes.size(); a++)
	{
		std::cout << "Identifiant de commande : " << _commandes[a].getid() << std::endl;
		std::cout << _commandes[a] << std::endl;
	}
}

void Magasin::commandesclient(int id)
{
	for (int a = 0; a < _commandes.size(); a++)
	{
		if (_commandes[a].getidclient() == id)
		{
			std::cout << "Identifiant de commande : " << _commandes[a].getid() << std::endl;
			std::cout << _commandes[a] << std::endl;
		}
	}
}
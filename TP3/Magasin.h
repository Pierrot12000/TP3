#pragma once
#include <vector>
#include <string>
#include "Produit.h"
#include "Client.h"
class Magasin
{
public:
	Magasin(std::string name);
	std::string getname();
	void addproduct(Produit prod); //permet d'ajouter un produit
	void display(); //permet d'afficher tout les produits
	void searchproduct(std::string name); //permet de chercher un produit dans le magasin
	void update(std::string name, int qtt); //permet de mettre a jour la quantitée d'un produit
	void addclient(Client client);
	void dispclient(); //permet d'afficher tout les clients du magasin
	void searchclient(std::string name); //permet de chercher un client du magasin par son nom ou son prénom
	void addpanier(Produit produit, int qtt, Client &client); //permet d'ajouter un produit au panier d'un client (mais ca veut dire que le magasin peut faire acheter n'importe quoi a ces clients ???)
	void delprod(std::string name, Client &client); //permet de suprpimer un élément du panier d'un client par son nom
	void changeqtt(std::string name, int qtt, Client &customer); //permet de modifier la quantité d'un produit dans le panier d'un client
private:
	std::string _name;
	std::vector <Produit> _produit;
	std::vector <Client> _clients;
	//std::vector<Commande> _commandes;  // les tableaux ne sont pas ajoutés au debut car les classes produit client et commande n'existent pas encore*/
};


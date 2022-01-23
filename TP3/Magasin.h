#pragma once
#include <vector>
#include <string>
#include "Produit.h"
#include "Client.h"
#include "Commande.h"
class Magasin
{
public:
	Magasin(std::string name);
	std::string getname();
	void addproduct(Produit &prod); //permet d'ajouter un produit
	void display(); //permet d'afficher tout les produits
	void searchproduct(std::string name); //permet de chercher un produit dans le magasin
	void update(std::string name, int qtt); //permet de mettre a jour la quantitée d'un produit
	void addclient(Client &client);
	void dispclient(); //permet d'afficher tout les clients du magasin
	void searchclient(int id); //permet de chercher un client du magasin par son identifiant
	void addpanier(Produit& produit, int qtt, Client &client); //permet d'ajouter un produit au panier d'un client (mais ca veut dire que le magasin peut faire acheter n'importe quoi a ces clients ???)
	void delprod(Produit& produit, Client &client); //permet de suprpimer un élément du panier d'un client
	void changeqtt(Produit& produit, int qtt, Client &client); //permet de modifier la quantité d'un produit dans le panier d'un client
	void commander(Client& client, int id); //permet de créer une commande d'un client et de vider automatiquement son panier. Il faut également donner un identifiant a la comamnde pour pouvoir la différencier des autres commandes du client
	void statuscommande(int id, bool status); //permet de changer le status d'une commande (de la passer a true ou false) avec l'identifiant de la commande
	void dispcommandes(); //permet d'afficher toute les commandes du magasin
	void commandesclient(int id); //permet d'afficher toutes les commandes d'un client avec son identifiant
private:
	std::string _name;
	std::vector <Produit> _produit;
	std::vector <Client> _clients;
	std::vector <Commande> _commandes;
	std::vector <int> _id; //tableau contenant les identifiants des clients
};


# TP3

Réalisation d'un programme qui va faciliter la gestion de votre magasin, voici **EasyStore**

# Explication du programme

De nombreuses classes sont déjà codés et prêtes à être utilisées:
- Une classe pour chaque clients (Class Client)
- Une classe pour les produits de votre magasin (Class Produit)
- Une classe permettant de faire des commandes, mettant en lien les clients avec les produits (Class Commande)
- Enfin, une classe Magasin, qui ici va gérer tout ce qui concerne le panier des clients, leurs commandes, les stocks etc...

Je vais détailler par la suite l'utilisaiton de chaques classes, mais pour vous, tout ce que vous avez a faire c'est créer votre programme dans le main en utilisant les fonctions des classes.
On notera que chaque client et chaque commande ont un identifiant unique, qu'il est important de conserver pour pouvoir utiliser le programme a bon escient

# Classe Client

Le constructeur par défaut de cette classe requiert un nom, un prénom et un identifiant unique de cette forme : `Client(std::string nom, std::string prenom, int id)`
Quand un client est instancié, un panier de `Produits` est créé et lui est associé
L'opérateur "<<" a été surchargé de manière a ce que on puisse afficher facilement le panier d'un client ainsi que les quantitées correspondant a chaque produit du panier

# Classe Produit

Le constructeur par défaut de cette classe requiet un nom, une brève description, une quantitée disponible ainsi qu'un prix. Le tout se présente de la forme : Produit(std::string nom, std::string description, int quantite, float prix)
L'opérateur "<<" a été surchargé de manière a afficher facilement le nom du produit

# Classe Commande

Le constructeur par défaut de cette classe requiert un client et un identifiant unique de commande : `Commande(Client client, int identifiant)`
Quand un client décide de passer commande, tout les articles dans sont panier sont supprimés et placés dans la commande. Est associé avec la commande une varaible qui permet d'avoir le status de celle ci : 
- En cours de préparation
- Commande expédiée
L'opérateur "<<" a également été surchargé pour afficher facilement ce que contient une commande, a quel client elle appartient et quel est sont status.

# Classe Magasin

Le constructeur par défaut de cette classe prend en paramètre le nom du magasin, ce qui donne : Magasin(std::string nom)
La classe magasin permet de tout faire : elle permet de placer les produits dans les paniers des client, de les retirer, de passer une commande, d'ajouter de nouveaux produits en stocks... Voici le détail pour s'en serir
- `addproduct(Produit produit)` permet d'ajouter un produit au magasin
- `display()` permet d'afficher tout les produits disponibles
- `searchproduct(std::string name)` permet de chercher si un produit est listé dans le magasin, en cherchant par son nom
- `update(std::string name, int quantite)` permet de mettre a jour le stock d'un produit
- `addclient(Client client)` permet d'ajouter un nouveau client au magasin
- `dispclient()` permet d'afficher le nom et le prénom de tout les clients du magasin
- `searchclient(int id)` permet de chercher un client du magasin par son identifiant unique
- `addpanier(Produit produit, int quantite, Client client)` permet d'ajouter au panier d'un client un produit en une certaine quantité
- `delprod(Produit produit, Client client)` permet de supprimer un produit du panier d'un client
- `changeqtt(Produit produit, int quantite, Client client)` permet de modifier la quantité d'un produit dans le panier d'un client
- `commander(Client client, int id)` permet de passer commande pour un client. Supprimme automatiquement son panier. Id correspond a l'identifiant unique de la commande
- `statuscommande(int id, bool status)` permet de changer le status d'une commande d'identifiant "id". True correspond a "commande expédiée" et False correspond à "commande en préparation"
- `dispcommandes()` permet d'afficher toutes les commandes du magasin (prètes ou non)
- `commandesclient(int id)` permet d'afficher toutes les commandes du magasin correspondant au client d'identifiant "id"
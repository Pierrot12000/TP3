#include "Produit.h"

Produit::Produit(std::string name, std::string description, int qtt, float prix)
	:_name(name), _description(description), _qtt(qtt), _prix(prix)
{

}

std::string Produit::getname()
{
	return _name;
}

std::string Produit::getdescription()
{
	return _description;
}

float Produit::getprix()
{
	return _prix;
}

int Produit::getqtt()
{
	return _qtt;
}

int Produit::setqtt(int nbr)
{
	_qtt = nbr;
	return 0;
}

std::ostream& operator <<(std::ostream& os, const Produit& produit)
{
	os << produit._name;
	return os;
}
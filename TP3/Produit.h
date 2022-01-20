#pragma once
#include<string>
#include <iostream>
class Produit
{
public:
	Produit(std::string name, std::string description, int qtt, float prix);
	std::string getname();
	std::string getdescription();
	int getqtt();
	float getprix();
	int setqtt(int nbr);
	friend std::ostream& operator<<(std::ostream& os, const Produit& produit);

private:
	std::string _name;
	std::string _description;
	int _qtt;
	float _prix;
};


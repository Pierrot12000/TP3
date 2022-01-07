#include "Magasin.h"
Magasin::Magasin(std::string name)
	:_name(name)
{

}

std::string Magasin::getname()
{
	return _name;
}
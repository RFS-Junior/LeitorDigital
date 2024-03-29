#include "Kobo.h"

Kobo::Kobo(const string &nu,bool comp,const string &us)
:LeitorDigital(nu)
{
	setCompartilhar(comp);
	setUserShare(us);
}

Kobo::Kobo()
:LeitorDigital()
{
	bool comp = true;
	string us = "Vazio";
	setCompartilhar(comp);
	setUserShare(us);
}

Kobo::Kobo (const Kobo &kobo)
:LeitorDigital(static_cast<LeitorDigital>(kobo))
{
	this->compartilhar = kobo.compartilhar;
	this->userShare = kobo.userShare;
}

Kobo::~Kobo(){
}

//Set/Get

void Kobo::setCompartilhar(bool comp){
	this->compartilhar = comp;
}

bool Kobo::getCompartilhar(){
	return this->compartilhar;
}

void Kobo::setUserShare(const string &us){
	this->userShare = us;
}

string Kobo::getUserShare(){
	return this->userShare;
}

ostream &operator<<(ostream &output,const Kobo &kobo){
	output << static_cast< LeitorDigital >( kobo ) << endl;
	output << "Compartilhamento de perfil ativo: " << kobo.compartilhar << endl;
	output << "Nome do Perfil a ser Compartilhado: " << kobo.userShare << endl;
	return output;
}

bool Kobo::operator==(const Kobo &kobo)const{
	if (compartilhar != kobo.compartilhar && userShare != kobo.userShare){
		return false;
	} else {
		return true;
	}
}

bool Kobo::operator!=(const Kobo &kobo)const{
	return ! (*this == kobo);
}

const Kobo &Kobo::operator=(const Kobo &kobo){
	*static_cast< LeitorDigital * >(this) = static_cast< LeitorDigital >(kobo);
		this->compartilhar = kobo.compartilhar;
		this->userShare = kobo.userShare;
	return *this;
}

#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>

int Fahrzeug::p_iMaxID;
extern double dGlobaleZeit;

Fahrzeug::Fahrzeug()
{
	vInitialisiere();
	//cout << "Neues Fahrzeug: '" << p_sName << "' (" << p_iID << ")" << endl;
}

Fahrzeug::Fahrzeug(const Fahrzeug& other)
{
	vInitialisiere();
	p_sName = other.p_sName;
	p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;
}

Fahrzeug::Fahrzeug(const string& sName)
{
	vInitialisiere();
	p_sName = sName;
	//cout << "Neues Fahrzeug: '" << p_sName << "' (" << p_iID << ")" << endl;
}

Fahrzeug::Fahrzeug(const string& sName, const double dMaxGeschwindigkeit)
{
	vInitialisiere();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
	//cout << "Neues Fahrzeug: '" << p_sName << "' (" << p_iID << ")" << endl;
}

void Fahrzeug::vInitialisiere()
{
	p_sName = "";
	p_iID = p_iMaxID++;
	p_dMaxGeschwindigkeit = 0.0;
	p_dGesamtStrecke = 0.0;
	p_dGesamtZeit = 0.0;
	p_dZeit = 0.0;
}

Fahrzeug::~Fahrzeug()
{
	//cout << "Fahrzeug entfernt: '" << p_sName << "' (" << p_iID << ")" << endl;
}

void Fahrzeug::vAusgabe() const
{
	ostreamAusgabe(cout);
}

void Fahrzeug::vAbfertigung()
{
	double dZeitDiff = dGlobaleZeit - p_dZeit;
	//if (dZeitDiff == 0.0) return;
	p_dZeit = dGlobaleZeit;
	p_dGesamtStrecke += dZeitDiff * dGeschwindigkeit(); //p_dMaxGeschwindigkeit
}

double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& os) const
{
	os << resetiosflags(ios::right) << setiosflags(ios::left | ios::fixed);
	os << setprecision(1);
	os << setw(4) << p_iID;
	os << setw(7) << p_sName << " : ";

	os << setw(10) << dGeschwindigkeit();
	os << setw(10) << p_dMaxGeschwindigkeit;
	os << setw(10) << p_dGesamtStrecke;

	return os;
}

bool Fahrzeug::operator<(const Fahrzeug& other) const
{
	return p_dGesamtStrecke < other.p_dGesamtStrecke;
}

ostream& operator<<(ostream& os, const Fahrzeug& fahrzeug)
{
	return fahrzeug.ostreamAusgabe(os);
}
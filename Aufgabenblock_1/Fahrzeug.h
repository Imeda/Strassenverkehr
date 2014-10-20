#pragma once
#include <string>

using namespace std;

class Fahrzeug
{
public:
	Fahrzeug();
	Fahrzeug(const string& sName);
	Fahrzeug(const string& sName, const double dMaxGeschwindigkeit);
	virtual ~Fahrzeug();

	virtual void vAbfertigung();
	virtual void vAusgabe();
	virtual double dGeschwindigkeit();

private:
	string p_sName;
	int p_iID;

	double p_dGesamtZeit, p_dZeit;

	static int p_iMaxID;

protected:
	virtual void vInitialisiere();
	double p_dGesamtStrecke, p_dMaxGeschwindigkeit;
};

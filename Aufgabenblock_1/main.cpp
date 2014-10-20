#include "Fahrzeug.h"
#include "PKW.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double dGlobaleZeit = 0.0;

void vFahrzeugHeader()
{
	cout << resetiosflags(ios::right) << setiosflags(ios::left);
	cout << setw(4) << "ID";
	cout << setw(7) << "Name" << " : ";
	cout << setw(10) << "KmH";
	cout << setw(10) << "MaxKmh";
	cout << setw(10) << "Strecke";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++" << endl;
}

void vAufgabe_1()
{
	Fahrzeug f0, f1("F1");
	Fahrzeug *f2, *f3, *f4, *f5;
	f2 = new Fahrzeug;

	string sName;
	cout << "Name fuer f3? ";
	//cout.flush();
	cin >> sName;

	f3 = new Fahrzeug(sName, 70.0);
	f4 = new Fahrzeug("", 30.0);
	f5 = new Fahrzeug("", 30.0);

	vFahrzeugHeader();
	f0.vAusgabe(); cout << endl;
	f1.vAusgabe(); cout << endl;
	f2->vAusgabe(); cout << endl;
	f3->vAusgabe(); cout << endl;
	f4->vAusgabe(); cout << endl;
	f5->vAusgabe(); cout << endl;

	double dInterval = 0.3;
	for (int i = 0; i < 25; i++) {
		dGlobaleZeit += dInterval;
		f0.vAbfertigung();
		f1.vAbfertigung();
		f2->vAbfertigung();
		f3->vAbfertigung();
		f4->vAbfertigung();
		f5->vAbfertigung();
		f5->vAbfertigung();

		cout << endl;
		f0.vAusgabe(); cout << endl;
		f1.vAusgabe(); cout << endl;
		f2->vAusgabe(); cout << endl;
		f3->vAusgabe(); cout << endl;
		f4->vAusgabe(); cout << endl;
		f5->vAusgabe(); cout << endl;
	}

	delete f5;
	delete f4;
	delete f3;
	delete f2;
}

void vAufgabe_1_deb()
{
	Fahrzeug f0, f1, f2, f3;
	Fahrzeug* pFahrzeuge[4] = { &f0, &f1, &f2, &f3 };

	vFahrzeugHeader();
	for (int i = 0; i < 4; i++)
	{
		pFahrzeuge[i]->vAusgabe(); cout << endl;
	}

	pFahrzeuge[2] = 0; //Fehler einbauen

	for (int i = 0; i < 4; i++) {
		pFahrzeuge[i]->vAusgabe(); cout << endl;
	}
}

void vAufgabe_2()
{
	int iPKWs, iFahrraeder;
	cout << "Anzahl PKWs? ";
	cin >> iPKWs;
	cout << "Anzahl Fahrraeder? ";
	cin >> iFahrraeder;

	vector<Fahrzeug*> fahrzeuge;
	for (int i = 0; i < iPKWs; i++) {
		string sName;
		double dMaxGeschwindigkeit, dVerbrauch;
		cout << "Fahrzeug " << i << endl;
		cout << "Name: "; cin >> sName;
		cout << "Max Geschwindigkeit: "; cin >> dMaxGeschwindigkeit;
		cout << "Verbrauch: "; cin >> dVerbrauch;
		cout << endl;
		PKW* pkw = new PKW(sName, dMaxGeschwindigkeit, dVerbrauch);

		fahrzeuge.push_back(pkw);
	}

	vFahrzeugHeader();
	double dInterval = 0.1;
	while (dGlobaleZeit < 3.0)
	{
		dGlobaleZeit += dInterval;
		for (vector<Fahrzeug*>::iterator it = fahrzeuge.begin(); it != fahrzeuge.end(); it++) {
			(*it)->vAbfertigung();
			(*it)->vAusgabe(); cout << endl;
		}
		cout << "----" << endl;
	}

	for (vector<Fahrzeug*>::iterator it = fahrzeuge.begin(); it != fahrzeuge.end(); it++) {
		delete *it;
	}
}

void main() {
	vAufgabe_2();

	/*string tmp;
	cin >> tmp;*/
	system("pause");
}
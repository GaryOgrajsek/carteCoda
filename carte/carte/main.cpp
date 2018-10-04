#include "coda.h"
#include<fstream>
#include<iostream>
#define DIMO 5
using namespace std;

string richiestaLingua() {
	int rispostaLingua;
	string lingua;
	bool vaBene = false;
	cout << "Quale lingua vuoi?" << endl;
	do {
		cout << "1 per INGLESE, 2 per SPAGNOLO"<<endl;
		cin >> rispostaLingua;
		switch (rispostaLingua) {
		case 1:
			lingua = "inglese.txt";
			vaBene = true;
			break;
		case 2:
			lingua = "spagnolo.txt";
			vaBene = true;
			break;
		default:
			cout << "ERRORE!!!";
		}
	} while (vaBene == false);
	return lingua;
}

void CreazioneFile() {
	string lingua = richiestaLingua();
	ofstream mioFile(lingua);
	carta miaCarta[DIMO];
	string stringa;
	for (int i = 0; i < DIMO; i++) {
		cout << "Carta n° " << i + 1 << endl;
		cout << "Parola in Italiano: ";
		cin >> miaCarta[i].ita;
		cin.ignore();
		cout << "Parola tradotta: ";
		cin >> miaCarta[i].alt;
		stringa = (miaCarta[i].ita + "," + miaCarta[i].alt + "\n");
		mioFile << stringa;
		cout << endl;
	}
	mioFile.close();
}

void Gioca(coda miaCoda) {
	carta challenge;
	string risposta;

	do {
		challenge = Davanti(miaCoda);
		cout << "Italiano: " << challenge.ita << ": ";
		cin >> risposta;
		if (risposta == challenge.alt) {
			cout << "Corretto!!!" << endl;
			Dequeue(miaCoda);
		}
		else {
			cout << "Errato!!!" << endl;
			Enqueue(miaCoda, Davanti(miaCoda));
			Dequeue(miaCoda);
		}
	} while (!(Empty(miaCoda)));
}

void Carica() {

	cout << "Inizio del gioco..." << endl;

	string lingua=richiestaLingua();

	ifstream mioFile(lingua);
	carta elenco[DIM];
	string riga;
	
	coda miaCoda;
	Init(miaCoda);

	int dimFind;
	int s=0;

	for (int i = 0; i < DIM; i++) {
		getline(mioFile, riga);
		dimFind = riga.find(",");
		elenco[i].ita = riga.substr(0, dimFind);
		elenco[i].alt = riga.substr(dimFind + 1, riga.length());
		Enqueue(miaCoda, elenco[i]);
	}
	Gioca(miaCoda);
}

int main() {
	int scelta;
	cout << "Scegli un opzione:" << endl;
	cout << "1) Crea file" << endl;
	cout << "2) Gioca" << endl;
	cout << "altro) Chiudi" << endl;
	cin >> scelta;
	switch (scelta) {
	case 1:
		CreazioneFile();
		break;
	case 2:
		Carica();
		break;
	default:
		break;
	}
	cout << "Fine del programma!" << endl;
	system("PAUSE");
	return 0;
}
#pragma once
#include <string>
#define DIM 5
using namespace std;

struct carta {
	string ita;
	string alt;
};

struct coda {
	carta elem[DIM];
	int iDavanti;
	int iDietro;
};


void Init(coda &);

void Enqueue(coda &, carta);

void Dequeue(coda &);

carta Davanti(coda);

bool Full(coda);

bool Empty(coda);

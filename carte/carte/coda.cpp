#include "coda.h"

void Init(coda & miaCoda) {
	miaCoda.iDavanti= miaCoda.iDietro = 0;
}

void Enqueue(coda &miaCoda, carta x) {
	miaCoda.elem[miaCoda.iDietro] = x;
	miaCoda.iDietro = (miaCoda.iDietro +1)%DIM;
}

void Dequeue(coda &miaCoda) {
	miaCoda.iDavanti = (miaCoda.iDavanti + 1) % DIM;
}

carta Davanti(coda miaCoda) {
	return(miaCoda.elem[miaCoda.iDavanti]);
}

bool Full(coda miaCoda) {
	return(miaCoda.iDavanti == ((miaCoda.iDietro + 1) % DIM));
}

bool Empty(coda miaCoda){
	return(miaCoda.iDavanti == miaCoda.iDietro);
}
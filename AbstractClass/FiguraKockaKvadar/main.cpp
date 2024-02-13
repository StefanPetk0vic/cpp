#include <iostream>
#include"Figura.h"
#include"Kvadar.h"
#include"Kocka.h"
int main() {
	int x = 4;
	int newSize = 0;
	Figura** Niz = new Figura * [x]; //Niz pointer-a za objekte
	for (int i = 0; i < x/2; i++) {
		Niz[i*2] = new Kocka((i+1),1);
		Niz[(i*2)+1] = new Kvadar(1, 2, 3, 2);
	}

	for (int i = 0; i < x / 2; i++) {
		Niz[i * 2]->Ispis();
		Niz[i * 2]->Povrsina();
		std::cout << std::endl;
		Niz[(i * 2) + 1]->Ispis();
		Niz[(i * 2) + 1]->Povrsina();
		std::cout << std::endl;
	}
	//Primer dodavanja novog objekta u niz pointer-a
	std::cout << "Dodaj novu figuru ako x nije vece od 6:";
	if (x < 6) {
		newSize = x + 1;
		Figura** NewNiz = new Figura * [newSize];
		for (int i = 0; i < newSize; i++) {
			NewNiz[i] = Niz[i];
		}
		NewNiz[x] = new Kocka(4, 1);
		
		//Primer kreiranja objekta
		Kocka* OBJ;
		OBJ = new Kocka(1, 2);
		OBJ->Ispis();
		//Brisanje samostalog objekta
		delete OBJ;
		
		//Brisanje starog i preimenovanje novog
		delete[] Niz;
		Niz = NewNiz;
		x = newSize;
	}
	//Proba novo dodatog pointer-a
	Niz[x-1]->Ispis();
	Niz[x-1]->Povrsina();

	//Brisanje niza pointer-a
	if (Niz != nullptr) {
		for (int i = 0; i < x; i++) {
			delete Niz[i];
		}
		delete[] Niz;
	}
}

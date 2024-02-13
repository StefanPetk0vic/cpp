#pragma once
#include"Figura.h"
#include<iostream>
class Kocka :public Figura {
	int a = 0;
public:
	Kocka(int a,int br) :Figura(br) {
		this->a = a;
	};
	void Povrsina() {
		int x = 6 * (a * a);
		std::cout << x;
	}
	void Ispis() {
		std::cout << "Ovo je **KOCKA** samo vrednosti " <<VratiBr()<< std::endl;
	};
	
};

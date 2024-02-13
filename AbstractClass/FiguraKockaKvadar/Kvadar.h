
#pragma once
#include"Figura.h"
#include<iostream>
class Kvadar :public Figura {
	int a = 0;
	int b = 0;
	int c = 0;
public:
	Kvadar(int a,int b,int c, int br) :Figura(br) {
		this->a = a;
		this->b = b;
		this->c = c;
	};
	void Povrsina() {
		int x = 2 * ((a*b)+(a*c)+(b*c));
		std::cout << x;
	}
	void Ispis() {
		std::cout << "Ovo je **KVADAR** samo vrednosti " << VratiBr() << std::endl;
	};
};

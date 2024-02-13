#pragma once
#include<iostream>
class Figura {
protected:
	int br;
public:
	Figura(int br) :br(br){};
	virtual void Povrsina() = 0;
	virtual void Ispis() {
		std::cout << "Ovo je figura samo vrednosti " << br << std::endl;
	};
	int VratiBr() {
		return br;
	}
};

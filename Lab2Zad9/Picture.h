#pragma once
#include <iostream>
using namespace std;
class Picture {
private:
	int size;
	int** Mat;
	int brojac;
public:

	Picture(int size1):size(size1) {
		Mat = new int* [size];
		for (int i = 0; i < size; ++i) {
			Mat[i] = new int[size];
			for (int j = 0; j < size; ++j) {
				Mat[i][j] = 0;
			}
		}
	}

	~Picture() {
		
		Brisanje();
	}
	inline int VratiSize();
	inline int VratiElement(int i, int j);
	Picture& operator=(const Picture& pic);
	void Brightness(int s);
	friend istream& operator>>(istream& in, Picture& pic);
	friend ostream& operator<<(ostream& out, Picture& pic);
	void Brisanje();
	void Resize(int nWidth,int nHeight);
	void Preklapanje(Picture* Slika);
	int Razlicite();
};

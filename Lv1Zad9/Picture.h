#pragma once
#include <iostream>
class Picture {
private:
	int size;
	int** Mat;
	
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
	void Brightness(int s);
	void Ucitaj();
	void Prikazi();
	void Resize(int nWidth,int nHeight);
	void Brisanje();
};

#include"Picture.h"
#include<iostream>
#include <cmath>
using namespace std;

int Picture::VratiSize() {
	return size;
};
void Picture::Brightness(int s)
{
	for (int i = 0; i < VratiSize(); i++) {
		for (int j = 0; j < VratiSize(); j++) {
			if (Mat[i][j] > 0 && Mat[i][j] < 512) {
				Mat[i][j] += s;
			}
		}
	}
}
void Picture::Ucitaj()
{
	
	for (int i = 0; i < VratiSize(); i++) {
		int j = 0;
		while (j < VratiSize()) {
			int x = 0;
			do {
				cout << "Unesi broj od 0 do 512"<<endl;
				cin >> x;
			} while (x < 0 || x > 512);
			Mat[i][j] = x;
			j++;
		}
	}
}
void Picture::Brisanje()
{
	for (int i = 0; i < size; ++i) {
		delete[] Mat[i];
	}
	delete[] Mat;
};
void Picture::Prikazi()
{
	for (int i = 0; i < VratiSize(); i++) {
		for (int j = 0; j < VratiSize(); j++) {
			cout << Mat[i][j] << " ";
		}
		cout << endl;
	}
};
void Picture::Resize(int nWidth, int nHeight)
{
	// MAT 10x10   MATCOPY 15x15
	double nXFactor = static_cast<double>(VratiSize()) / static_cast<double>(nWidth);
	double nYFactor = static_cast<double>(VratiSize()) / static_cast<double>(nHeight);

	int** CopyMat = new int* [nWidth];
	for (int i = 0; i < nWidth; i++) {
		CopyMat[i] = new int[nHeight];
		for (int j = 0; j < nHeight; j++) {
			CopyMat[i][j] = Mat[static_cast<int>(floor(i * nXFactor))][static_cast<int>(floor(j * nYFactor))];
		}
	}
	Brisanje();
	Mat = CopyMat;
	size = nWidth;
	CopyMat = nullptr;
};

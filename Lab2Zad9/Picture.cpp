#include"Picture.h"
#include<fstream>
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
Picture& Picture::operator=(const Picture& pic) {
if(this==&pic)
	return *this;

for (int i = 0; i < pic.size; i++) {
	delete[] Mat[i];
}
delete[] Mat;

size = pic.size;
Mat = new int* [size];
for (int i = 0; i < size; i++) {
	Mat[i] = new int[size];
	for (int j = 0; j < size; j++) {
		Mat[i][j] = pic.Mat[i][j];
	}
}

return *this;
}
istream& operator>>(istream& in, Picture& pic) {
	int x = 0;
	
	in >> x;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			in >> pic.Mat[i][j];
		}
	}

	if (!(in >> x) || x <= 0) {
		
		ofstream FileOut("mat.txt");
		FileOut << "3 1 2 3 4 5 6 7 8 9 2 10 11 12 13";
		FileOut.close();

	}
	else {
		int* Niz = nullptr;
		Niz = new int[x*x];
		for (int i = 0; i < x * x; i++) {
			in >> Niz[i];
		}
		
		ofstream FileOut("mat.txt");
		FileOut << x << endl;
		for (int i = 0; i < x * x; i++) {
			FileOut << Niz[i] << " ";
		}
		FileOut.close();
	delete[] Niz;
	}
	return in;
}

void Picture::Brisanje()
{
	for (int i = 0; i < size; ++i) {
		delete[] Mat[i];
	}
	delete[] Mat;
};
ostream& operator<<(ostream& out,Picture& pic)
{
	for (int i = 0; i < pic.VratiSize(); i++) {
		for (int j = 0; j < pic.VratiSize(); j++) {
			out << pic.Mat[i][j] << " ";
		}
		out << endl;
	}
	return out;
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
void Picture::Preklapanje(Picture* Slika){
	int x = size;
	if (size > Slika->VratiSize()) {
		x = Slika->VratiSize();
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			Mat[i][j] = (Mat[i][j]+Slika->VratiElement(i,j)) / 2;
		}
	}
}

//Chatgpt clutch
int Picture::Razlicite()
{
	int count = 0;
	bool* Niz = new bool[512];
	//Index sam po sebi sluzi kao znak da li postoji neki broj u 2d arr.
	//Za razliku od pravljenje arr koji cuva brojeve i onda ih svakog posebno uporedjuje.
	for (int i = 0; i < size * size; i++) {
		Niz[i] = { false };
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int broj = Mat[i][j];
			if (!Niz[broj]) {
				Niz[broj] = true;
				count++;
			}
		}
	}
	delete[] Niz;
	return count;
};
int Picture::VratiElement(int i,int j) {
	return Mat[i][j];
}

/*
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
*/

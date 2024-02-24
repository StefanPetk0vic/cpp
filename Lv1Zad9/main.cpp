#include <iostream>
#include"Picture.h"
using namespace std;
int main() {
    Picture* slika = new Picture(3);
    slika->Ucitaj();
    cout << endl;
    slika->Prikazi();
    cout << endl;
    slika->Resize(5, 5);
    slika->Prikazi();
    cout << endl;
    slika->Brightness(14);
    slika->Prikazi();

}

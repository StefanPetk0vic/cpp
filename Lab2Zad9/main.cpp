#include <iostream>
#include<fstream>
#include"Picture.h"
using namespace std;
int main() {
    Picture* slika = new Picture(3);
    Picture S1(2);
    ifstream FileIn("Mat.txt");
    FileIn >> *slika;
    FileIn.close();
    ifstream FileI("Mat.txt");
    FileI >> S1;
    FileIn.close();
    slika->Resize(5,5);
    slika->Brightness(14);
    
    cout << endl;
    
    
     
      S1.Brightness(5);
      cout << *slika;
      cout << endl;
      S1.Preklapanje(slika);
      cout << S1;
      cout << endl;
      slika->Preklapanje(&S1);
      cout << S1;
      cout << endl;
      cout << "Broj razlicitih piksela je: " << slika->Razlicite() << endl;
      Picture* Slika3 = new Picture(2);
      Slika3 = slika;
      cout << *Slika3;
 }

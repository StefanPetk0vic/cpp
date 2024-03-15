#pragma once
#include"Kolekcija.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<limits>
using namespace std;
class Ispit{
private:
    char* Naziv;
    int Ocena;
    int Esbp;
public:
    Ispit(){}
    
    Ispit(const char* NAME,int OCENA,int ESBP):Ocena(OCENA),Esbp(ESBP){
        Naziv=new char[strlen(NAME)+1];
        strcpy(Naziv,NAME);
    }
    friend ostream& operator<<(ostream& out,const Ispit& KOL){
        out<<KOL.Naziv<<" "<<KOL.Ocena<<" "<<KOL.Esbp;
        return out;
    }
    int operator+()const {
        
        return GiveOcena();
    }
    int GiveOcena()const {return Ocena;}
    void SetNAME(char* NAME){
        Naziv=new char[strlen(NAME)+1];
        strcpy(Naziv,NAME);
    }
    void SetOcena(int x){
        Ocena = x;
    }
    void SetESBP(int x){
        Esbp = x;
    }
    friend istream& operator>>(istream& in,Ispit& KOL){
       
        char TempN[30];
        int tempOE=0;
        in.getline(TempN,30,' ');
        KOL.SetNAME(TempN);
        in>>tempOE;
        KOL.SetOcena(tempOE);
        in>>tempOE;
        KOL.SetESBP(tempOE);
        in.ignore(INT_MAX, ' ');
        return in;
    }
};
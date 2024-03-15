#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include<stdexcept>
#include"Ispit.h"
using namespace std;

template<typename T>
    class Kolekcija{
private:
int kapacitet;
int count;
T** podaci;

public:
    Kolekcija(){
        kapacitet=0;
        count=0;
        podaci=nullptr;
    }
    Kolekcija(int element):kapacitet(element){
        count=0;
        podaci=new T*[element];
            for (int i = 0; i < count; i++)
            {
                podaci[i]=nullptr;
            }
            
    }
    ~Kolekcija() {
        if (podaci != nullptr) {
            delete[] podaci;
        }
        podaci = nullptr;
    }
    
    int GiveKapacitet(){return kapacitet;}
    int GiveCount(){return count;}
    
    void DodajPodatak(T element){
            if(count<kapacitet)
            {
                podaci[count++]=new T(element);
            }
            else 
            cout<<"Not enough room !"<<endl;
    }
    friend ostream& operator<<(ostream& out,const Kolekcija<T>& KOL){
        KOL.Print();
        return out;
    }
    friend istream& operator>>(istream& in, Kolekcija<T>& KOL) {
        T element;
        while (in >> element) {
            KOL.DodajPodatak(element);
        }
        return in;
    }
  
    void Print()const{
        for (int i = 0; i < count; i++)
            cout<<*podaci[i]<<" ";
    }
    void Obrisi(int element){
        if(podaci[element]!=nullptr){
            for(int i=element;i<count;i++){
                podaci[i]=podaci[i+1];
            }
            count--;
        }
        else
            cout<<"Ovaj element ne postoji !";
    }
    float OdrediProsek(){
        float rez=0;
        for(int i=0;i<count;i++){
            rez+= +(*podaci[i]);
        }
        return rez=rez/count;
    }
    T NajveciPodatak(){
        T* max = new T(*podaci[0]);
        for (int i = 1; i < count; i++)
        {
            if(max<podaci[i]){
                max=podaci[i];
            }
        }
        return *max;
    }
    void Sacuvaj(const char* FileName){
        ofstream File(FileName);
        if(File.is_open()){
            for(int i=0;i<count;i++)
                File<<*podaci[i]<<" ";
        }
        else{
            throw std::runtime_error("Doslo je do greske s otvaranje File !");
        }
    }
    void Ucitaj(const char* FileName){
        ifstream File1(FileName);
            if(File1.is_open()){
                File1 >> *this;
            }
            else{
                throw std::runtime_error("Doslo je do greske s otvaranje File !");
            }
    }
};
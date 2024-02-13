#include <iostream>
#include <cstdlib>
using namespace std;
#include <bits/stdc++.h>
#include "los.hpp"

int main()
{
    constexpr int ROZMIAR = 12;
    int tab[ROZMIAR];
    int tab2[ROZMIAR] = {5,10,26,34,40,46,50,61,69,76,88,91};
    cout<<"wylosowane liczby:"<<endl;
    wygeneruj(ROZMIAR,tab);
    wyswietl(ROZMIAR,tab);
    cout<<endl<<"sortowanie bąbelkowe"<<endl;
    sort_bombel(tab,ROZMIAR);
    wyswietl(ROZMIAR,tab);
    cout<<endl<<"sortowanie przez wstrząsanie"<<endl;
    sort_wstrzas(tab,ROZMIAR);
    wyswietl(ROZMIAR,tab);
    cout<<endl<<"sortowanie przez wstawianie"<<endl;
    sort_wstaw(tab,ROZMIAR);
    wyswietl(ROZMIAR,tab);
    cout<<endl<<"sortowanie szybkie"<<endl;
    sort_szybkie(tab,0,ROZMIAR);
    wyswietl(ROZMIAR,tab);
    cout<<endl<<"sortowanie przez scalanie"<<endl;
    sort_scalanie(tab,0,ROZMIAR);
    wyswietl(ROZMIAR,tab);
    int liczba;
    cout<<endl<<endl<<"Jaką cyfrę chcesz wyszukać?: ";
    cin>>liczba;
    cout<<endl<<"wyszukiwanie liniowe"<<endl;
    cout<<"twoja cyfra jest w miejscu "<<wysz_linio(tab2,ROZMIAR,liczba)<<endl;
    cout<<endl<<"wyszukiwanie liniowe z wartownikiem"<<endl;
    wysz_linio_zwart(tab2,ROZMIAR,liczba);
    cout<<endl<<endl<<"wyszukiwanie skokowe"<<endl;
    cout<<"twoja cyfra jest w miejscu "<<wysz_skok(tab2,ROZMIAR,liczba)<<endl;
    cout<<endl<<"wyszukiwanie binarne"<<endl;
    cout<<"twoja cyfra jest w miejscu "<<wysz_binar(tab2,0,ROZMIAR,liczba)<<endl;
    cout<<endl<<"wyszukiwanie interpolacyjne"<<endl;
    cout<<"twoja cyfra jest w miejscu "<<wysz_interpol(tab2,0,ROZMIAR,liczba)<<endl;
}
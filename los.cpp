#include <iostream>
#include <cstdlib>
using namespace std;
 
void wygeneruj(int ROZMIAR, int wyl_liczby[]){
    srand((unsigned) time(NULL));
    for(int i = 0; i <= ROZMIAR; i++){
        int random = rand() % 25 + 1;
        wyl_liczby[i] = random;
    }
}
 
void wyswietl(int ROZMIAR, int wyl_liczby[]){
    for(int i = 0; i <= ROZMIAR; i++){
    cout<<wyl_liczby[i]<<" ";
    }
}
 
void sort_bombel(int tab[], int ROZMIAR){
    for(int i = 0; i <= ROZMIAR; i++){
		for(int j = 1; j <= ROZMIAR - i; j++){
		    if(tab[j - 1] > tab[j]){
		        swap(tab[j - 1], tab[j]);
		    }
		}
    }
}

void sort_wstrzas(int tab[], int ROZMIAR){
  int left = 0, right = ROZMIAR - 1;
  bool zamiana = true;
  while (zamiana == true){
    zamiana = false;
    for (int i = left; i < right; i++){
      if (tab[i] > tab[i + 1]){
        swap(tab[i], tab[i + 1]);
        zamiana = true;
      }
    }
    right = right - 1;
    for (int i = right; i > left; i--){
      if (tab[i] < tab[i - 1]){
        swap(tab[i], tab[i - 1]);
        zamiana = true;
      }
    }
    left = left + 1;
  }
}

int main()
{
    constexpr int ROZMIAR = 12;
    int tab[ROZMIAR];
    wygeneruj(ROZMIAR,tab);
    wyswietl(ROZMIAR,tab);
    cout<<endl;
    sort_bombel(tab,ROZMIAR);
    wyswietl(ROZMIAR,tab);
    cout<<endl;
    sort_wstrzas(tab,ROZMIAR);
    wyswietl(ROZMIAR,tab);
}
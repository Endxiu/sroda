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

void sort_wstaw(int tab[], int ROZMIAR) {
    int i, j, x;
    
    for(i = 1; i <= ROZMIAR; i++) {
        x = tab[i];
        j = i - 1;
        while(j >= 0 && tab[j] > x) {
            tab[j + 1] = tab[j];
            j = j - 1;
        };
        tab[j + 1] = x;
    };
};

void sort_szybkie(int tab[], int left, int right) {
    int i = left;
    int j = right;
    int x = tab[(left + right) / 2];

    do {
        while(tab[i] < x) {
            i++;
        };
       
        while(tab[j] > x) {
            j--;
        };
       
        if(i <= j) {
            swap(tab[i], tab[j]);
            i++;
            j--;
        };
    } while(i <= j);
   
    if(left < j) sort_szybkie(tab, left, j);
   
    if(right > i) sort_szybkie(tab, i, right);
};

void sort_scal(int tab[], int p, int q, int ROZMIAR) {
    int n1 = q - p + 1;
    int n2 = ROZMIAR - q;
 
    int L[n1], M[n2];
 
    for (int i = 0; i < n1; i++) {
        L[i] = tab[p + i];
    };
    
    for (int j = 0; j < n2; j++) {
        M[j] = tab[q + 1 + j];
    };
 
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
 
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            tab[k] = L[i];
            i++;
        }
            
        else {
            tab[k] = M[j];
            j++;
        };
            
        k++;
    };
 
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    };
 
    while (j < n2) {
        tab[k] = M[j];
        j++;
        k++;
    };
};
 
void sort_scalanie(int tab[], int left, int right) {
    if (left < right) {
        int m = left + (right - left) / 2;
        
        sort_scalanie(tab, left, m);
        sort_scalanie(tab, m + 1, right);   
        
        sort_scal(tab, left, m, right);
    };
};

int main()
{
    constexpr int ROZMIAR = 12;
    int tab[ROZMIAR];
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
}
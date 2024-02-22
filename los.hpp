#include <iostream>
#include <cstdlib>
using namespace std;
#include <bits/stdc++.h>

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

int wysz_linio(int tab2[], int n, int liczba) 
{ 
    for (int i = 0; i < liczba; i++) 
        if (tab2[i] == liczba) 
            return i; 
    return -1; 
} 

void wysz_linio_zwart(int arr[], int n, int key)
{
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;
    while(arr[i] != key){
        i++;
    }
    arr[n - 1] = last;
    if((i < n - 1) || (arr[n - 1] == key)){
        cout<<"Twoja cyfra jest w miejscu "<<i;
    }else{
        cout<<"nie ma takiej liczby";
    }
}

int wysz_skok(int arr[], int n, int liczba){
    int krok = sqrt(n);
    int prev = 0;
    while (arr[min(krok, n)-1] < liczba){
        prev = krok;
        krok += sqrt(n);
        if (prev >= n){
            return -1;
        }
    }
    while (arr[prev] < liczba){
        prev++;
        if (prev == min(krok, n)){
            return -1;
        }
    }
    if (arr[prev] == liczba){
        return prev;
    }
    return -1;
}

int wysz_binar(int arr[], int low, int high, int liczba){
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == liczba){
            return mid;
        }
        if (arr[mid] < liczba){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int wysz_interpol(int arr[], int poczatek, int koniec, int liczba){
    int pos;
    if (poczatek <= koniec && liczba >= arr[poczatek] && liczba <= arr[koniec]){
        pos = poczatek + (((double)(koniec - poczatek) / (arr[koniec] - arr[poczatek])) * (liczba - arr[poczatek]));
        if (arr[pos] == liczba){
            return pos;
        }
        if (arr[pos] < liczba){
            return wysz_interpol(arr, pos + 1, koniec, liczba);
        }
        if (arr[pos] > liczba){
            return wysz_interpol(arr, poczatek, pos - 1, liczba);
        }
    }
    return -1;
}
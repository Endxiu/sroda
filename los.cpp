#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    constexpr int ROZMIAR = 12;
    int wyl_liczby[ROZMIAR];
    for(int i = 0; i < ROZMIAR; i++){
        int random = rand() % 25 + 1;
        wyl_liczby[i] = random;
        cout<<wyl_liczby[i]<<" ";
    }
}
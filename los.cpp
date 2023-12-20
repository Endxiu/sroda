#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int wyl_liczby[12];
    for(int i=0;i<12;i++){
        int random = rand();
        wyl_liczby[i] = random;
        cout<<wyl_liczby[i]<<" ";
    }
}
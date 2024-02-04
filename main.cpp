// Created by Florin on 01/02/2024.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void citire(int v[], int &n)
{
    cout << "n=";
    cin >> n;
    cout << "Introduceti elementele:" << endl;
    for (int i=1; i<=n; i++)
        cin >> v[i];
}

void initializare(int v[], int &n)
{
    cout << "n=";
    cin >> n;
    srand(time(NULL));
    for (int i=1; i<=n; i++)
        v[i] = rand()%21; // valori aleatoare in intervalul [0,20]
}

void afisare (int v[], int n)
{
    for (int i=1; i<=n; i++)
        cout << v[i] << " ";
     cout << endl;
}

void sortare(...)
{

}

int main()
{
    int v[100], n, k;
    citire(v,n);
    //initializare(v,n); // sau citire
    cout << "Vectorul inainte de sortare" << endl;
    afisare(v,n);
    sortare(v, n);
    cout << "Vectorul dupa sortare" << endl;
    afisare(v,n);
    return 0;
}


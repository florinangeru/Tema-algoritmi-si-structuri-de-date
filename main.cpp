// Created by Florin on 01/02/2024.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void citire(int v[], int &n)
{
    cout << "Introduceti numarul de elementele dorit:" << endl;
    cout << "n="; // numarul de elemente
    cin >> n; // citim numarul de elemente
    cout << "Introduceti elementele folosind ca separator spatiul:" << endl; // afisam mesajul pentru introducerea elementelor vectorului
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


// Sortare prin selectie------------------------------------------------------------------------------------------------
void sortareSelectie(int v[], int n)
{
    int i, j, min_idx, temp;
    for (i = 1; i < n; i++) // Ajustam indexul de start la 1
    {
        min_idx = i;
        for (j = i + 1; j <= n; j++)
        {
            if (v[j] < v[min_idx])
                min_idx = j;
        }

        // Schimbam elementul minim gasit cu primul element neordonat
        temp = v[min_idx];
        v[min_idx] = v[i];
        v[i] = temp;
    }
}


// Sortare prin inserare------------------------------------------------------------------------------------------------
void sortareInserare(int v[], int n)
{
    int i, cheie, j;
    for (i = 2; i <= n; i++)
    {
        cheie = v[i];
        j = i - 1;

        // Mutati elementele v[1..i-1], care sunt mai mari decat cheia, la o pozitie inainte de pozitia lor curenta
        while (j >= 1 && v[j] > cheie)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = cheie;
    }
}


// Sortare prin metoda bulelor (Bubblesort)-----------------------------------------------------------------------------
void bubbleSort(int v[], int n)
{
    int i, j, temp;
    bool swapped; // aceasta variabila verifica daca a avut loc o interschimbare
    for (i = 1; i < n; i++) // Buclează prin vector
    {
        swapped = false;
        for (j = 1; j <= n - i; j++) // Mergi prin vector de la început până la n-i
        {
            if (v[j] > v[j + 1]) // Compară elementele adiacente
            {
                // Dacă elementul curent este mai mare decât următorul, interschimbă-le
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                swapped = true; // Marchează că a avut loc o interschimbare
            }
        }
        // Dacă nu a avut loc nicio interschimbare, înseamnă că vectorul este sortat
        if (!swapped)
            break;
    }
}


// Sortarea prin interclasare (Mergesort)-------------------------------------------------------------------------------
void mergeSort(int v[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i++];
        } else {
            v[k] = R[j++];
        }
        k++;
    }

    while (i < n1) {
        v[k++] = L[i++];
    }
    while (j < n2) {
        v[k++] = R[j++];
    }
}

void mergeSort(int v[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        mergeSort(v, left, mid, right);
    }
}


// Sortarea rapida (Quicksort)------------------------------------------------------------------------------------------
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int v[], int low, int high) {
    int pivot = v[high]; // pivot
    int i = (low - 1); // Indexul elementului mai mic

    for (int j = low; j <= high - 1; j++) {
        // Dacă elementul curent este mai mic sau egal cu pivotul
        if (v[j] <= pivot) {
            i++; // incrementați indexul elementului mai mic
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return (i + 1);
}

void quickSort(int v[], int low, int high) {
    if (low < high) {
        /* pi este indexul de partitionare, v[pi] este acum la locul potrivit */
        int pi = partition(v, low, high);

        // Sortează separat elementele înainte
        // și după partitionare
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}



int main()
{
    int v[100], n, optiune;
    citire(v,n);

    cout << "Selectati metoda de sortare:\n";
    cout << "1. Sortare prin selectie\n";
    cout << "2. Sortare prin inserare\n";
    cout << "3. Bubblesort\n";
    cout << "4. Mergesort\n";
    cout << "5. Quicksort\n";
    cout << "\n";
    cout << "Optiunea dvs.: \n";
    cin >> optiune;

    cout << "Vectorul inainte de sortare" << endl;
    afisare(v,n);

    switch(optiune) {
        case 1:
            sortareSelectie(v, n);
            break;
        case 2:
            sortareInserare(v, n);
            break;
        case 3:
            bubbleSort(v, n);
            break;
        case 4:
            mergeSort(v, 1, n); // Ajustează parametrii dacă este necesar
            break;
        case 5:
            quickSort(v, 1, n); // Ajustează parametrii dacă este necesar
            break;
        default:
            cout << "Optiune invalida!\n";
    }


    cout << "Vectorul dupa sortare:\n";
    afisare(v, n);

    return 0;
}


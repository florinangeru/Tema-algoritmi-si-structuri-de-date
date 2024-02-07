// Created by Florin on 04/02/2024.
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


// 1. Sortare prin selectie---------------------------------------------------------------------------------------------
void sortareSelectie(int v[], int n) // vectorul v cu n elemente
{
    int i, j, min_idx, temp; // i, j - indicii vectorului, min_idx - indicele elementului minim
    for (i = 1; i < n; i++) // Buclam prin vector
    {
        min_idx = i; // Consideram primul element neordonat ca fiind minimul
        for (j = i + 1; j <= n; j++) // Cautam minimul in vectorul neordonat
        {
            if (v[j] < v[min_idx])  // Daca gasim un element mai mic decat minimul curent
                min_idx = j; // Il consideram minim
        }

        // Schimbam elementul minim gasit cu primul element neordonat
        temp = v[min_idx]; // Schimbam elementul minim gasit cu primul element neordonat
        v[min_idx] = v[i];
        v[i] = temp;
    }
}


// 2. Sortare prin inserare---------------------------------------------------------------------------------------------
void sortareInserare(int v[], int n) // vectorul v cu n elemente
{
    int i, cheie, j; // i, j - indicii vectorului, cheie - elementul curent
    for (i = 2; i <= n; i++) // Buclam prin vector
    {
        cheie = v[i]; // Consideram elementul curent ca fiind cheia
        j = i - 1; // Consideram elementele din stanga cheii ca fiind ordonate

        // Mutam elementele v[1..i-1], care sunt mai mari decat cheia, la o pozitie inainte de pozitia lor curenta
        while (j >= 1 && v[j] > cheie)
        {
            v[j + 1] = v[j]; // Mutam elementul la o pozitie inainte
            j = j - 1; // Mutam la stanga
        }
        v[j + 1] = cheie; // Mutam cheia la pozitia sa corecta
    }
}


// 3. Sortare prin metoda bulelor (Bubblesort)--------------------------------------------------------------------------
void bubbleSort(int v[], int n) // vectorul v cu n elemente
{
    int i, j, temp; // i, j - indicii vectorului, temp - variabila temporara
    bool swapped; // aceasta variabila verifica daca a avut loc o interschimbare
    for (i = 1; i < n; i++) // Buclam prin vector
    {
        swapped = false; // Initializam variabila swapped ca fiind falsa
        for (j = 1; j <= n - i; j++) // Mergi prin vector de la început până la n-i
        {
            if (v[j] > v[j + 1]) // Compară elementele adiacente
            {
                // Dacă elementul curent este mai mare decât următorul, interschimbă-le
                temp = v[j];
                v[j] = v[j + 1]; // Schimbă elementele
                v[j + 1] = temp;
                swapped = true; // Marchează că a avut loc o interschimbare
            }
        }
        // Dacă nu a avut loc nicio interschimbare, înseamnă că vectorul este sortat
        if (!swapped)
            break;
    }
}


// 4. Sortarea prin interclasare (Mergesort)----------------------------------------------------------------------------
void mergeSort(int v[], int left, int mid, int right) { // vectorul v cu n elemente si indicii left, mid, right pentru a separa vectorul
    int n1 = mid - left + 1; // Numarul de elemente din prima jumatate
    int n2 = right - mid; // Numarul de elemente din a doua jumatate
    int L[n1], R[n2]; // Vectorii temporari pentru a stoca elementele din jumatati

    for (int i = 0; i < n1; i++) // Copiem elementele in vectorii temporari
        L[i] = v[left + i]; // Copiem elementele din prima jumatate
    for (int j = 0; j < n2; j++) // Copiem elementele in vectorii temporari
        R[j] = v[mid + 1 + j]; // Copiem elementele din a doua jumatate

    int i = 0, j = 0, k = left; // Indicii pentru vectorii temporari si vectorul principal
    while (i < n1 && j < n2) { // Interclasam vectorii temporari in vectorul principal
        if (L[i] <= R[j]) { // Daca elementul din prima jumatate este mai mic sau egal cu elementul din a doua jumatate
            v[k] = L[i++]; // Copiem elementul din prima jumatate in vectorul principal
        } else {
            v[k] = R[j++]; // Copiem elementul din a doua jumatate in vectorul principal
        }
        k++; // Incrementam indicele vectorului principal
    }

    while (i < n1) {
        v[k++] = L[i++]; // Copiem elementele ramase din prima jumatate in vectorul principal
    }
    while (j < n2) {
        v[k++] = R[j++]; // Copiem elementele ramase din a doua jumatate in vectorul principal
    }
}

void mergeSort(int v[], int left, int right) { // vectorul v cu n elemente si indicii left, right pentru a separa vectorul
    if (left < right) { // Daca vectorul are mai mult de un element
        int mid = left + (right - left) / 2; // Gasim mijlocul vectorului
        mergeSort(v, left, mid); // Sortam prima jumatate
        mergeSort(v, mid + 1, right); // Sortam a doua jumatate
        mergeSort(v, left, mid, right); // Interclasam jumatatile sortate
    }
}


// 5. Sortarea rapida (Quicksort)---------------------------------------------------------------------------------------
void swap(int* a, int* b) { // Functie pentru interschimbarea a doua elemente
    int t = *a; // Variabila temporara pentru interschimbare
    *a = *b; // Interschimbare
    *b = t;
}

int partition(int v[], int low, int high) { // vectorul v cu n elemente si indicii low, high pentru a separa vectorul
    int pivot = v[high]; // pivot (elementul ales ca pivot)
    int i = (low - 1); // Indexul elementului mai mic

    for (int j = low; j <= high - 1; j++) { // Buclam prin vector
        // Dacă elementul curent este mai mic sau egal cu pivotul
        if (v[j] <= pivot) { // Daca elementul curent este mai mic sau egal cu pivotul
            i++; // incrementam indexul elementului mai mic
            swap(&v[i], &v[j]); // interschimbam elementele
        }
    }
    swap(&v[i + 1], &v[high]); // interschimbam elementele
    return (i + 1); // returnam indexul pivotului
}

void quickSort(int v[], int low, int high) { // vectorul v cu n elemente si indicii low, high pentru a separa vectorul
    if (low < high) { // Daca vectorul are mai mult de un element
        /* pi este indexul de partitionare, v[pi] este acum la locul potrivit */
        int pi = partition(v, low, high); // Partitionam vectorul si returneaza indexul pivotului

        // Sorteaza separat elementele inainte și după partitionare
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


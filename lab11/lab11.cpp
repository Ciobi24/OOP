//codul colegei gresit
#include <iostream>
using namespace std;
template <typename T>
void merge(T arr[], int st, int mij, int dr)
{
    T* aux = new T[dr - st + 1];
    int i = st, j = mij + 1, k = 0;

    while (i < mij && j < dr) // greseala(2):trebuie i<=mij si j<=dr ca sa includem si capetele, altfel 2 elemente nu sunt luate in considerare
    {
        if (arr[i] <= arr[j])
        {
            aux[k] = arr[i];
            i++;
        }
        else
        {
            aux[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= dr) //greseala(5):i trebuie sa mearga in prima jumatate, pana la mijl, nu pana la dr
    {
        aux[k] = arr[i];
        i++;
        k++;
    }

    while (j <= mij)//greseala(4):j trebuie sa mearga in a doua jumatate, de la mijl pana la dr, nu pana la mijl
    {
        aux[k] = arr[j];
        j++;
        k++;
    }

    for (int i = st; i <= dr; i++)
    {
        arr[i] = aux[i]; //greseala(1): st si dr sunt capete pentru arr, nu pentru aux, aux este indexat de la 0 mereu, arr este bucata pe care lucram din array
    }
}

template <typename T>
void mergesort(T arr[], int st, int dr)
{
    if (st < dr)
    {
        int mij = (st + dr) / 2;

        mergesort(arr, st, mij);
        mergesort(arr, mij, dr); //greseala(3):nu e corect sa punem mij in ambele apeluri, trebuie sa luam sectiuni care se completeaza, nu care se suprapun deci apelurile sunt  mergesort(arr, st, mij); si  mergesort(arr, mij+1, dr);

        merge(arr, st, mij, dr);
    }
}
int main() {

    int b[] = { 4,3,2,1 };
    mergesort(b, 0, 3);
    for (int i = 0; i <= 3; i++)cout << b[i] << " "; //nu schimba deloc ordinea elementelor, greseala copiere in memorie marcata cu (1) in functia merge
   
    cout << endl;
    int a[] = { 2,3,1 };
    mergesort(a, 0, 2);
    for (int i = 0; i <= 2; i++)cout << a[i] << " ";//in functia merge nu mergem pana la capatul drept si mijloc, deci nu dam merge complet la elemente (se omit si cate 2, cel de pe pozitia mij si pozitia dr)
    cout << endl;

    int c[] = { 7,2,3,1 };
    mergesort(c, 0, 3);
    for (int i = 0; i <= 3; i++)cout << c[i] << " "; //stack oveflow, apelul functiilor recursive este gresit, greseala(3)
    
    cout << endl;
    int d[] = { 1,2,1,3};
    mergesort(d, 0, 3);
    for (int i = 0; i <= 3; i++)cout << d[i] << " ";//greseala(4) ultimul element ia valoarea de pe mij, e ceva gresit la indici cand copiem la merge
    
    cout << endl;
    int e[] = { 2,2,1,3 };
    mergesort(e, 0, 3);
    for (int i = 0; i <= 3; i++)cout << e[i] << " ";//greseala(5) obtin 1 2 2 1, se suprapun cele doua jumatati cand copiez, e ceva gresit la indici cand copiem la merge
    cout << endl;
    return 0;
}
//codul colegei corectat
/*


#pragma once

#include <iostream>

template <typename T>
void merge(T arr[], int st, int mij, int dr)
{
    T* aux = new T[dr - st + 1];
    int i = st, j = mij + 1, k = 0;

    while (i <= mij && j <= dr)
    {
        if (arr[i] <= arr[j])
        {
            aux[k] = arr[i];
            i++;
        }
        else
        {
            aux[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mij)
    {
        aux[k] = arr[i];
        i++;
        k++;
    }

    while (j <= dr)
    {
        aux[k] = arr[j];
        j++;
        k++;
    }

    for (int i = st; i <= dr; i++)
    {
        arr[i] = aux[i - st];
    }
}

template <typename T>
void mergesort(T arr[], int st, int dr)
{
    if (st < dr)
    {
        int mij = (st + dr) / 2;

        mergesort(arr, st, mij);
        mergesort(arr, mij + 1, dr);

        merge(arr, st, mij, dr);
    }
}
*/
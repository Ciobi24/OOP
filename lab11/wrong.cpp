//codul meu gresit
/*#include <iostream>
#include <list>
using namespace std;

template<typename T>
void sortAscendent(list<T>& lista)
{
    list<T> copie;
    copie.push_front(lista.front());
    typename list<T>::iterator it = lista.begin(), i;
    for (it; it != lista.end(); it++)
    {
        for (i = copie.begin(); i != copie.end(); i++)
        {
            if (*it >= *i)
            {
                copie.push_front(*it);
                break;
            }
            else  copie.push_back(*it);
        }
    }
    for (i = copie.begin(); i != copie.end(); i++)
        lista.push_back(*i);
}

int main()
{
    list<int> l = { 20, 5, 6 };
    l.push_back(3);
    l.push_back(7);
    l.push_back(1);
    l.push_back(10);
    list<int>::iterator it;

    for (it = l.begin(); it != l.end(); it++)
        cout << *it << " ";

    cout << endl;

    sortAscendent(l);

    for (it = l.begin(); it != l.end(); it++)
        cout << *it << " ";

    return 0;
}
*/

//codul meu corect
/*
#include <iostream>
#include <list>
using namespace std;

template<typename T>
void sort(list<T>& lista)
{
    list<T> copie;
    copie.push_front(lista.front());
    typename list<T>::iterator it = lista.begin(), i;
    it++;
    for (it; it != lista.end(); it++)
    {
        bool ok = false;
        for (i = copie.begin(); i != copie.end(); i++)
        {
            if (*it < *i)
            {
                copie.insert(i, *it);
                ok = true;
                break;
            }
        }
        if (!ok)
            copie.push_back(*it);
    }
    lista.erase(lista.begin(), lista.end());
    for (i = copie.begin(); i != copie.end(); i++)
        lista.push_back(*i);
}

int main()
{
    list<int> l = { 20, 5, 6 };
    l.push_back(3);
    l.push_back(7);
    l.push_back(1);
    l.push_back(10);
    list<int>::iterator it;

    for (it = l.begin(); it != l.end(); it++)
        cout << *it << " ";

    cout << endl;

    sort(l);

    for (it = l.begin(); it != l.end(); it++)
        cout << *it << " ";

    return 0;
}

*/
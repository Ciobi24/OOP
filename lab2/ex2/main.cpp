#include <iostream>
#include <cstring>
#include "Student.h"
#include "functions.h"
using namespace std;
Student s[5], * s1[5] = {&s[0],&s[1],&s[2],&s[3],};
int i,j;
float m, e, h;
char nume[20];
int main()
{
    for (i = 0; i < 5; i++)
    {
        cin >> nume;
        s[i].SetName(nume);
        cin >> m >> e >> h;
        s[i].SetMath(m);
        s[i].SetEng(e);
        s[i].SetHistory(h);
    }
    for(i=0;i<4;i++)
        for (j = i + 1; j < 5; j++)
        {
            if (CompAverage(s[i], s[j]) < 0)
            {
                aux = s[j];
                s[j] = s[i];
                s[i] = aux;
            }
            else
                if (CompAverage(s[i], s[j]) == 0)
                {
                    if (s[i].GetMath() < s[j].GetMath())
                    {
                        aux = s[j];
                        s[j] = s[i];
                        s[i] = aux;
                    }
                    else
                        if (s[i].GetMath() == s[j].GetMath())
                        {
                            if (s[i].GetEng() < s[j].GetEng())
                            {
                                aux = s[j];
                                s[j] = s[i];
                                s[i] = aux;
                            }
                            else
                                if (s[i].GetEng() == s[j].GetEng())
                                {
                                    if (s[i].GetHistory() < s[j].GetHistory())
                                    {
                                        aux = s[j];
                                        s[j] = s[i];
                                        s[i] = aux;
                                    }
                                    else
                                        if (s[i].GetHistory() == s[j].GetHistory())
                                        {
                                            if (strcmp(s[i].GetName(), s[j].GetName()) > 0)
                                            {
                                                aux = s[j];
                                                s[j] = s[i];
                                                s[i] = aux;
                                            }
                                        }
                                }
                        }
                }
        }
    for (i = 0; i < 5; i++)
        cout << s[i].GetName() << endl;

}


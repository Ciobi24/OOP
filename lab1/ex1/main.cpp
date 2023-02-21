#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char s[105];
int n;
int convert(char s[])
{
    int n=0;
    for(int i=0;i<strlen(s);i++)
        n=n*10+(s[i]-'0');
    return n;
}
int main()
{
    FILE *file;
    file=fopen("in.txt","r");
    do
    {
        fgets(s,100,file);
        n+=convert(s);
    }while(!feof(file));
    printf("%d",n);
    fclose(file);
    return 0;
}

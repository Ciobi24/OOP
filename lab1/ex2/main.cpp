#include <iostream>
#include <cstring>
using namespace std;
char s[105],c[105][105];
int vmax[105];
int main()
{
    scanf("%[^\n]",s);
    int a=0,b=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]!=' ')c[a][b++]=s[i];
        else
        {
            c[a][b]='\0';
            a++;
            b=0;
        }
    }
    c[a][b]='\0';
/**pentru verificare memorare cuvinte corect
for(int i=0;i<=a;i++)
    cout<<c[i]<<" ";*/
    int k=0,ok;
    for(int i=0;i<=a;i++)
    {   ok=1;
        for(int j=0;j<=k;j++)
            if(vmax[j]==strlen(c[i]))ok=0;
        if(ok)
        vmax[k++]=strlen(c[i]);
    }
    k--;
    for(int i=0;i<k;i++)
        for(int j=i+1;j<=k;j++)
        if(vmax[i]<vmax[j])swap(vmax[i],vmax[j]);
    for(int i=0;i<=k;i++)
        for(int j=0;j<=a;j++)
        if(strlen(c[j])==vmax[i])
            printf("%s\n",c[j]);

    return 0;
}


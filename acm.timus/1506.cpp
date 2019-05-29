#include <iostream>
#include <cstring>
#define LMAX 6
#define NMAX 105

using namespace std;

struct nr
{
    char s[LMAX];
};
nr num[NMAX];
int nrnum;

int n, col;

void adaugaNum(int x)
{
    char s[LMAX];
    memset(s, 0, sizeof(s));
    int lg = 0;
    if (x == 0)
    {
        s[3] = '0';
        s[1] = s[0] = s[2] = ' ';
        strcpy(num[nrnum++].s, s);
        return ;
    }
    while (x)
    {
        s[lg++] = (char)(x%10+'0');
        x/=10;
    }
    while (lg<4)
    {
        s[lg++]=' ';
    }
    for (int i=0;i<2;i++)
    {
        swap(s[i], s[4-i-1]);
    }
    strcpy(num[nrnum++].s, s);
}

char as[100][500];

int main()
{
    int x;
    cin>>n>>col;
    for (int i= 1; i<=n;i++)
    {
        cin>>x;
        adaugaNum(x);
    }
    int act = 0;
    int peL = n/col;
    if (n%col)
    {
        peL++;
    }
    for (int i=0;i<col;i++)
    {
        for (int j = 0;j<peL;j++)
        {
            strcat(as[j], num[act++].s);
            if (act == n)
            {
                goto gata;
            }
        }
    }
    gata:
    for (int i = 0;i<peL;i++)
    {
        cout<<as[i]<<'\n';
    }
    return 0;
}
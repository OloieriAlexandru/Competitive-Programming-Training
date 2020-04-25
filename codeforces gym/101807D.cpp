#include <bits/stdc++.h>
#define nmax 10005
using namespace std;
char sc[nmax], s[nmax];
int ln;
int main()
{
    cin.getline(sc, nmax);
    if (sc[0] != '-'){
        strcpy(s+1, sc);
        s[0] = '+';
    } else {
        strcpy(s, sc);
    }
    bool first = false;
    ln = strlen(s);
    for (int i=0;i<ln;){
        bool minuss = false;
        if (s[i] == '-'){
            minuss = true;
        }
        ++i;
        int coef = 0, degree = 0;
        if (s[i] == 'x'){
            coef = 1;
        } else {
            while (i < ln && s[i] >= '0' && s[i] <= '9'){
                coef = coef * 10 + (s[i] - '0');
                ++i;
            }
            if (s[i] != 'x'){
                degree = 0;
            }
        }
        if (s[i] == 'x'){
            ++i;
            while (i < ln && s[i] >= '0' && s[i] <= '9'){
                degree = degree * 10 + (s[i] - '0');
                ++i;
            }
            if (degree == 0){
                degree = 1;
            }
        }
        int toPrint = degree * coef;
        if (!toPrint){
            if (first == false){
                cout<<toPrint;
            }
            continue;
        }
        if (minuss){
            cout<<"-";
        } else {
            if (first){
                cout<<"+";
            }
        }
        first = true;
        cout<<toPrint;
        if (degree-1>=2){
            cout<<'x'<<degree-1;
        } else if (degree-1 == 1){
            cout<<'x';
        }
    }
    cout<<'\n';
    return 0;
}

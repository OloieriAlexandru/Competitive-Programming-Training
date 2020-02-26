#include <bits/stdc++.h>
using namespace std;
char c;
int nr,a,b,i,k;
int sumcif(int x){
    int res = 0;
    while (x){
        res += x % 10, x /= 10;
    }
    return res;
}
int reversed(int x){
    int res = 0;
    while (x){
        res=x%10+res*10, x /= 10;
    }
    return res;
}
bool palindrome(int x){
    return reversed(x) == x;
}
int prim(int x) {
    int j;
    for (j=2; j<=sqrt(x); ++j)
        if (x%j==0) break;
    if (x%j==0) return j;
    else return x;
}
int smith(int x)
{
    int s,s1=0,nr=0;
    s=sumcif(x);
    while (x>1){
        int p=prim(x);
        int aux=sumcif(p);
        while (x%p==0){
            s1=s1+aux;
            x=x/p;
            nr++;
        }
    }
    if (s==s1 && nr>1) return 1;
    else return 0;
}
int main()
{
    freopen("smith.in","r",stdin);
    freopen("smith.out","w",stdout);
    cin>>c;
    cin>>nr;
    a=1;
    for (i=1; i<nr; ++i)
        a=a*10;
    b=a*10;
    if (c == 'a'){
        for (i=b-1; i>=a; --i){
            if (smith(i) == 1){
                break;
            }
        }
    } else if (c == 'b'){
        for (i=b-1; i>=a; --i){
            if (palindrome(i) == 1){
                if (smith(i) == 1){
                    break;
                }
            }
        }
    } else if (c == 'c'){
        for (i=b-1; i>=a; --i){
            if (smith(i) == 1){
                k = reversed(i);
                if (smith(k) == 1){
                    break;
                }
            }
        }
    } else {
        for (i=sqrt(b)-1; i*i >= a; --i){
            if (smith(i*i) == 1){
                break;
            }
        }
        i=i*i;
    }
    if (i >= a){
        cout<<i<<'\n';
    } else {
        cout<<"0\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

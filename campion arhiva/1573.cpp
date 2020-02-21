#include <bits/stdc++.h>
using namespace std;
int G, nrl, A, B, C;
struct pct{
    int x, y;
};
typedef pct lot[101];
lot L[101], LM;
pct g[2000],m[2000];
int nrp[101], M;
int GpeL[101], cateMmax, cate0, Mmax;
void citire(){
    cin>>nrl;
    for (int i=1;i<=nrl;++i){
        cin>>nrp[i];
        for (int j=1;j<=nrp[i];++j){
            cin>>L[i][j].x>>L[i][j].y;
        }
        L[i][nrp[i]+1]=L[i][1];
        L[i][nrp[i]+2]=L[i][2];
    }
    cin>>G;
    for (int i = 1; i <= G; i++){
        cin>>g[i].x>>g[i].y;
    }
}
double dist (pct A, pct B){
    return sqrt((double)((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)));
}
double S (double a, double b, double c){
    double p = (a+b+c)/2.0;
    return sqrt ((double)(p*(p-a)*(p-b)*(p-c)));
}
double aria (int l){
    double A = 0, a, b, c;
    for (int i = 2; i < nrp[l]; i++){
        a = dist (LM[1], LM[i]);
        b = dist (LM[i], LM[i+1]);
        c = dist (LM[1], LM[i+1]);
        A += S (a, b, c);
    }
    return A;
}
int numara_cu_arii (int l, double Aria){
    int in_lot = 0, ok;
    double AriaL, a, b, c, A;
    for (int i = 1; i <= M; ++i){
        AriaL = 0.0;
        ok = 1;
        for (int k = 1; k <= nrp[l]; k++){
            a = dist (m[i], LM[k]);
            b = dist (LM[k], LM[k+1]);
            c = dist (m[i], LM[k+1]);
            A = S (a, b, c);
            if (A) AriaL += A;
            else {
                ok = 0;
                break;
            }
        }
        if (fabs (Aria - AriaL) < 0.0001 && ok) in_lot++;
    }
    return in_lot;
}
int main()
{
    freopen("grindina.in","r",stdin);
    freopen("grindina.out","w",stdout);
    double Aria;
    citire();
    for (int l = 1; l <= nrl; l++){
        M = G;
        for (int i = 1; i <= G; i++){
            m[i] = g[i];
        }
        for (int i = 1; i <= nrp[l] + 2; i++){
            LM[i] = L[l][i];
        }
        Aria = aria (l);
        M = numara_cu_arii (l, Aria);
        GpeL[l] = M;
        if (M>Mmax){
            Mmax = M;
            cateMmax = 1;
        } else if (M == Mmax)
                cateMmax++;
        if (M == 0) {
            cate0++;
        }
    }
    cout<<cateMmax<<'\n';
    for (int i = 1; i <= nrl; i++)
        if (GpeL[i] == Mmax)
            cout<<i<<' ';
    cout<<'\n'<<cate0<<'\n';
    if (cate0){
        for (int i = 1; i <= nrl; i++)
            if (GpeL[i] == 0) cout<<i<<' ';
    } else cout<<0<<'\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}

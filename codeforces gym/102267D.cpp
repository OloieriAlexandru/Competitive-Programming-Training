#include <bits/stdc++.h>
#define nmax 15
using namespace std;
int n = 12, m = 12;
vector<vector<int>>v1, v2;
string ans;
vector<vector<int>>getDefault(){
    vector<vector<int>>df;
    df.resize(n+1, vector<int>(n+1));

    df[6][6] = df[6][7] = 1;
    df[7][6] = df[7][7] = 1;

    df[9][2] = df[9][3] = df[9][10] = df[9][11] = 1;
    df[10][2] = df[10][11] = 1;

    return df;
}
pair<int,int>asd[4];
vector<vector<int>>getComplete(){
    auto cv = getDefault();
    for (int i=0;i<4;++i){
        cv[asd[i].first][asd[i].second] = 2;
    }
    return cv;
}
void print(const vector<vector<int>>& v){
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }
}
void check(char ch){
    if (ch == 'a'){
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if (j == m){
                    v2[i][j]=v1[i][j];
                    continue;
                }
                if (v2[i][j] == 0 && v1[i][j+1] == 2 && v1[i][j] != 2){
                    v2[i][j] = 2;
                    v1[i][j+1] = 0;
                } else {
                    if (v2[i][j] == 2){
                        continue;
                    }v2[i][j] = v1[i][j];
                }
            }
        }
    } else if(ch == 'd'){
        for (int i=1;i<=n;++i){
            for (int j=m;j>=1;--j){
                if (j == 1){
                    v2[i][j]=v1[i][j];
                    continue;
                }
                if (v2[i][j] == 0 && v1[i][j-1] == 2 && v1[i][j] != 2){
                    v2[i][j] = 2;
                    v1[i][j-1] = 0;
                } else {
                    if (v2[i][j] == 2){
                        continue;
                    }
                    v2[i][j] = v1[i][j];
                }
            }
        }
    } else if(ch == 'w'){
        for (int j=1;j<=m;++j){
            for (int i=1;i<=n;++i){
                if (i == n){
                    v2[i][j]=v1[i][j];
                    continue;
                }
                if (v2[i][j] == 0 && v1[i+1][j] == 2 && v1[i][j] != 2){
                    v2[i][j] = 2;
                    v1[i+1][j] = 0;
                } else {
                    if (v2[i][j] == 2){
                        continue;
                    }
                    v2[i][j] = v1[i][j];
                }
            }
        }
    } else if(ch == 's'){
        for (int j=1;j<=m;++j){
            for (int i=n;i>=1;--i){
                if (i == 1){
                    v2[i][j]=v1[i][j];
                    continue;
                }
                if (v2[i][j] == 0 && v1[i-1][j] == 2 && v1[i][j] != 2){
                    v2[i][j] = 2;
                    v1[i-1][j] = 0;
                } else {
                    if (v2[i][j] == 2){
                        continue;
                    }
                    v2[i][j] = v1[i][j];
                }
            }
        }
    }
}
vector<vector<int>> apply(vector<vector<int>>aas, char ch){
    if (ch == 'd'){
        ans.push_back('R');
    } else if (ch == 's'){
        ans.push_back('D');
    } else if (ch == 'a'){
        ans.push_back('L');
    } else {
        ans.push_back('U');
    }
    v1 = aas;
    v2 = getDefault();
    check(ch);
    return v2;
}
vector<vector<int>> apply(vector<vector<int>>aas, const char* str){
    vector<vector<int>> par = aas;
    for (int i=0;str[i];++i){
        par = apply(par, str[i]);
    }
    return par;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        for (int i=0;i<4;++i){
            cin>>asd[i].first>>asd[i].second;
        }

        ans.clear();
        vector<vector<int>> asd = getComplete();

        vector<vector<int>> jos = apply(asd, "wdwdwdwdwdwdwdwdwdwdwdwd");
        jos = apply(jos, "wawawawawawawawawawawawa");
        jos = apply(jos, "wwwwwwwwwwww");

        jos = apply(jos, "dddddddddddd");

        if (jos[1][9] == 2){
            jos = apply(jos, "aaasssssdddddwwww");
        } else if (jos[1][10] == 2){
            jos = apply(jos, "aaasssssddddwwwww");
        } else if (jos[4][12] == 2){
            jos = apply(jos, "sssaaaaawwwwwdddd");
        } else if (jos[3][12] == 2){
            jos = apply(jos, "sssaaaaawwwwddddd");
        }

        jos = apply(jos, "aaassssssssssddd");
        jos = apply(jos, "wwaaaaaassaaaawdwdwwwsaaddwwww");

        cout<<ans.size()<<'\n';
        cout<<ans<<'\n';
        //print(jos);
    }
    return 0;
}

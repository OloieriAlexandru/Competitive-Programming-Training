#include <bits/stdc++.h>
using namespace std;
int n, k, x;
stack< bitset<121> > st;
int main()
{
    freopen("liste.in","r",stdin);
    freopen("liste.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&k);
        bitset<121> bits;
        for (int j=1;j<=k;++j){
            scanf("%d",&x);
            bits.set(x);
        }
        while (!st.empty()){
            bitset<121> rs = st.top() & bits;
            if (rs.any()){
                bits = bits | st.top();
                st.pop();
            } else {
                break;
            }
        }
        st.push(bits);
    }
    printf("%d\n", st.size());
    fclose(stdin);
    fclose(stdout);
    return 0;
}

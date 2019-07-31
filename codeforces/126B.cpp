#include <bits/stdc++.h>
#define nmax 1000005
#define mod 1000000007LL
#define lld long long
using namespace std;
char s[nmax];
int ln, ans = -1;
lld leftHashes[nmax];
lld rightHash, leftHash;
vector<int>goodLen;
lld pw = 31, currPow = 1, pows[nmax];
bool good(int mid)
{
    lld mul = pows[mid-1];
    lld hsh = leftHashes[mid-1];
    for (int i=mid;i<ln-1;++i)
    {
        hsh = (hsh - 1LL * s[i-mid] * mul)%mod;
        if (hsh < 0) hsh = mod + hsh;
        hsh = (hsh * pw + s[i])%mod;
        if (hsh == leftHashes[mid-1]) return true;
    }
    return false;
}
int main()
{
    cin>>s;
    ln = strlen(s);
    pows[0] = 1;
    for (int i=1;i<=ln;++i)
        pows[i] = ( pows[i-1] * pw ) % mod;
    for (int i=0;i<ln-1;++i)
    {
        leftHash = (leftHash*pw + s[i])%mod;
        rightHash = (rightHash + s[ln-i-1]*currPow)%mod;
        currPow = (currPow * pw)%mod;
        if (leftHash == rightHash)
            goodLen.push_back(i+1);
        leftHashes[i] = leftHash;
    }
    int lo = 0, hi = goodLen.size()-1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) >> 1;
        if(good(goodLen[mid]))
            ans = max(ans, goodLen[mid]), lo = mid + 1;
        else
            hi = mid - 1;
    }
    if (ans == -1)
    {
        cout<<"Just a legend\n";
        return 0;
    }
    for (int i=0;i<ans;++i)
        cout<<s[i];
    cout<<'\n';
    return 0;
}

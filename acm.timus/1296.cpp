#include <bits/stdc++.h>
using namespace std;

template<class T, class A=T>
class maximumSubarraySum
{
private:
#define uint unsigned int
#define maxx(a,b) (a)>(b)?(a):(b)
    std::vector<T>v;
public:
    maximumSubarraySum() {}
    void reserve(uint n)
    {
        v.reserve(n);
    }
    void addElement(T &x)
    {
        v.push_back(x);
    }
    void clearAll()
    {
        v.clear();
    }
    void computeMSS(A &maxSum, uint &startPos, uint &len)
    {
        if (!v.size()) return;
        A sum = 0;
        maxSum = v[0];
        startPos = 1, len = 1;
        uint beginn = 0;
        for (uint i=0;i<v.size();++i)
        {
            if (sum < 0)
                sum = v[i], beginn = i;
            else sum+=v[i];
            if (sum > maxSum || (sum == maxSum && len > i - beginn + 1))
                maxSum = sum, len = i - beginn + 1, startPos = beginn + 1;
        }
    }
};

int main()
{
    int n, x;
    maximumSubarraySum<int,long long>mss;
    cin>>n;
    if (!n)
    {
        cout<<"0\n";
        return 0;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        mss.addElement(x);
    }
    long long ans;
    unsigned int s, l;
    mss.computeMSS(ans, s, l);
    if (ans < 0) ans = 0;
    cout<<ans<<'\n';
    return 0;
}

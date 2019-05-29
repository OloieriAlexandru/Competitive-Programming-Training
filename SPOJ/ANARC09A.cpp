#include <iostream>
#include <cstring>
#define LMAX 2005

using namespace std;

char s[LMAX];
int lg;

int solve()
{
    int ret = 0;
    int sum = 0;
    for (int i=0; i<lg; ++i)
    {
        if (s[i]=='{')
        {
            sum++;
        }
        else
        {
            sum--;
        }
        if (sum<0)
        {
            sum = 1;
            ret++;
        }
    }
    ret+=(sum/2);
    return ret;
}

int main()
{
    int t = 0;
    while(cin>>s)
    {
        if (strchr(s, '-'))
        {
            break;
        }
        ++t;
        lg = strlen(s);
        for (int i=0;i<lg;++i)
        {
            while (s[i] == ' ')
            {
                strcpy(s+i, s+i+1);
                --lg;
            }
        }
        cout<<t<<". "<<solve()<<'\n';
    }
    return 0;
}

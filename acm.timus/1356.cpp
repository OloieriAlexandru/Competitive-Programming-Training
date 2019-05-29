#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
bitset<nmax>prime;
bool isPrime(int x)
{
    if ((x%2==0 && x!=2) || x==1)
        return false;
    for (int d=3;d*d<=x;d+=2)
        if (x%d == 0) return false;
    return true;
}
void ciur()
{
    prime.set(1);
    for (int i=2;i<nmax;++i)
        if (!prime.test(i))
            for (int j=i+i;j<nmax;j+=i)
                prime.set(j);

}
int main()
{
    int t, x;
    ciur();
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&x);
        if (isPrime(x))
        {
            printf("%d\n", x);
            continue;
        }
        if (x%2)
        {
            if (isPrime(x-2))
            {
                printf("2 %d\n", x-2);
                continue;
            }
            if (isPrime(x-4))
            {
                printf("2 2 %d\n", x-4);
                continue;
            }
            printf("3 ");
            x-=3;
        }
        int alt = 0;
        for (int i=1;i<=100000;++i)
        {
            ++alt;
            --x;
            if (!prime.test(alt))
            {
                if (isPrime(x))
                {
                    printf("%d %d\n", x, alt);
                    break;
                }
            }
        }
    }
    return 0;
}
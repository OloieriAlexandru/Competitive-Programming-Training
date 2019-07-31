#include <iostream>

using namespace std;

int main()
{
    int x, y, c;
    cin>>x>>y>>c;
    if (x + y < c)
    {
        cout<<"Impossible\n";
        return 0;
    }
    if (x < y)
    {
        if (y < c)
            cout<< c - y << ' ' << y << '\n';
        else
            cout<< 0 << ' ' << c << '\n';
    }
    else
    {
        if (x < c)
            cout << x << ' ' << c - x << '\n';
        else
            cout<< c << ' ' << 0 << '\n';
    }
    return 0;
}

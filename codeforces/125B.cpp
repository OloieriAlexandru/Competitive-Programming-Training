#include <bits/stdc++.h>
using namespace std;
void printt(int h, char ch, bool closing = false)
{
    for (int i=0; i<(2*h); ++i)
        cout<<' ';
    cout<<'<';
    if (closing) cout<<'/';
    cout<<ch<<">\n";
}
char ch1, ch2, ch3, ch4;
bool next(char &ch, bool &closing)
{
    if (!(cin>>ch1)) return false;
    cin>>ch2>>ch3;
    closing = false;
    if (ch2 == '/')
    {
        cin>>ch4;
        closing = true;
        ch = ch3;
    }
    else ch = ch2;
    return true;
}
stack<pair<char,int>>st;
int main()
{
    char ch;
    bool closin;
    while (1)
    {
        if (!next(ch, closin)) break;
        if (closin)
        {
            printt(st.top().second, ch, true);
            st.pop();
        }
        else
        {
            if (st.empty())
            {
                printt(0, ch);
                st.push(make_pair(ch, 0));
            }
            else
            {
                printt(st.top().second + 1, ch);
                st.push(make_pair(ch, st.top().second + 1));
            }
        }
    }
    return 0;
}

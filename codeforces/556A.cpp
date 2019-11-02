#include <iostream>
#include <stack>
using namespace std;

int main()
{
    char ch;
    int n;
    cin>>n;
    stack<char>st;
    for (int i=1;i<=n;++i)
    {
        cin>>ch;
        if (st.empty()){
            st.push(ch);
            continue;
        }
        if (ch == '1'){
            if (st.top() == '0'){
                st.pop();
                continue;
            }
        } else {
            if (st.top() == '1'){
                st.pop();
                continue;
            }
        }
        st.push(ch);
    }
    cout<<st.size()<<'\n';
    return 0;
}

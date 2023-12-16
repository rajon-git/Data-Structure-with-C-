#include<bits/stdc++.h>
using namespace std;
int main()
{
    list <int> mylist;
    list <int> copylist;
    int test;
    cin>>test;
    for (int i=0;i<test;i++)
    {
        int pos,val;
        cin>>pos>>val;
        if(pos == 0)
        {
            mylist.push_front(val);
        }
        else if(pos == 1)
        {
            mylist.push_back(val);
        }
        else if(pos == 2)
        {
            int n=mylist.size();
            if(val<n)
            {
                auto it=next(mylist.begin(),val);
                mylist.erase(it);
            }
        }
        
        copylist.assign(mylist.begin(),mylist.end());

        copylist.reverse();
        cout << "L -> ";
        for (int x : mylist) {
            cout << x << " ";
        }
        cout << endl;
        cout << "R -> ";
        for (int x : copylist) {
            cout << x << " ";
        }
        cout << endl;

        
    }
    return 0;
}

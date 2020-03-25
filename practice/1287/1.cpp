#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll k;
        cin>>k;
        ll mx=0;
        ll maxp=0;
        ll cnta=0;
        string a;
        cin>>a;
        ll temp=k-1;
        ll cnt=0;
        while(temp>=0)
        {
            if(a[temp]=='A')
            {
                if(cnt>maxp)
                maxp=cnt;
                cnt=0;
            }
            else 
            cnt++;

            temp--;
        }

        cout<<maxp<<endl;
    }
}
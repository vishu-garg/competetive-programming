#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k1,k2;
        cin>>n>>k1>>k2;
        set<ll> p1,p2;
        for(ll i=0;i<k1;i++)
        {
            ll temp;
            cin>>temp;
            p1.insert(temp);
        }   
        for(ll i=0;i<k2;i++)
        {
            ll temp;
            cin>>temp;
            p2.insert(temp);
        }
        while(p1.size()!=0 && p2.size()!=0)
        {
            auto it1=p1.end();
            auto it2=p2.end();
            it1--;
            it2--;
            if(*it1>*it2)
            {
                p1.insert(*it2);
                p2.erase(it2);
            }

            else if(*it2>*it1)
            {
                p2.insert(*it1);
                p1.erase(it1);
            }
        }
        if(p1.size()==0)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
}
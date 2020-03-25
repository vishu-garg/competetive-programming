#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        ll maxd,maxdh;
        ll d,h;
        cin>>d>>h;
        maxd=d;
        maxdh=(d-h);
        for(ll i=1;i<n;i++)
        {
            cin>>d>>h;
            if(d>maxd)
            maxd=d;
            if(d-h>maxdh)
            maxdh=d-h;
        }
        if(x<=maxd)
        cout<<"1";
        else if(maxdh<=0)
        cout<<"-1";
        else{
        ll tmp=x-maxd;
        tmp=(tmp%maxdh==0) ? tmp/maxdh : ((tmp/maxdh)+1);
        cout<<tmp+1;}
        cout<<endl;
    }
}
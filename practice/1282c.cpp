#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,T,a,b;
        cin>>n>>T>>a>>b;
        ll lev[n];
        for(ll i=0;i<n;i++)
        cin>>lev[i];
        ll t[n];
        for(ll i=0;i<n;i++)
        cin>>t[i];
        vector<pair<ll, ll> > v(n);
        for(ll i=0;i<n;i++)
        v[i]=make_pair(t[i],lev[i]);
        sort(v.begin(),v.end());
        if(v[0].second==0)
        v[0].second=a;
        else
        v[0].second=b;
        for(ll i= 1;i<n;i++)
        {
            if(v[i].second==0)
            v[i].second=a+v[i-1].second;
            else
            v[i].second=b+v[i-1].second;
        }
        ll ans=0,ext,scr=0;
        if(v[n-1].second<=T)
        cout<<n<<"\n";
        else if(v[0].second>T){
        ll scr2=(v[0].first-1)/a;
                if (scr2<0) {cout<<0<<endl;}
                else 
                cout<<scr2<<endl;}
        else
        {
            ll i=n-1;
            while(ans!=1)
            {
            while(v[i].second>T)
            i--;

            if(v[i+1].first<=v[i].second)
            {
                if(i==0){
                ll scr3=(v[i].first-1)/a;
                if (scr3<0) {cout<<0<<endl;}
                else
                cout<<scr3<<endl;
                ans=1;
                }
                else
                {
                    T=v[i+1].first - 1;
                }
            }
            else
            {
                if(i+1<0)
                cout<<"0"<<"\n";
                else
                cout<<i+1<<endl;
                ans=1;
            }
            }
        }
        
    }
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<ll>l,r;
    ll mn=LLONG_MAX, mx=-LLONG_MAX;
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        l.push_back(x);
        r.push_back(y);
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    // cout<<mn<<" "<<mx<<"<---"endl;
    
    for(int i=0;i<m;i++)
    {
        ll pnt;
        cin>>pnt;
        ll ans=0;
        if(lower_bound(l.begin(),l.end(),pnt+1)==l.end()){ans+=n;}
        else 
        {
            ans+=(lower_bound(l.begin(),l.end(),pnt+1))-(l.begin());
        }
        
        if(lower_bound(r.begin(),r.end(),pnt)==r.end())ans-=n;
        else 
        ans-=(lower_bound(r.begin(),r.end(),pnt)-r.begin());
        cout<<ans<<" ";
    }
    return 0;

}
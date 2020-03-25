#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll> > adj(100005);

long double ans(ll s,int prev)
{
    ll k=adj[s].size()-1;
    if(s==1)k++;
    if(k==0){
    // cout<<0<<" <--"<<" s= "<<s<<endl;
    return 0;}
    long double ansr=0;
    for(ll i=0;i<adj[s].size();i++)
    {
        if(adj[s][i]!=prev)
        ansr+=ans(adj[s][i],s);
    }
    ansr=ansr/k;
    ansr+=1;
    // cout<<ansr<<" <--"<<" s= "<<s<<endl;
    return ansr;
}


int main()
{
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<fixed<<setprecision(15)<<0;
        return 0;
    }
    for(ll i=1;i<n;i++)
    {
        ll c1,c2;
        cin>>c1>>c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
    cout<<fixed<<setprecision(15)<<ans(1,0);
    
}
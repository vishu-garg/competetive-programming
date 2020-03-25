#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> x(n);
    for(ll i=0;i<n;i++)
    cin>>x[i];
    queue<ll> q;
    map<ll,ll> d;
    for(ll i=0;i<n;i++)
    {
        d[x[i]]=0;
        q.push(x[i]);
    }
    ll ans=0;
    vector<ll> reslt;
    while(!q.empty())
    {
        if(reslt.size()==m) break;
        ll cur=q.front();
        q.pop();
        if(d[cur]!=0)
        {
            reslt.push_back(cur);
            ans=ans+d[cur];
        }
        if(d.count(cur-1)==0)
        {
            q.push(cur-1);
            d[cur-1]=d[cur]+1;
        }
        if(d.count(cur+1)==0)
        {
            q.push(cur+1);
            d[cur+1]=d[cur]+1;
        }
    }
    cout<<ans<<endl;
    for(ll i=0;i<reslt.size();i++)
    cout<<reslt[i]<<" ";
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,c[10000],res[10000];
vector<ll>v[10000];
vector<ll> q;

ll dfs(ll pos)
{
    ll ret=1;
    if(pos==0)
    ret=0;

    for(ll i=0;i<v[pos].size();i++)
    ret+=dfs(v[pos][i]);

    if(pos!=0)
    {
        if(c[pos]>=ret)
        {
            cout<<"NO"<<endl;
            exit(0);
        }
        q.insert(q.begin()+c[pos],pos);
    }
    return ret;
}

int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        cin>>c[i];
        v[x].push_back(i);
    }
    ll temp=dfs(0);

    for(ll i=0;i<q.size();i++)
    res[q[i]]=i+1;

    cout<<"YES"<<endl;
    for(ll i=1;i<=n;i++)
    cout<<res[i]<<" ";
}
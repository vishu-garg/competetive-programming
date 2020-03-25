#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll f[n],in[n]={0},out[n]={0};
    for(ll i=0;i<n;i++)
    {
        cin>>f[i];
        f[i]=f[i]-1;
        if(f[i]!=-1)
        {
            out[i]=1;
            in[f[i]]=1;
        }
    }
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        if(in[i]==0 && out[i]==0 )
        v.push_back(i);
    }
    
    if(v.size()==1)
    {
        for(ll i=0;i<n;i++)
        {
            if(in[i]==0 && i!=v[0])
            {
                f[v[0]]=i;
                in[i]=1;
                out[v[0]]=1;
            }
        }
    }
    else if(v.size()>1)
    { 
        ll siz=v.size();
        for(ll i=0;i<v.size();i++)
        {

            f[v[i]]=v[(i+1)%siz];
            out[v[i]]=1;
            in[v[(i+1)%siz]]=1;
        }
    }
    v.clear();

    vector<ll> rem_out,rem_in;
    for(ll i=0;i<n;i++)
    {
        if(out[i]==0)
        rem_out.push_back(i);
        if(in[i]==0)
        rem_in.push_back(i);
    }
    for(ll i=0;i<rem_in.size();i++)
    {
        f[rem_out[i]]=rem_in[i];
    }
    for(ll i=0;i<n;i++)
    {
        cout<<f[i]+1<<" ";
    }
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll dis[n],adj[n][n],path[n];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            cin>>adj[i][j];
        }
        ll src,gl;
        cin>>src>>gl;
        path[src]=-1;
        dis[src]=0;
        for(ll i=1;i<n;i++)
        {    
        dis[i]=INFINITY;
        path[i]=i;
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(adj[i][j]!=0)
                {
                    if((dis[i]+adj[i][j])<dis[j])
                    {
                      
                        dis[j]=dis[i]+adj[i][j];
                        path[j]=i;
                    }
                }
            }
        }
        vector<ll> v;
        cout<<dis[gl]<<endl;
        ll i=gl;
        while(i!=-1)
        {
            v.push_back(i);
            i=path[i];
        }
        reverse(v.begin(),v.end());
        for(ll i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        cout<<endl;
    }
}
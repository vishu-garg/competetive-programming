#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,h;
    cin>>n>>m>>h;
    ll a[m],b[n],t[n][m],arr[n][m];
    for(ll i=0;i<m;i++)
    cin>>a[i];
    for(ll i=0;i<n;i++)
    cin>>b[i];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        cin>>t[i][j];
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(t[i][j])
            arr[i][j]=min(b[i],a[j]);
            else 
            arr[i][j]=0;

             cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
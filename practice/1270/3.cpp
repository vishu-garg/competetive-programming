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
        ll a[n],S,X;
        cin>>a[0];
        S=a[0];
        X=a[0];
        for(ll i=1;i<n;i++){
        cin>>a[i];
        S=S+a[i];
        X=X^a[i];}
        cout<<"2"<<endl;
        cout<<X<<" "<<S+X<<endl;
      }
}
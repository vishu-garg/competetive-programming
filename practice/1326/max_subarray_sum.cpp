#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll a1=a[0],a2=a[0];
    for(int i=1;i<n;i++)
    {
        ll temp = a1+a[i];
        if(temp<=0)
        {
            a2=max(a2,max(temp,a[i]));
            a1=0;
        }
        else 
        {
            a1=temp;
            a2=max(a2,max(a1,a[i]));
        }
    }
    cout<<a2<<endl;
}


// This is in O1 space

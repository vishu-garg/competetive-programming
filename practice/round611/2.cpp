#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll ans=((n/k)*k)+(k/2);
        if(n-((n/k)*k)>(k/2))
        cout<<ans<<endl;
        else 
        cout<<n<<endl;
    }
}
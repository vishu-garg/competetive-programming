#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
 
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fb(i,a,b) for(ll i=a;i>=b;i--)
 
#define mp make_pair
#define pb push_back
 
#define ft first
#define sd second
 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V> 
 
const ll N = 100005;
const ll M = 1000000007;
 
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,d;
        cin>>n>>d;
        ll x=sqrt(d);
        x=x-1;
        
        double tmp=double();
        cout<<tmp<<endl;
        ll mnd=ceil(tmp);
        mnd+=x;
        if(mnd<=n)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
}
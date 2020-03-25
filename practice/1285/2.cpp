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
    ll n;
    cin>>n;
    ll cc[n],a[n];
    S s;
    ll max_sum;
    f(i,0,n){
        cin>>a[i];
    }
    ll pref[n],suf[n];
    pref[0]=a[0];
    suf[0]=a[n-1];
    f(i,1,n)
    pref[i]=a[i]+pref[i-1];

    f(i,1,n)
    suf[i]=suf[i-1]+a[n-i-1];
    ll ans=0;
    f(i,0,n)
    {
        if(pref[i]<=0 || suf[i]<=0)
        {
            ans=1;
            cout<<"NO"<<endl;
            i=n;
        }
    }
    if(ans==0)
    cout<<"YES"<<endl;  
}

}
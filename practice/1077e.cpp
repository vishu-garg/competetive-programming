#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int pow1(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=res*a;
		}
        a=a*a;
        b>>=1;
    }
    return res;
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        rep(i,0,n)cin>>v[i];
        map<ll,ll>mp;
        rep(i,0,n)mp[v[i]]++;
        v.clear();
        for(auto it: mp)v.pb(it.second);
        sort(all(v));
        // bool ok=true;
        ll ans=v.back();
        ll mn=ans/2;
        ll i=(ll)v.size()-2;
        ll q=2;
        // cout<<v.size();
        // err1(i);
        while(i>=0)
        {
            // cout<<i<<" "<<mn<<" "<<v[i]<<endl;
            mn=min(v[i],mn);
            if(mn==0)
            {
                break;
            }
            else
            {
                ll tmp=(((ll)(pow)(2,q))-1ll)*mn;
                ans=max(ans,tmp);
                i--;
                q++;
                mn/=2;
            }
        }
        cout<<ans<<endl;
    }

}
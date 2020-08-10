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
        rep(i,0,n)
        cin>>v[i];
        map<ll,ll> mp;
        vector<ll>pref(n,0);
        rep(i,0,n)
        {
            if(mp[v[i]]==0)pref[i]=1;
            mp[v[i]]++;
        }
        rep(i,1,n)pref[i]+=pref[i-1];
        ll ans=n-1;
        if(pref[n-1]==n)
        {
            cout<<"0";
            return 0;
        }
        // rep(i,0,n)
        // cout<<suff[i]<<" <---"<<endl;
        mp.clear();
        ll a3=0;
        repb(r,n-1,0)
        {
            // cout<<mp[v[r]]<<"<--"<<endl;
            if(mp[v[r]]!=0)break;
            a3++;
            mp[v[r]]++;
        }
        ans=min(ans,n-a3);
        // cout<<ans<<endl;
        // cout<<ans<<"<--"<<endl;
        rep(l,0,n)
        {
            if(pref[l]!=l+1)
            continue;
            // cout<<l<<endl;
            map<ll,ll> mp1;
            rep(i,0,l+1)
            mp1[v[i]]++;
            ll ans2=l+1;
            repb(r,n-1,l+1)
            {
                // cout<<v[r]<<"<--"<<mp1[v[r]]<<endl;
                if(mp1[v[r]]!=0)
                {
                    break;
                }
                ans2++;
                mp1[v[r]]++;
            }
            // cout<<l<<" "<<ans2<<endl;
            ans=min(ans,n-ans2);
        }
        cout<<ans<<endl;
    }
}
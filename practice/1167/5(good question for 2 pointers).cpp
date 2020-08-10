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
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        ll pref[n],a[n];
        vector<ll> pos[x+1];
        rep(i,0,n)
        {
            cin>>a[i];
            pos[a[i]].pb(i);
            pref[i]=a[i];
            if(i>0)
            pref[i]=max(pref[i],pref[i-1]);
        }
        ll lst=n+5;
        ll p=1;
        repb(i,x,1)
        {
            if(pos[i].empty())
            {
                p=i;
                continue;
            }
            if(pos[i].back()>lst)break;
            p=i;
            lst=pos[i][0];
        }
        lst=-1;
        ll ans=0;
        for(ll l=1;l<=x;l++)
        {
            ll r=max(l,p-1);
            if(lst!=-1) // the last pos of number <=l-1
            r=max(r,pref[lst]);
            ans+=(x-r+1);
            if(!pos[l].empty())
            {
                if(pos[l][0]<lst)
                break;
                lst=pos[l].back();
            }
        }
        cout<<ans;
    }
}
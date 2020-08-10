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

struct lex_compare {
    bool operator() (const pair<ll,pll>& lhs, const pair<ll,pll>& rhs) const {
        if(lhs.first!=rhs.first)return lhs.first>rhs.first;
        return lhs.second.first<rhs.second.first;
    }
};

// vector<ll>vec;
int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n+1,0);
        set<pair<ll,pll>,lex_compare >s;
        s.insert({n,{1,n}});
        rep(i,1,n+1)
        {
            auto it=*s.begin();
            s.erase(it);
            ll len=it.first;
            ll l=it.second.first;
            ll r=it.second.second;
            ll ind;
            if(len%2==0)
            {
                ind=(r+l-1)/2;
                v[ind]=i;
                ll r1=ind-1;
                ll l2=ind+1;
                if(r1>=l)
                s.insert({r1-l+1,{l,r1}});
                if(l2<=r)
                s.insert({r-l2+1,{l2,r}});
            }
            else 
            {
                ind=(r+l)/2;
                v[ind]=i;
                ll r1=ind-1;
                ll l2=ind+1;
                if(r1>=l)
                s.insert({r1-l+1,{l,r1}});
                if(l2<=r)
                s.insert({r-l2+1,{l2,r}});
            }
        }

        rep(i,1,n+1)
        cout<<v[i]<<" ";
        cout<<endl;
        
    }

}
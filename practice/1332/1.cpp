#include<bits/stdc++.h>
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
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e9+7;
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
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll mh=min(a,b);
        ll mv=min(c,d);
        ll x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        if(x1==x2 && (a!=0 || b!=0))
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(y1==y2 && (c!=0 || d!=0))
        {
            cout<<"NO"<<endl;
            continue;
        }
        a-=mh;
        b-=mh;
        c-=mv;
        d-=mv;
        if(a>0)
        {
            if(a>(x-x1))
            {
                cout<<"NO"<<endl;
                continue;
            }
        }
        if(b>0)
        {
            if(b>(x2-x))
            {
                cout<<"NO"<<endl;
                continue;
            }
        }
        if(c>0)
        {
            if(c>(y-y1))
            {
                cout<<"NO"<<endl;
                continue;
            }
        }
        if(d>0)
        {
            if(d>(y2-y))
            {
                cout<<"NO"<<endl;
                continue;
            }
        }
        cout<<"YES"<<endl;
    }
}
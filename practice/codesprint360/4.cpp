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
//    cin>>t;
    while(t--)
    {
        ll p;
        cin>>p;
        ll n1;
        ll rem=0;
        ll gne=0,req=0;
        ll a1[n1],d1[n1];
        rep(i,0,n1)
        {cin>>a1[i];gne+=a1[i];}
        rep(i,0,n1)
        {cin>>d1[i];req+=d1[i];}
        if(req>p)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        rem=p-gne;
        req=0;
        ll n2;
        cin>>n2;
        ll a2[n2],d2[n2];
        rep(i,0,n2)
        cin>>a2[i];
        rep(i,0,n2)
        {
            cin>>d2[i];
            req+=d2[i];
        }
        if(rem<req)
        {
            cout<<"NO"
            return 0;
        }

        cout<<"YES";

    }

}
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

int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n)
    cin>>a[i];
    sort(a.begin(),a.end());
    ll mn=-100000,mn2=100000,f1=0,f2=0;
    ll s_pstv=0;
    rep(i,0,n){
    if(a[i]>=0){
    if(a[i]%2!=0){f1=1;
    mn2=min(a[i],mn2);}
    s_pstv+=a[i];}
    else {
//    {cout<<"___________"<<a[i]<<" "<<a[i]%2;
	if(a[i]%2!=0){
    f2=1;
    mn=max(mn,a[i]);}}
}
    if(s_pstv%2!=0){
	    cout<<s_pstv;return 0;}
    ll a1=s_pstv,a2=s_pstv;
    if(f2==1)
    {
//    	cout<<mn<<endl;
        a1=s_pstv+mn;
    }
    if(f1==1)
    {
//    	cout<<mn2<<endl;
        a2=s_pstv-mn2;
    }
    if(f1==1 && f2==1)
    cout<<max(a1,a2);
    else 
    {
    	if(f1==1)
    	cout<<a2;
    	else 
    	cout<<a1;
	}
}
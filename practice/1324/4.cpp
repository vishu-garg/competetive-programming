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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    ll n;
    cin>>n;
    ll a[n],b[n];
    vector<ll>arr_i(n),arr_j(n);
    rep(i,0,n)
    cin>>a[i];
    rep(i,0,n)
    cin>>b[i];
    rep(i,0,n)
    {
        arr_i[i]=a[i]-b[i];
    }
    rep(i,0,n)
    {
        arr_j[i]=b[i]-a[i];
    }
    sort(arr_i.begin(),arr_i.end());
    ll ans=0;
    rep(i,0,n)
    {
        ll tmp=0;
        tmp=upper_bound(arr_i.begin(),arr_i.end(),arr_j[i])-arr_i.begin();
        tmp=n-tmp;
        if(arr_j[i]<0)
        tmp--;
        ans+=tmp;
    }
    cout<<(ans/2);
}
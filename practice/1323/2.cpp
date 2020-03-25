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
    string s;
    cin>>n>>s;
    ll ob=0,cb=0;
    vector<char> v;
    rep(i,0,n)
    {
        if(s[i]==')')cb++;
        else ob++;
        if(cb>ob)
        v.pb(')');
        else if(ob>cb)
        v.pb('(');
        else 
        v.pb('.');
    }
//    rep(i,0,n)
//    cout<<v[i]<<" ";
    ll ans=0;
    if(v[n-1]!='.')
    {
        cout<<"-1"<<endl;
        return 0;
    }
    ll k=0;
    while(k<n)
    {
        if(v[k]==')')
        {
            while(v[k]!='.')
            {
                ans++;k++;
            }
            ans++;
        }
        k++;
    }
    cout<<ans<<endl;
}
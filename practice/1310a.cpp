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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    rep(i,0,n)
    cin>>a[i];
    vector<ll> t(n+1);
    rep(i,0,n)
    cin>>t[i];
    t[n]=0;a[n]=1e10;
    ++n;
    vector<ll> ord(n);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](ll i,ll j){
        return a[i]<a[j];
    });
    ll ans=0;
    ll last=0;
    multiset<ll> s;
    ll sum=0;
    for(auto i : ord)
    {
        while(a[i]>last && !s.empty()){
            ++last;
            auto it=prev(s.end());
            // cout<<last-1<<" "<<*it<<endl;
            sum-=*it;
            s.erase(it);
            ans+=sum;
        }
        last=a[i];
        s.insert(t[i]);
        sum+=t[i];
    }
    cout<<ans;
}
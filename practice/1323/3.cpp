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

vector<ll> gao(vector<int> a)
{
    int n=a.size();
    vector<ll> res(n+1);
    int i=0;
    while(i<n){
        if(a[i]==0){
            i++;
            continue;
        }

        int j=i;
        while(j<n && a[j]==1){
            j++;
        }
        for(int len=1;len<=j-i;len++){
            res[len]+=j-i-len+1;
        }
        i=j;
    }
    return res;
}

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),b(m);
    rep(i,0,n)
    cin>>a[i];
    rep(i,0,m)
    cin>>b[i];

    auto ga = gao(a);
    auto gb = gao(b);
    ll ans=0;
    for(int i=1;i<ga.size();i++){
        if(k%i==0 && (k/i)<=m)
        {
            ans+=(ga[i]*gb[k/i]);
        }
    }

    cout<<ans<<endl;

return 0;
}
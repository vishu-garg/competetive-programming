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

ll mx=100005;
vector<ll> v;

void SieveOfEratosthenes(ll n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers
    v.pb(0);v.pb(0); 
    ll lst;
    for (ll p=2; p<=n; p++) 
       {if (prime[p]) 
          {v.pb(p);lst=p;}
        else 
        v.pb(lst);}
} 

int main()
{
    // ll t=1;
    SieveOfEratosthenes(mx);
    ll n;cin>>n;
    ll a[n];
    map<ll,ll> mp;
    ll c[n];
    rep(i,0,n){
    cin>>a[i];c[i]=a[i];mp[a[i]]=i;}
    sort(c,c+n);

    vector<pair<ll,ll> > p;
    

    rep(i,0,n)
    {
        ll j=mp[c[i]];
        while(j!=i){
        ll pr=v[j-i+1];
        p.pb({j-pr+1,j});
        swap(mp[a[j-pr+1]],mp[a[j]]);
        swap(a[j-pr+1],a[j]);
        j=j-pr+1;
        }
    }

    
    
    cout<<p.size()<<endl;
    rep(i,0,p.size())
    cout<<p[i].first+1<<" "<<p[i].second+1<<endl;
}
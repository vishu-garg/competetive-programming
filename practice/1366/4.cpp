#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll int
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
const ll N=100005;
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

// struct segtree{
//     ll x,y;
//     ll tree[4*N];

//     void build_tree(vector<ll>&v , ll ind,ll l, ll r)
//     {
//         if(l==r)
//         {
//             tree[ind]=v[l];
//             return;
//         }
//         ll mid=(l+r)/2;
//         build_tree(v,2*ind,l,mid);
//         build_tree(v,2*ind+1,mid+1,r);
//         tree[ind]=max(tree[2*ind],tree[2*ind+1]);
//     }

//     ll query(ll ind, ll l, ll r)
//     {
//         // cout<<l<<" "<<r<<" "<<endl;
//         if(x>r || y<l)return -LLONG_MAX;
//         if(l>=x && r<=y)return tree[ind];
//         ll mid=(l+r)/2;
//         return max(query(2*ind,l,mid),query(2*ind+1,mid+1,r));
//     }
// }obj;

// bool isPrime(ll n) 
// { 
//     // Corner cases 
//     if (n <= 1) 
//         return false; 
//     if (n <= 3) 
//         return true; 
  
//     // This is checked so that we can skip 
//     // middle five numbers in below loop 
//     if (n % 2 == 0 || n % 3 == 0) 
//         return false; 
  
//     for (ll i = 5; i * i <= n; i = i + 6) 
//         if (n % i == 0 || n % (i + 2) == 0) 
//             return false; 
  
//     return true; 
// } 

vector<ll>least_prime(10000001);

void leastPrimeFactor(ll n=10000000) 
{ 
    // Create a vector to store least primes. 
    // Initialize all entries as 0. 
    // vector<int> least_prime(n+1, 0); 
  
    // We need to print 1 for 1. 
    least_prime[1] = 1; 
  
    for (ll i = 2; i <= n; i++) 
    { 
        // least_prime[i] == 0 
        // means it i is prime 
        if (least_prime[i] == 0) 
        { 
            // marking the prime number 
            // as its own lpf 
            least_prime[i] = i; 
  
            // mark it as a divisor for all its 
            // multiples if not already marked 
            for (ll j = 2*i; j <= n; j += i) 
                if (least_prime[j] == 0) 
                   least_prime[j] = i; 
        } 
    } 
  
    // print least prime factor of 
    // of numbers till n 
} 


int main()
{
    leastPrimeFactor();
    // fast;
    ll T=1;
    cin>>T;
    vector<ll>v1,v2;
    while(T--)
    {
        ll n;
        cin>>n;
        // ll cnt=0;
        ll ans=least_prime[n];
        if(n==ans)
        {
            v1.pb(-1);
            v2.pb(-1);
            continue;
        }
        ll tmp=n;
        while(tmp%ans==0)
        tmp/=ans;
        if(tmp==1)
        {
            v1.pb(-1);
            v2.pb(-1);
            continue;
        }
        else 
        {
            v1.pb(ans);
            v2.pb(tmp);
        }
    }

    for(auto it:v1)cout<<it<<" ";
    cout<<endl;
    for(auto it:v2)cout<<it<<" ";
    cout<<endl;
}
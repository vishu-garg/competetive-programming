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
const ll N=100005;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll pow1(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
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

int main()
{
    fast;

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        V a(n+1);
        rep(i,0,n)
        cin>>a[i];
        // n+=1;
        // a[n-1]=0;
        ll mx=-1;
        ll sum1=0,sum2=0;
        ll ind=0;
        while(ind<n)
        {
            if(ind==0)
            {
                ll k1=(ind+1)%n;
                ll k2=(ind-1+n)%n;
                while(k1!=0)
                {
                    sum1+=a[k1];
                    k1=(k1+2)%n;
                }
                while(k2!=0)
                {
                    sum2+=a[k2];
                    k2=(k2-2)%n;
                }
                // err3(a[ind],sum1,sum2);
                ll ans1=sum1+a[0];
                ll ans2=sum2+a[0];
                mx=max(mx,ans1);
                mx=max(mx,ans2);
                ind++;
            }
            else 
            {
                // err2(sum1,sum2);
                ll sum3=sum1;
                sum1=sum2;
                sum2=sum3-a[ind]+a[(ind-1+n)%n];
                // err3(a[ind],sum1,sum2);
                ll ans1=sum1+a[ind];
                ll ans2=sum2+a[ind];
                mx=max(mx,ans1);
                mx=max(mx,ans2);
                ind++;
            }
        }
        cout<<mx<<endl;
    }

}
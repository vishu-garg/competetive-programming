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
        string s;
        cin>>s;

        V a;
        ll n=s.length();
        rep(i,0,n)
        {
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y')
            {
                a.pb(1);
            }
            else 
            a.pb(0);
        }
        
        rep(i,1,n)
        a[i]+=a[i-1];

        // errA(a);

        ll lmt=(n)/2;

        ld ans=0;
        ll sum=0;

        vector<ll>tmp;

        ll k=lmt;
        if(n%2==0)k-=1;

        rep(i,0,n)
        {
            if(i==0)
            {
                sum=a[n-1];
                tmp.pb(sum);
                ans+=(sum);
            }
            else if(i<=lmt)
            {
                // err2(n-i-1,i-1);
                // if(n-i-1<i-1)
                // continue;
                sum+=(a[n-i-1]-a[i-1]);
                // err2(sum,i+1);
                if(i!=lmt)
                if(n%2!=0)
                tmp.pb(sum);
                else if(i!=lmt-1)
                tmp.pb(sum);
                ans+=(ld)(sum)/(ld)(i+1);
            }
            else 
            {
                // err1(k-1);
                sum=tmp[k-1];
                // err2(sum,i+1);
                k--;
                ans+=(ld)(sum)/(ld)(i+1);
            }
        }

        cout<<fixed<<setprecision(10)<<ans;

    }

}
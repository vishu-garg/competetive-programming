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
ll pow1(ll a,ll b , ll mod){
    ll res=1;
    while(b>0){
        if(b&1){
        	res=(res*a)%mod;
		}
        a=(a*a)%mod;
        b>>=1;
    }
    return res%mod;
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
    ll T=1;
//     cin>>T;
    while(T--)
    {
        string num;
        cin>>num;
        ll a, b;
        cin>>a>>b;
        ll n=num.length();
        ll arr[n],arr2[n];
        ll cur=0;
        rep(i,0,n)
        {
            ll dig=num[i]-'0';
            arr[i]=(((cur*10)%a)+(dig%a))%a;
           cur=arr[i]; 
        //    cout<<cur<<endl;
        }
        cur=0;
        ll dis=0;
        repb(i,n-1,0)
        {
            ll dig=num[i]-'0';
            ll val1=pow1(10,dis,b);
            val1=(val1*dig)%b;
            val1=(cur+val1)%b;
            arr2[i]=val1;
            cur=val1;
            dis++;
        }

        // rep(i,0,n)
        // cout<<arr[i]<<" , ";
        // cout<<endl;

        repb(i,n-1,1)
        {
            if(arr2[i]==0 && num[i]!='0' && arr[i-1]==0)
            {
                cout<<"YES"<<endl;
                cout<<num.substr(0,i)<<endl;
                cout<<num.substr(i)<<endl;
                return 0;
            }
        }
        cout<<"NO"<<endl;
    }

}
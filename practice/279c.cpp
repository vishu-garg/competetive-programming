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

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,q;
        cin>>n>>q;
        ll a[n];
        rep(i,0,n)
        cin>>a[i];

        ll a2[n];
        ll a3[n];

        a2[0]=0;
        rep(i,1,n)
        {
            if(a[i]==a[i-1])a2[i]=0;
            else if(a[i]>a[i-1])a2[i]=1;
            else a2[i]=-1;
        }

        // rep(i,0,n)
        // cout<<a2[i]<<" "<<endl;

        ll l_1=-1,l1=-1,l0=0;
        a3[0]=0;
        
        rep(i,1,n)
        {
           if(a2[i]==1)
           {
               if(l1>l_1)
               a3[i]=a3[i-1];
               else if(l0>l_1)
               a3[i]=l0-1;
               else 
               a3[i]=i-1;
               l1=i;
               l0=-1;
           }
           else if(a2[i]==0)
           {
               a3[i]=a3[i-1];
               if(l0==-1)l0=i;
           }
           else if(a2[i]==-1)
           {
               a3[i]=a3[i-1];
               l_1=i;
               l0=-1;
           }
        }


        // rep()

        // rep(i,0,n)cout<<a3[i]<<" , ";
        // cout<<endl;

        while(q--)
        {
            ll st,en;
            cin>>st>>en;
            st--;
            en--;
            if(st>=a3[en] && st<=en)
            {
                cout<<"Yes"<<endl;
            }
            else 
            {
                cout<<"No"<<endl;
            }
        }

    }

}
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
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        V a(n);
        rep(i,0,n)
        cin>>a[i];

        if(n==1)
        {
            cout<<a[0]<<endl;
            continue;
        }

        V o(n,0),e(n,0);

        rep(i,0,n)
        {
            if(i!=0){
            o[i]+=o[i-1];
            e[i]+=e[i-1];}
            if(i%2==0)
            {
                e[i]+=a[i];
            }
            else 
            {
                o[i]+=a[i];
            }
        }

        ll ans=0;

        rep(i,0,n)
        {
            if(i%2==0)
            ans+=a[i];
        }

        // err1(ans)<<endl;
        // cout<<ans<<endl;


        ll i=0;
        multiset<ll>m1,m2;
        m1.insert(0);
        m2.insert(0);

        // errA(o);
        // errA(e);
        ll tmp4=ans;
        while(i<n)
        {   
            ll t1;
            if(i%2==0)
            {
                t1=*m2.begin();
            }
            else 
            {
                t1=*m1.begin();
            }
            // err2(i,t1)<<endl;
            t1=(o[i]-e[i])-(t1);
            // err2(i,t1)<<endl;
            ans=max(ans,tmp4+t1);
            if(i%2)
            m1.insert(o[i]-e[i]);
            else 
            m2.insert(o[i]-e[i]);
            i++;
        }

        cout<<ans<<endl;



    }

}
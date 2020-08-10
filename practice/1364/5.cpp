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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

ll query(ll a, ll b)
{
    cout<<"? "<<a<<" "<<b<<endl;
    ll num;
    cin>>num;
    return num;
}

int main()
{
    // fast;

    //#ifndef ONLINE_JUDGE
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    //#endif
    
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        V qp(n+1);
        rep(i,1,n+1)
        qp[i]=i;

        shuffle((qp.begin()+1),qp.end(),rng);

        ll a=qp[1],b=qp[2];
        ll num1=query(a,b);
        for(int i=3;i<=n;i++)
        {
            ll c=qp[i];
            ll num2=query(b,c);
            // err3(a,b,c);
            if(num1<num2)
            {
                continue;
            }
            else if(num1>num2)
            {
                num1=num2;
                a=b;
                b=c;
                continue;
            }
            else 
            {
                b=c;
                num1=query(a,c);
                continue;
            }
        }
        ll zero_wala=-1;
        while(true)
        {
            ll i=uniform_int_distribution<int>(1,n)(rng);
            if(i==a || i==b)continue;
            ll num1=query(a,i);
            ll num2=query(b,i);
            if(num1<num2)
            {
                zero_wala=a;
                break;
            }
            else if(num1>num2)
            {
                zero_wala=b;
                break;
            }
        }
        V ans(n);
        rep(i,0,n)
        {
            if(i+1==zero_wala)
            ans[i]=0;
            else 
            ans[i]=query(i+1,zero_wala);
        }

        rep(i,0,n)
        {
            if(i==0)
            cout<<"! ";
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return 0;
    }

}

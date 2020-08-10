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

ll calc(ll n,ll k)
{
    
    ll ans=LLONG_MAX;
    ll st=-1;
    ll flg=0;
    // err();
    rep(i,0,10)
    {
        V a;
        rep(j,0,k+1)
        {
            // cout<<j<<"<---"<<endl;
            a.pb((j+i)%10);
        }
        // errA(a);
        ll sum=0;
        rep(j,0,k+1)
        sum+=a[j];

        // err1(sum)<<endl;

        if(n-sum<0)
        {
            continue;
        }

        ll tmp=-1;
        rep(j,0,k+1)
        {
            if(a[j]==0 && j!=0)
            {
                tmp=(k+1-j);
                break;
            }
        }

        // err1(tmp);

        // ll t2=0;

        ll tmp3=(n-sum);
        // err1(tmp3)<<endl;
        if(tmp!=-1)
        {
            tmp3-=tmp;
        }
        // err1(tmp3)<<endl;
        if(tmp3<0 || tmp3%(k+1)!=0)
        {
            continue;
        }
        // err();
        tmp3/=(k+1);
        // err1(tmp3)<<endl;
        ll ans2=0;
        if(tmp3%9!=0)ans2+=(tmp3%9);
        
        ll c2=tmp3/9;

        rep(i,0,c2)
        {
            ans2=(ans2*10)+9;
        }
        // err()
        // err1(tmp3)<<endl;
        // err();
        if(ans2%10==9 && tmp!=-1)
        {
            ll k1=ans2;
            ll k2=0;
            if(tmp3%9!=0)
            {
                if((tmp3%9)+1<10)
                ans2=(tmp3%9)+1;
                else 
                ans2=19;
            }
            else 
            ans2=1;
            rep(i,0,c2-1)
            {
                ans2=(ans2*10)+9;
            }
            ans2=(ans2*10)+8;

        }
        // else 
        ans2=(ans2*10)+a[0];
        // err1(ans2)<<endl;
        flg=1;
        ans=min(ans,ans2);

    }

    if(flg==0)
    return -1;
    else 
    return ans;
    
}

int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {   
        ll n,k;
        cin>>n>>k;
        cout<<calc(n,k)<<endl;
    }

}
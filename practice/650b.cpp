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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,a,b,t;
        cin>>n>>a>>b>>t;

        string s;
        cin>>s;


        ll dp_right[n+1];

        dp_right[1]=1;
        if(s[0]=='w')dp_right[1]+=b;

        if(dp_right[1]>t)
        {
            cout<<"0"<<endl;
            continue;
        }

        rep(i,2,n+1)
        {
            dp_right[i]=1+a+dp_right[i-1];
            if(s[i-1]=='w')dp_right[i]+=b;
        }

        ll dp_left[n+1];

        repb(i,n,1)
        {
            if(i!=n)
            dp_left[i]=dp_left[i+1]+a+1;
            else 
            dp_left[i]=a+1;

            if(s[i-1]=='w')dp_left[i]+=b;
        }

        ll ans=0;

        rep(i,1,n+1)
        {if(dp_right[i]<=t)ans++;
        else break;}

        // err1(ans);



        ll i=1;ll lft=n;
        ll ans2=0;
        while(lft>i)
        {
           ll tme=dp_right[i]+dp_left[lft];

            if(tme>t)break;

            ans2=(n+1)-lft+i;

            lft--;
        }
        i++;
        while(i<=n)
        {

            while(lft<=i)
            lft++;

            if(lft>n)break;

            ll tme3=dp_right[i]+dp_left[lft]+(min(i-1,n+1-lft)*a);

            while(lft<=n && tme3>t)
            {
                lft++;
                tme3=dp_right[i]+dp_left[lft]+(min(i-1,n+1-lft)*a);
            }

            if(lft>n)
            break;

            ll ans3=(n+1-lft+i);

            ans2=max(ans2,ans3);

            i++;
        }

        ans=max(ans,ans2);

        cout<<ans<<endl;



    }
}
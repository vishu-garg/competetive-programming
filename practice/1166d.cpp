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
        ll a,b,m;
        cin>>a>>b>>m;
        if(a==b)
        {
            cout<<"1 "<<a<<endl;
            continue;
        }
        else
        {
            ll fnd=-1,n=2;
            ll num1=(ll)pow(2,n-2)*(a+1);
            ll num2=(ll)pow(2,n-2)*(a+m);
            while(true)
            {
                // cout<<n<<endl;
                // cout<<num1<<" "<<num2<<endl;
                if(num1<=b && b<=num2)
                {
                    fnd=n;
                    break;
                }
                else if(num1>b)
                break;
                else 
                {
                    n++;
                    num1=(ll)pow(2,n-2)*(a+1);
                    num2=(ll)pow(2,n-2)*(a+m);
                }
            }
            // err();
            if(fnd==-1)
            {
                cout<<"-1"<<endl;
                continue;
            }
            
            ll lo=1,hi=m;
            ll k1;
            while(lo<=hi)
            {
                ll k2=(lo+hi)/2;
                // cout<<k2<<"<--"<<endl;
                ll r=(b-(ll)pow(2,n-2)*(a+k2));
                if(r<(ll)pow(2,n-2))
                {
                    // cout<<k2<<"<---"<<endl;
                    k1=k2;
                    hi=k2-1;
                }
                else
                {
                    lo=k2+1;
                }                
            }

            ll r=(b-(ll)pow(2,n-2)*(a+k1));

            V vec;
            ll tmp=0;
            while(tmp<n-2)
            {
                vec.pb(r%2);
                r/=2;
                tmp++;
            }

            reverse(all(vec));

            V ans;
            ans.pb(a);
            ll sum=a;
            rep(i,0,n-2)
            {
                ll n3=sum+(k1+vec[i]);
                ans.pb(n3);
                sum+=n3;
            }
            ans.pb(sum+k1);

            cout<<ans.size()<<" ";
            rep(i,0,n)
            cout<<ans[i]<<" ";
            cout<<endl;

        }
        
    }

}
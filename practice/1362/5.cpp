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
vector<ll>freq(1000010,0);

int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n,p;
        cin>>n>>p;
        vector<ll>a(n);
        // map<ll,ll>freq,freq2;
        rep(i,0,n){cin>>a[i];freq[a[i]]++;}
        if(p==1)
        {
            if(n%2)cout<<"1";
            else cout<<"0";
            cout<<endl;
            rep(i,0,n)
            freq[a[i]]=0;
            continue;
        }
        sort(all(a),greater<ll>());
        ll cnt=0;
        rep(i,0,n)
        {
            if(a[i]!=a[i-1]){a[cnt]=a[i];cnt++;}
        }
        n=cnt;
        ll ans=0;
        rep(i,0,n)
        {
            // if(i>0)
            if(freq[a[i]]%2==0)continue;
            ll  req=1;
            ll fnd=0;
            ll tmp=i;
            ll x=i;
            for(ll j=i+1;j<n;j++)
            {
                ll dist=a[x]-a[j];
                // cout<<dist<<"<--"<<endl;
                if(dist>20)
                {
                    break;
                }
                else 
                {
                    ll over=0;
                    for(ll k=1;k<=dist;k++)
                    {
                        if(req*p>(1e6+10))
                        {
                            over=1;
                            break;
                        }
                        else 
                        req*=p;
                    }
                    // cout<<req<<" "<<a[j]<<" "<<a[i]<<endl;
                    if(over)
                    break;
                    else if(req<=freq[a[j]])
                    {
                        fnd=1;
                        i=j-1;
                        freq[a[j]]-=req;
                        // freq2[a[j]]-=req;
                        break;
                    }
                    else 
                    {
                        // i=j;
                        req-=freq[a[j]];
                        // freq[a[j]]=0;
                        x=j;
                        // cout<<req<<endl;
                    }
                }
            }
            if(fnd==0)
            {
                ll sum=0;
                i=tmp;
                // cout<<i<<endl;
                sum=(sum+(pow1(p,a[i])))%M;
                // cout<<sum<<endl;
                i++;
                // cout<<n<<endl;
                while(i<n)
                {
                    // cout<<freq[a[i]]<<endl;

                    ll t2=(((freq[a[i]])%M)*(pow1(p,a[i])))%M;
                    sum=(sum-(t2)+M)%M;
                    // cout<<t2<<"<--"<<endl;
                    i++;
                }
                ans=sum; 
                // break;  
            }
        }
        cout<<ans<<endl;
        rep(i,0,n)
        freq[a[i]]=0;
    }

}
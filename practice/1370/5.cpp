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
    // fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s;
        cin>>t;
        V v1,v2;
        rep(i,0,n)
        {
            if(s[i]=='0' && t[i]=='1')
            v1.pb(i);
            else if(s[i]=='1' && t[i]=='0')
            v2.pb(i);
        }
        if(v1.size()!=v2.size())
        {
            cout<<"-1"<<endl;
            return 0;
        }
        sort(all(v1));sort(all(v2));
        
        if(v1.size()==0)
        {
            cout<<"0"<<endl;
            return 0;
        }

        // V ans1,ans2;
        // ll st=0;
        // ll cnt1=0;
        // while(true)
        // {
        //     // cout<<st<<endl;
        //     if(cnt1%2==0)
        //     {
        //         if(lower_bound(all(v1),st)!=v1.end())
        //         {
        //             auto it1=lower_bound(all(v1),st);
        //             auto it=*it1;
        //             ans1.pb(it);
        //             st=it+1;
        //             cnt1++;
        //         }
        //         else 
        //         {
        //             break;
        //         }
        //     }
        //     else 
        //     {
        //         if(lower_bound(all(v2),st)!=v2.end())
        //         {
        //             auto it1=lower_bound(all(v2),st);
        //             auto it=*it1;
        //             // err1(it)<<endl;
        //             ans1.pb(it);
        //             cnt1++;
        //             st=it+1;
        //         }
        //         else 
        //         {
        //             break;
        //         }
        //     }
        // }
        // st=0;
        // cnt1=0;
        // while(true)
        // {
        //     if(cnt1%2==0)
        //     {
        //         if(lower_bound(all(v2),st)!=v2.end())
        //         {
        //             auto it1=lower_bound(all(v2),st);
        //             auto it=*it1;
        //             ans2.pb(it);
        //             st=it+1;
        //             cnt1++;
        //         }
        //         else 
        //         {
        //             break;
        //         }
        //     }
        //     else 
        //     {
        //         if(lower_bound(all(v1),st)!=v1.end())
        //         {
        //             auto it1=lower_bound(all(v1),st);
        //             auto it=*it1;
        //             ans2.pb(it);
        //             cnt1++;
        //             st=it+1;
        //         }
        //         else 
        //         {
        //             break;
        //         }
        //     }
        // }

        // ll k1=max(ans1.size(),ans2.size());
        // k1/=2;

        // ll t1=v1.size();
        // t1-=k1;
        // ll t2=v2.size();
        // t2-=k1;
        // assert(t1==t2);
        // ll ans;
        // if(k1>0)
        // ans=(t1)+1;
        // else 
        // ans=t1;
        // cout<<ans<<endl;
        V tmp(n,0);
        for(auto it:v1)tmp[it]=1;
        for(auto it:v2)tmp[it]=-1;
        V tmp2;
        rep(i,0,n)
        {
            if(tmp[i]!=0)tmp2.pb(tmp[i]);
        }
        ll ans=0;
        ll sum=0,sum2=0;
        // errA(tmp2);
        ll ch=-1;
        rep(i,0,tmp2.size())
        {
            sum+=(-1*tmp2[i]);
            sum2+=(1,tmp2[i]);
            ans=max(ans,sum);
            ans=max(ans,sum2);
            if(sum<0)
            sum=0;
            if(sum2<0)
            sum2=0;
        }

        cout<<ans<<endl;




    }

}
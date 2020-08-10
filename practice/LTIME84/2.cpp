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
        string A,B;
        cin>>A;
        cin>>B;
        map<char,ll> mp1,mp2;
        rep(i,0,n)
        {
            mp1[A[i]]++;
        }
        rep(i,0,n)
        {
            mp2[B[i]]++;
        }
        bool flg=false;
        for(auto it:mp2)
        {
            if(mp1[it.first]==0)
            {
                flg=true;
                break;
            }
        }

        if(flg)
        {
            cout<<"-1"<<endl;
            continue;
        }

        if(A==B)
        {
            cout<<"0"<<endl;
            continue;
        }

        map<char,vector<ll>>ans;
        vector<ll>ind(26,-1);
        bool flg2=false;
        ll cnt=0;
        for(char ch='z';ch>='a';ch--)
        {
            if(mp2[ch]==0)continue;
            for(ll i=0;i<n;i++)
            {
                if(B[i]==ch && A[i]<ch)
                {
                    flg2=true;
                    break;
                }
                else if(B[i]==ch && A[i]!=ch)
                {
                    ans[ch].pb(i);

                }
                else if(A[i]==ch) 
                ind[ch-'a']=i;
            }
            if(ans[ch].size()!=0 && ind[ch-'a']==-1)
            {
                flg2=true;
            }
            if(flg2)
            {
                break;
            }
            if(ans[ch].size()!=0)
            {
                cnt++;
                ans[ch].pb(ind[ch-'a']);
                rep(i,0,n)
                {
                    if(B[i]==ch &&  A[i]!=ch)
                    A[i]=ch;
                }
            }
        }

        if(flg2)
        {
            cout<<"-1"<<endl;
            continue;
        }


        cout<<cnt<<endl;

        
        for(char ch='y';ch>='a';ch--)
        {
            if(ans[ch].size()!=0)
            {
                cout<<ans[ch].size()<<" ";
                for(auto it:ans[ch])
                cout<<it<<" ";
                cout<<endl;
            }
        }




    }

}
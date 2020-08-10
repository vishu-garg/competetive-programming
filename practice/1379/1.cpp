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
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif


    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string p="abacaba";
        ll fnd=0;
        rep(i,0,s.length()-6)
        {
            string tmp="";
            rep(j,0,7)
            tmp+=s[i+j];
            // err1(tmp);
            if(tmp==p)
            {
                fnd++;
            }
        }

        if(fnd>1)
        {
            cout<<"No"<<endl;
            // err();
            continue;
        }

        else if(fnd==1)
        {
            cout<<"Yes"<<endl;
            // err();
            rep(i,0,s.length())
            {
                if(s[i]=='?')
                cout<<"d";
                else 
                cout<<s[i];
            }
            cout<<endl;
            continue;
        }

        else
        {
            ll flg=-1;
            V tmp2;
            rep(i,0,s.length()-6)
            {
                ll cnt=0;
                rep(j,0,7)
                {
                    if(s[i+j]==p[j] || s[i+j]=='?')
                    {
                        cnt++;
                    }
                }
                if(cnt==7)
                {
                    tmp2.pb(i);
                    flg=i;
                    // break;
                }
            }
            if(flg==-1)
            {
                cout<<"No"<<endl;
                continue;
            }
            else 
            {
                ll flg3=-1;
                for(auto it:tmp2)
                {
                    flg=it;
                    string tmp1="";
                rep(i,0,flg)
                {
                    if(s[i]=='?')tmp1+='d';
                    else tmp1+=s[i];
                }
                rep(j,0,7)tmp1+=p[j];
                rep(i,flg+7,s.length())
                {
                    if(s[i]=='?')
                    tmp1+='d';
                    else
                    tmp1+=s[i];
                }
                ll fnd2=0;
                rep(i,0,tmp1.length()-6)
                {
                    string tmp="";
                    rep(j,0,7)
                    tmp+=tmp1[i+j];
                    // err1(tmp);
                    if(tmp==p)
                    {
                        fnd2++;
                    }
                }
                if(fnd2>1)
                {
                    continue;
                }
                else 
                {
                    cout<<"Yes"<<endl;
                    cout<<tmp1<<endl;
                    flg3=1;
                    break;
                }

                }
                if(flg3==-1)
                {
                    cout<<"No"<<endl;
                    continue;
                }
            }
        }
    }
}
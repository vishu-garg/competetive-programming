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
vector<bool> d(1e6 + 9, false);
int main(){ll n;
    cin>>n;
    vector<ll> a(n);
    bool incr = true;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        d[a[i]] = true;
        if(i > 0){
            if(a[i] < a[i-1]){
                incr = false;
            }
        }
    }
    if(!incr){
        cout<<-1<<endl;
        return 0;
    }
    vector<ll> b(n);
    vector<bool> c(1e6 + 9, false);
    set<ll> s, t;
    for(ll i=0; i<2*n + 5; i++){
        t.insert(i);
        if(!d[i]){
            s.insert(i);
        }
    }
    ll mex = 0, id = 0;
    for(ll i=0; i<n; i++){
        if(a[i] > mex){
            b[i] = mex;
        }
        else if(a[i] == mex){
            for(auto j: s){
                if(!c[j]){
                    b[i] = j;
                    break;
                }
            }
        }
        else{
            cout<<-1<<endl;
            return 0;
        }
        c[b[i]] = true;
        if(s.find(b[i]) != s.end()){
            s.erase(b[i]);
        }
        t.erase(b[i]);
        mex = *(t.begin());
    }
    for(ll i=0; i<n; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
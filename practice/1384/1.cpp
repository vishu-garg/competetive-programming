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
    while(T--){
    ll n;
   cin>>n;
   V v(n);
   rep(i,0,n)cin>>v[i];
   vector<string>ans(n+1);
   char ch='a';
   ll rep=max(1LL,v[0]);
   string s="";
   rep(i,0,rep){
   	s+=ch;
   }
   ans[0]=s;
   rep(i,1,n){
   	if(v[i-1]==0){
   		char ch1;
   		string s1="";
   		if(ans[i-1][0]=='z')ch1='a';
   	    else ch1=ans[i-1][0]+1;
   	    ll mx=max(1LL,v[i]);
   	    rep(j,0,mx)s1+=ch1;
   	    ans[i]=s1;
	   }
   	else{
   		string s1="";
   	rep(j,0,v[i-1]){
   		s1+=ans[i-1][j];
	   }
	char ch1='a';
	if(v[i]>v[i-1]){
		if(ans[i-1].length()==v[i-1])ch1='a';
		else {
			if(ans[i-1][v[i-1]]=='z')ch1='a';
			else ch1=ans[i-1][v[i-1]]+1;
		}
		rep(j,0,v[i]-v[i-1]){
			s1+=ch1;
		}
	}
	if(s1.length()==0){
   	char ch2;
   	if(ans[i-1][0]=='z')ch2='a';
   	else ch2=ans[i-1][0]+1;
   	s1+=ch2;
   }
	ans[i]=s1;
	   }
   }
   string s2="";
   rep(i,0,v[n-1]){
   	s2+=ans[n-1][i];
   }
   if(s2.length()==0){
   	char ch1;
   	if(ans[n-1][0]=='z')ch1='a';
   	else ch1=ans[n-1][0]+1;
   	s2+=ch1;
   }
   ans[n]=s2;
   rep(i,0,n+1){
   	cout<<ans[i]<<endl;
   }

    }

}
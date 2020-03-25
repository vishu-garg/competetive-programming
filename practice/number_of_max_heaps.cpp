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
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

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

ll nck[101][101];
int ans[101];

int get_left(int n)
{
	if(n==1)return 0;
    int l;
    ll h=0;
    ll cpy=n;
    while(n>=2)
    {
    	h++;
    	n/=2;
	}
	n=cpy;
//    cout<<h<<endl;
    int p = n-((1<<h)-1);
//    cout<<n<<" "<<(1<<h)-1<<" ####"<<endl;
    int m = (1<<h)/2;
//    cout<<m<<" "<<p<<endl;
    if(p>=m)
    l=(1<<h)-1;
    else 
    l=(1<<h)-1-(m-p);
    // cout<<l<<"  ......l"<<endl;
    return l;
}

int get_nck(int n , int r)
{
    if(nck[n][r]!=-1)return nck[n][r];
    if(r>n)
    nck[n][r]=0;
    else if(n<=1)nck[n][r]=1;
    else if (r==0)
    nck[n][r]=1;
    else if(r==1)
    nck[n][r]=n;
    else 
    {
        nck[n][r] = get_nck(n-1,r-1)+get_nck(n-1,r);
        nck[n][r]%=M;
    }
    return nck[n][r];
}

int func(int n)
{
    // cout<<"yes";
    if(n<=1){return 1;}
    if (ans[n]!=-1){return ans[n];}
    int l = get_left(n);
    //  cout<<l<<"       .........l"<<endl;
    ans[n]=get_nck(n-1,l)*func(l)*func(n-1-l);
    ans[n]%=M;
    return ans[n];
}

int main()
{
    int n;
    cin>>n;
    rep(i,0,101)
    rep(j,0,101)
    nck[i][j]=-1;
    rep(i,0,101)ans[i]=-1;
    func(n);
     cout<<ans[n]%M;
}
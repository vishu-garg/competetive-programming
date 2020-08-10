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
const int N=1000005;
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



int fnwck_tree[N];

void update(int item , int val)
{
    while(item<N)
    {
        fnwck_tree[item]+=val;
        item+=(item&(-item));
    }
}

int query(int pos)
{
    int ans=0;
    while(pos>0){
        ans+=fnwck_tree[pos];
        pos-=(pos&(-pos));
    }
    return ans;
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        int n,q;
        cin>>n>>q;
        
        rep(i,0,n)
        {
            int item;
            cin>>item;
            update(item,1);
        }

        rep(i,0,q)
        {

            ll x;
            cin>>x;
            if(x<0)
            {
                x=-x;
                ll l=1,r=n;
                while(l<r)
                {
                    int mid=(l+r)/2;
                    int p=query(mid); 
                    if(p>=x)  // the mid number has pos >=x so check in l...mid  
                    {
                        r=mid;
                    }
                    else 
                    {
                        l=mid+1;
                    }
                }
                update(l,-1);
            }
            else 
            update(x,1);
        }

        ll ans=0;
        rep(i,1,n+1)
        {
            if(query(i)>0) // there are some numbers which are <= i;
            {
                ans=i; 
                break;
            }
        }
        cout<<ans<<endl;

    }

}
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

int main()
{
    fast;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>a(n);
        rep(i,0,n)
        cin>>a[i];    
        if(find(all(a),k)==a.end())
        {
            cout<<"no"<<endl;
            continue;
        }
        
        rep(i,0,n)
        {
           if(a[i]>k)a[i]=2;
           else if(a[i]<k)a[i]=0;
           else a[i]=1; 
        }

        if(n==1)
        {cout<<"yes"<<endl;continue;}

        //  rep(i,0,n)
        //  cout<<a[i]<<" ";
        //  cout<<endl;   

        ll flg=0;
            rep(i,0,n)
            {
                if(a[i]==0)
                continue;
                if(i+1<n && a[i+1]>0)
                {
                    flg=1;
                    cout<<"yes"<<endl;
                    break;
                }
                else if(i+2<n && a[i+2]>0)
                {
                    flg=1;
                    cout<<"yes"<<endl;
                    break;
                }
            }
            if(flg==0)
            {
                cout<<"no"<<endl;
            }
    }

}
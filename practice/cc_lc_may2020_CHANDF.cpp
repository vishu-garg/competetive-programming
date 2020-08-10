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
int k_th_bit(ll num,ll k)
{
    int bit;
    rep(i,0,k)
    {
        bit=num%2;
        num>>=1;
        // cout<<bit<<" "<<num<<"<--"<<endl;
    }
    // cout<<num<<" "<<k<<" "<<bit<<"<--"<<endl;
    return bit;
}

ll F(ll x, ll y, ll z)
{
    return (x&z)*(y&z);
}

int main()
{
    fast;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll X,Y,L,R;
        cin>>X>>Y>>L>>R;
        ll k=50;
        ll z=0;
        // k_th_bit(17,5);
        ll k1=k_th_bit(L,k);
        ll k2=k_th_bit(R,k);
        while(k>0 && k1==k2)
        {
            // cout<<k<<" "<<z<<"<---"<<endl;
            if(k1==1)
            z+=(ll)pow(2,k-1);
            k--;
            k1=k_th_bit(L,k);
            k2=k_th_bit(R,k);
        }
        // cout<<k<<" "<<z<<"<---"<<endl;
        // // err()
        if(k==0)
        {
            cout<<L<<endl;
            continue;
        }
        // err()
        ll cur_max=F(X,Y,L);
        // cout<<cur_max<<endl;
        ll ans=L;
        ll z2=z+(ll)pow(2,k-1);
        // cout<<z2<<endl;
        vector<ll>X_bits(51),Y_bits(50);
        rep(i,1,51)
        {
            X_bits[i]=k_th_bit(X,1);
            Y_bits[i]=k_th_bit(Y,i);
        }
        ll z1=z;
        for(ll bit=k-1;bit>0;bit--)
        {
            if(k_th_bit(L,bit)==0)
            {
            z1+=(ll)pow(2,bit-1);
            for(ll rem=bit-1;rem>0;rem--)
                {
                    if(X_bits[rem]==1 || Y_bits[rem]==1)
                    {
                        z1+=(ll)pow(2,rem-1);
                    }
                }
                // cout<<F(X,Y,z1)<<" "<<cur_max<<endl;
                ll tmp=F(X,Y,z1);
                if(tmp>=cur_max)
                {
                    ans=z1;
                    // cout<<ans<<" ### "<<z1<<endl;
                    cur_max=tmp;
                }
            }
            // cout<<z1<<" "<<cur_max<<" "<<ans<<"<--"<<endl;
            z1=z;
            if(k_th_bit(L,bit))
            z1+=(ll)pow(2,bit-1);
            z=z1;
            // cout<<z1<<"<--"<<endl;
        }
        // cout<<cur_max<<" "<<ans<<endl;
        z=z2;
        for(ll bit=k-1;bit>0;bit--)
        {
            if(k_th_bit(R,bit))
            {
                for(ll rem=bit-1;rem>0;rem--)
                {
                    if(X_bits[rem]==1 || Y_bits[rem]==1)
                    {
                        z2+=(ll)pow(2,rem-1);
                    }
                }
                ll tmp=F(X,Y,z2);
                if(tmp>cur_max)
                {
                    cur_max=tmp;
                    ans=z2;
                }
            }
            z2=z;
            if(k_th_bit(R,bit))
            z2+=(ll)pow(2,bit-1);
            z=z2;
        }
        cout<<ans<<endl;
    }

}
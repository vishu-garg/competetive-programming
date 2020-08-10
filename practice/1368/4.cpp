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
    // cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        V a(n);
        rep(i,0,n)cin>>a[i];
    //     ll num=(ll)pow(2,20);
    //     ll ans2=0;
    //     repb(i,20,0)
    //     {
    //         // num+=(ll)pow(2,i);
    //         // err1(num)<<endl;
    //         ll cnt=0;
    //         ll fnd=0;
    //         V b(n);
    //         ll cnt2=0;
    //         rep(j,0,n)
    //         {
    //             ll tmp=a[j]-(num);
    //             if(tmp>=0)
    //             {b[j]=tmp;cnt++;}
    //             else 
    //             b[j]=a[j];
    //             if(tmp<0 && b[j]==(ll)(pow(2,i+1))-1ll)
    //             cnt2++;
    //         }
    //         if(cnt2==n-cnt)
    //         break;
    //         // cout<<cnt<<endl;
    //         ll t3=cnt;
    //         // err1(cnt)<<endl;
    //         // if(t3!=0)cout<<num<<endl;
    //         sort(all(b));
    //         ll tmp2=n-1;
    //         rep(j,0,cnt)
    //         {
    //             b[tmp2]+=num;
    //             tmp2--;
    //         }
    //         ll tmp3=0;
    //         rep(j,0,n)
    //         tmp3+=b[j]*b[j];

    //         if(t3!=0){
    //         rep(j,0,n)
    //         a[j]=b[j];}

    //         ans2=max(ans2,tmp3);


    //         // rep(j,0,n)
    //         // cout<<a[j]<<" ";
    //         // cout<<endl;
    //         // if(t3!=0)break;
    //         if(t3!=0)num+=(ll)(pow(2,i-1));
    //        else  num=(ll)(pow(2,i-1));

    //     }

        V tmp2(21,0);

        rep(i,0,n)
        {
            // cout<<a[i]<<endl;
            ll cnt=0;
            while(a[i]>0)
            {
                if(a[i]%2==1)
                tmp2[cnt]++;
                a[i]/=2;
                cnt++;
            }
        }

        // rep(i,0,21)
        // cout<<tmp2[i]<<" ";

        ll num=0,ans=0;
        rep(i,0,n)
        {
            ll num2=0;
            rep(j,0,21)
            {
                // cout<<tmp2[j]<<endl;
                if(tmp2[j]>0)
                {num2+=(ll)pow(2,j);tmp2[j]--;}
            }
            ans+=(num2*num2);
        }

        // ll ans=0;
        // rep(i,0,n)
        // {
        //     ans+=(a[i]*a[i]);
        //     ans2=max(ans,ans2);
        // }
        cout<<ans<<endl;
    }

}
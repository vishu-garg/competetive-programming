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
        ll  n,k;
        cin>>n>>k;
        vector<array<int,3>>v;
        V a,b;

        rep(i,0,n)
        {
            ll t,a1,b1;
            cin>>t>>a1>>b1;
            if(a1+b1!=0)
            {
                array<int,3> ar={t,a1,b1};
                v.pb(ar);
            }
        }

        // for(auto it:v)
        // {
            // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"<--"<<endl;
        // }

        n=v.size();

        sort(all(v));

        rep(i,0,n)a.pb(v[i][1]);

        rep(i,0,n)b.pb(v[i][2]);

        ll ind1=-1,ind2=-1,sum1=0,sum2=0;

        // errA(a);

        rep(i,0,n)
        {
            sum1+=a[i];
            if(sum1>=k)
            {
                ind1=i;
                break;
            }
        }

        rep(i,0,n)
        {
            sum2+=b[i];
            if(sum2>=k)
            {
                ind2=i;
                break;
            }
        }

        // cout<<sum1<<" "<<sum2<<endl;
        
        // err2(ind1,ind2)<<endl;

        if(ind1==-1 || ind2==-1)
        {
            cout<<"-1"<<endl;
            return 0;
        }

        ll ans=0;

        // err2(ind1,ind2)<<endl;
        V tmp5;
        rep(i,0,n)
        {
            if(v[i][1]==1 && v[i][2]==1)
            tmp5.pb(v[i][0]);
        }
        sort(all(tmp5));
        // ll ans2=-1;
        // if(tmp5.size()>=k)
        // {
        //     ans2=0;
        //     sort(all(tmp5));
        //     rep(i,0,k)
        //     ans2+=tmp5[i];
        // }


        V tmp2,tmp3;

        rep(i,0,n)
        {
            if(v[i][1]==1 && v[i][2]==0)
            tmp2.pb(i);
            if(v[i][1]==0 && v[i][2]==1)
            tmp3.pb(i);
        }

        // set<ll>st;

        // ll ans3=-1;

        // if(tmp2.size()>=k && tmp3.size()>=k)
        // {
        //     rep(i,0,k)
        //     {st.insert(tmp2[i]);st.insert(tmp3[i]);}
        //     for(auto it:st)
        //     {
        //         ans3+=v[it][0];
        //     }
        // }
        ll ans5 =LLONG_MAX;
        ll sum5=0;
        // rep(i,0,tmp5.size())
        // {  sum5+=tmp5[i];
        //     ll req=k-(i+1);
        //     // err1(req)<<endl;
        //     if(tmp2.size()>=req && tmp3.size()>=req)
        //     {
        //     ll flg=1;
        //     set<ll>st1;
        //     ll ans4=sum5;
        //     rep(j,0,req)
        //     {st1.insert(tmp2[j]);st1.insert(tmp3[j]);}
        //     for(auto it:st1)
        //     {
        //         ans4+=v[it][0];
        //     }
        //     // errA(st1);
        //     ans5=min(ans5,ans4);
        //     }
        // }

        // if(tmp5.size()>=k)
        // {
        //     ll ans2=0;
        //     rep(i,0,k)
        //     ans2+=tmp5[i];
        //     ans5=min(ans5,ans2);
        // }

        // if(tmp2.size()>=k && tmp3.size()>=k)
        // {
        //     set<ll>st1;
        //     ll ans4=0;
        //     rep(j,0,k)
        //     {st1.insert(tmp2[j]);st1.insert(tmp3[j]);}
        //     for(auto it:st1)
        //     {
        //         ans4+=v[it][0];
        //     }
        //     // errA(st1);
        //     ans5=min(ans5,ans4);
        // }

        V v1,v2,v3,v4;
        ll sum=0;
        rep(i,0,tmp5.size())
        {
            sum+=tmp5[i];
            v1.pb(tmp5[i]);
        }

        sum=0;

        rep(i,0,min(tmp3.size(),tmp2.size()))
        {
            v4.pb(v[tmp2[i]][0]+v[tmp3[i]][0]);
        }

        // errA(v4);
        


        // ll ans=0;
        ll cnt=0;

        V tmp7;
        rep(i,0,v1.size())
        tmp7.pb(v1[i]);

        rep(i,0,v4.size())
        tmp7.pb(v4[i]);

        sort(all(tmp7));

        rep(i,0,k)
        ans+=tmp7[i];
        
        cout<<ans<<endl;

    }

}
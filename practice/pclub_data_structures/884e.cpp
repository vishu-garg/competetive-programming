// #include<bits/stdc++.h>
// #include<algorithm>
// using namespace std;
 
// #define ll int
// #define ld long double
 
// #define rep(i,a,b) for(ll i=a;i<b;i++)
// #define repb(i,a,b) for(ll i=a;i>=b;i--)
 
// #define err() cout<<"=================================="<<endl;
// #define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
// #define err1(a) cout<<#a<<" "<<a<<endl
// #define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
// #define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
// #define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
// #define pb push_back
// #define all(A)  A.begin(),A.end()
// #define allr(A)    A.rbegin(),A.rend()
// #define ft first
// #define sd second
 
// #define pll pair<ll,ll>
// #define V vector<ll>
// #define S set<ll>
// #define VV vector<V>
// #define Vpll vector<pll>
 
// #define endl "\n"
 
// const ll logN = 20;
// const ll N=100005;
// const ll M = 1000000007;
// const ll INF = 1e12;
// #define PI 3.14159265
// #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// int pow1(int a,int b){
//     int res=1;
//     while(b>0){
//         if(b&1){
//         	res=res*a;
// 		}
//         a=a*a;
//         b>>=1;
//     }
//     return res;
// }

// // struct segtree{
// //     ll x,y;
// //     ll tree[4*N];

// //     void build_tree(vector<ll>&v , ll ind,ll l, ll r)
// //     {
// //         if(l==r)
// //         {
// //             tree[ind]=v[l];
// //             return;
// //         }
// //         ll mid=(l+r)/2;
// //         build_tree(v,2*ind,l,mid);
// //         build_tree(v,2*ind+1,mid+1,r);
// //         tree[ind]=max(tree[2*ind],tree[2*ind+1]);
// //     }

// //     ll query(ll ind, ll l, ll r)
// //     {
// //         // cout<<l<<" "<<r<<" "<<endl;
// //         if(x>r || y<l)return -LLONG_MAX;
// //         if(l>=x && r<=y)return tree[ind];
// //         ll mid=(l+r)/2;
// //         return max(query(2*ind,l,mid),query(2*ind+1,mid+1,r));
// //     }
// // }obj;
// ll n,m;
// vector<ll> mat;
// vector<ll>par;
// // vector<vector<bool>>vis;

// // void dfs(ll i, ll j)
// // {
// //     if(i<0 || j<0 || i>=n || j>=m || mat[i][j]=='0' || vis[i][j])return;
// //     vis[i][j]=true;
// //     dfs(i+1,j);
// //     dfs(i,j+1);
// //     dfs(i-1,j);
// //     dfs(i,j-1);
// //     return;
// // }

// ll get_parent(ll ind)
// {
//     if(par[ind]==ind)return ind;
//     else 
//     return par[ind]=get_parent(par[ind]);
// }


// int main()
// {
//     // fast;
//     ll T=1;
// //     cin>>T;
//     while(T--)
//     {
//         cin>>n>>m;
//         mat = vector<ll>(2*m+2,0);
//         par=vector<ll>(2*m+2,0);
//         // vis=  vector<vector<bool>>(n,vector<bool>(m,false));
//         ll cnt1=0,cnt2=0;
//         rep(i,0,n)
//         {
//             if(i==0)
//             rep(j,0,2*m+1)
//             par[j]=j;
//             else
//             rep(j,0,m)
//             par[j]=j;
//             ll cnt=0;
//             rep(j,0,m/4)
//             {
//                 char tmp;
//                 cin>>tmp;
//                 ll itm;
//                 if(tmp=='A')
//                 itm=10;
//                 else if(tmp=='B')
//                 itm=11;
//                 else if(tmp=='C')
//                 itm=12;
//                 else if(tmp=='D')
//                 itm=13;
//                 else if(tmp=='E')
//                 itm=14;
//                 else if(tmp=='F')
//                 itm=15;
//                 else 
//                 itm=tmp-'0';
//                 vector<ll>tmp2;
//                 rep(k,0,4)
//                 {
                
//                     tmp2.pb(itm%2);
//                     itm/=2;
//                     // cnt++;   
//                 }
//                 rep(k,0,4)
//                 {
//                     mat[cnt]=tmp2[3-k];
//                     cnt++;
//                 }
//             }
//             rep(j,0,m)
//             if(mat[j]){cnt1++;}
//             // if(i==0)
//             // {
//             //     rep(j,1,m)
//             //     {
//             //         if(mat[j] && mat[j-1])
//             //         {
//             //             ll p1=get_parent(j);
//             //             ll p2=get_parent(j-1);
//             //             if(p1!=p2)
//             //             {
//             //                 cnt2++;
//             //                 par[j-1]=p1;
//             //             }
//             //         }
//             //     }
//             //     rep(j,0,m)
//             //     {
//             //         mat[m+j]=mat[j];
//             //         // par[m+j]=(par[j]+m);
//             //     }
//             // }
//             // else 
//             // {
//                 rep(j,0,m)
//                 {
//                     if(mat[j] && mat[m+j])
//                     {
//                         // err1(i)<<endl;
//                         ll p1=get_parent(j);
//                         ll p2=get_parent(m+j);
//                         // err4(j,p1,m+j,p2)<<endl;
//                         if(p1!=p2)
//                         {
//                             cnt2++;
//                             par[j]=p2;
//                         }
//                         // err2(par[j],par[m+j]);
//                     }
//                 }
//                 rep(j,1,m)
//                 {
//                     if(mat[j] && mat[j-1])
//                     {
//                         ll p1=get_parent(j-1);
//                         ll p2=get_parent(j);
//                         if(p1!=p2)
//                         {
//                             cnt2++;
//                             par[j]=p1;
//                         }
//                     }
//                 }
//                 rep(j,0,m)
//                 mat[m+j]=mat[j];
//             // }
//             rep(j,m,2*m)
//             {
//                 par[j]=(par[j-m]+m)%(2*m);
//             }
//             // errA(par);
//         }

//         cout<<cnt1-cnt2<<endl;

//         // rep(i,0,n)
//         // {
//         //     rep(j,0,m)cout<<mat[i][j]<<" ";
//         //     cout<<endl;
//         // }

//     }

// }
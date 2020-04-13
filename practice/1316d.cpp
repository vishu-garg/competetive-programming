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

int N=200005;
int x[N][N],y[N][N];
char mat[N][N];
int n;

bool connect(int i, int j , int fi, int fj, char ini , char f)
{
    mat[i][j]=ini;
    if(x[fi][fj]==-1)
    {
        if(mat[fi][fj]=='/0')
        mat[fi][fj]=f;
        return true;
    }
    return false;
}

void  dfs(int i, int j , char inst)
{
    if(mat[i][j]!='\0')
    return;
    mat[i][j]=inst;
    if(x[i+1][j]==x[i][j] && y[i][j]==y[i+1][j])
    dfs(i+1,j,'U');
    if(x[i-1][j]==x[i][j] && y[i][j]==y[i-1][j])
    dfs(i+1,j,'D');
    if(x[i][j+1]==x[i][j] && y[i][j]==y[i][j+1])
    dfs(i+1,j,'L');
    if(x[i][j-1]==x[i][j] && y[i][j]==y[i][j-1])
    dfs(i+1,j,'R');
    return;
}

int main()
{
    int i,j;
    cin>>n;
    rep(i,1,n+1)
    rep(j,1,n+1)
    {
        cin>>x[i][j]>>y[i][j];
    }

    rep(i,1,n+1)
    rep(j,1,n+1)
    {
        if(x[i][j]==-1)
        {
            bool res=(mat[i][j]!='\0');
            if(res==0)res=connect(i,j,i+1,j,'D','U');
            if(res==0)res=connect(i,j,i+1,j,'R','L');
            if(res==0)res=connect(i,j,i+1,j,'U','D');
            if(res==0)res=connect(i,j,i+1,j,'L','R');
            if(res==0)
            {
                cout<<"INVALID"<<endl;
                return 0;
            }
        }
        else if(x[i][j]==i &&  y[i][j]==j)
        dfs(i,j,'X');
    }

    rep(i,1,n+1)
    rep(j,1,n+1)
    {
        if(mat[i][j]=='\0')
        {
            cout<<"INVALID";
            return 0;
        }
    }
    cout<<"VALID"<<endl;
    rep(i,1,n+1)
    {
    rep(j,1,n+1)
    cout<<mat[i][j]<<" ";
    cout<<endl;
    }
}
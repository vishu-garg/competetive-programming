#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
 
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

int main()
{
    ll t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<set<int> > segs;
        rep(i,0,n-1)
        {
            set<int> cur;
            int tmp;
            cin>>tmp;
            rep(j,0,tmp)
            {
                int tmp2;
                cin>>tmp2;
                cur.insert(tmp2);
            }
            segs.pb(cur);
        }

        for(int i=1;i<=n;i++)
        {
            vector<set<int> > segs2 = segs;
            int fst=i; // FIXING FIRST ELELMENT
            for(auto &it : segs2)
            if(it.count(fst))it.erase(fst);
            vector<int> ans;
            ans.pb(fst);
            bool ok=true;
            for(int j=1;j<n;j++)
            {
                int cnt=0,ele;
                for(auto &it : segs2)
                {
                    if(it.size()==1)
                    {cnt++;ele=*it.begin();}
                }
                // cout<<j<<" "<<ans[j-1]<<" "<<cnt<<"<---"<<endl;
                if(cnt!=1)
                {
                    ok=false;
                    break;
                }
                ans.pb(ele);
                for(auto &it: segs2)
                {
                    if(it.count(ele))it.erase(ele);
                }
            }
            // cout<<ok;
            // if(ok)
            // {
            //     rep(i,0,n)
            //     cout<<ans[i]<<" ";
            //     cout<<endl;
            // }
            if(ok)
            {
                for(int i2=1;i2<n;i2++)
                {
                    // cout<<ans[i]<<" "<<"<---"<<endl;
                    bool found=false;
                    set<int> tmp;
                    tmp.insert(ans[i2]);
                    for(int j=i2-1;j>=0;j--)
                    {
                        tmp.insert(ans[j]);
                        if(find(all(segs),tmp)!=segs.end())
                        {
                            found=true;
                            break;
                        }
                    }
                    if(!found)
                    {
                        ok=false;
                        break;
                    }
                }
            }
            if(ok)
            {
                rep(i2,0,n)
                cout<<ans[i2]<<" ";
                cout<<endl;
                break;
            }
            // cout<<i<<" ### \n";
        }

    }

}


/* the main observation in this question is hidden in this line ..... 
"For EACH position r from 2 to n we chose some other index l (l<r) and gave you the segment pl,pl+1,…,pr in sorted order"
*/


/*
TBR : remember that in code we wrote for(auto &it : segs2)
      & is necessary to be there as we are erasing some elelment from the segs2's element and so memory reference is done in range based loop here.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int N=105;
signed main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int dp[N][N];

    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)dp[i][j]=0;

    for(int i=0;i<N;i++)
    {
        dp[0][i]=0;
    }
    dp[0][1]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i+1;j++)
        {
            if(j==0)
            {dp[i][j]=0;continue;}
            if(j==1)
            {
                int flg=0;
                for(int mid_num=0;mid_num<i;mid_num++)
                {
                    if(s[mid_num]==s[i])
                    {flg=1;break;}
                }

                if(flg==0)
                dp[i][j]=1;
                continue;
            }
            for(int i2=0;i2<i;i2++)
            {
                int flg=0;
                for(int mid_num=i2+1;mid_num<i;mid_num++)
                {
                    if(s[mid_num]==s[i])
                    {
                        flg=1;
                        break;
                    }
                }
                if(flg==1)
                continue;
                // if(i==7)
                // {
                //     cout<<i<<" "<<j<<" "<<i2<<endl;
                // }
                dp[i][j]+=(dp[i2][j-1]);
            }
            // if(i==9)
            // cout<<dp[i][j]<<endl;
        }
    }

    int ans=0;

    int val=0;

    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<" --->  ";
    //     for(int j=0;j<=n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }



    for(int i=n;i>0;i--)
    {
        for(int j=i-1;j<n;j++)
        {
            if(val>=k)
            {
                i=0;
                break;
            }
            int tot=min(k-val,dp[j][i]);
            val+=tot;
            ans+=(tot)*(n-i);
            // cout<<val<<" "<<ans<<" "<<endl;
        }
    }

    if(val<k)
    {
        ans+=(n);
        val+=1;
    }

    if(val<k)
    cout<<"-1"<<endl;
    else 
    cout<<ans<<endl;

}




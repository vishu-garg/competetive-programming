class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        int ans[n];
        ans[0]=v[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(j==i)
                    ans[j]=ans[j-1];
                if(j==0)
                {
                    ans[j]+=v[i][j];
                    continue;
                }
                else 
                    ans[j]=min(ans[j],ans[j-1]);
                ans[j]+=v[i][j];
            }
        }
        int tmp=ans[0];
        for(int i=1;i<n;i++)
            tmp=min(tmp,ans[i]);
        return tmp;
    }
};

// dp solution with O(N) space;
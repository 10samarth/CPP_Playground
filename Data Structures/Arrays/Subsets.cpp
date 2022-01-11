class Solution
{
public:
    void backtrack(vector<vector<int> > &res, vector<int> &nums, vector<int> &cur, int id)
    {
        res.push_back(cur);
        for (int i = id; i < nums.size(); i++)
        {
            vector<int> c = cur;
            c.push_back(nums[i]);
            backtrack(res, nums, c, i + 1);
        }
    }
    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<vector<int> > res;
        vector<int> cur;
        backtrack(res, nums, cur, 0);

        return res;
    }

    if(root==NULL)
            return;
        ans=(ans<<1)|root->val;
        if(root->left==NULL && root->right==NULL)
          sum+=ans;
        dfs(root->left,ans);
        dfs(root->right,ans);
};
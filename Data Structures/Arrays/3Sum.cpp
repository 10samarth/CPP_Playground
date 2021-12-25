class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        vector<vector<int> > res;

        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
        {
            if (i == 0 || nums[i - 1] != nums[i])
            {
                twoSum(nums, i, res);
            }
        }

        return res;
    }

    void twoSum(vector<int> &nums, int i, vector<vector<int> > &res)
    {
        int l = i + 1;
        int r = nums.size() - 1;

        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < 0)
            {
                ++l;
            }
            else if (sum > 0)
            {
                --r;
            }
            else
            {
                res.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1])
                {
                    ++l;
                }
            }
        }
    }
};
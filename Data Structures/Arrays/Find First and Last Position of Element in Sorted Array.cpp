class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int firstLoc = this->findBound(nums, target, true);

        if (firstLoc == -1)
        {
            return {-1, -1};
        }

        int lastLoc = this->findBound(nums, target, false);

        return {firstLoc, lastLoc};
    }

private:
    int findBound(vector<int> &nums, int target, bool isFirst)
    {
        int len = nums.size();
        int begin = 0;
        int end = len - 1;

        while (begin <= end)
        {
            int mid = (begin + end) / 2;

            if (nums[mid] == target)
            {
                if (isFirst)
                {
                    if (mid == begin || nums[mid - 1] != target)
                    {
                        return mid;
                    }
                    end = mid - 1;
                }
                else
                {
                    if (mid == end || nums[mid + 1] != target)
                    {
                        return mid;
                    }

                    begin = mid + 1;
                }
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }

        return -1;
    }
};
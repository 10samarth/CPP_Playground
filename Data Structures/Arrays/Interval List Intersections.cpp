class Solution
{
public:
    vector<vector<int> > intervalIntersection(vector<vector<int> > &firstList, vector<vector<int> > &secondList)
    {
        vector<vector<int> > result;
        int i = 0;
        int j = 0;

        while (i < firstList.size() and j < secondList.size())
        {
            int l = max(firstList[i][0], secondList[j][0]);
            int h = min(firstList[i][1], secondList[j][1]);

            if (l <= h)
            {
                result.push_back({l, h});
            }

            if (firstList[i][1] < secondList[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return result;
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()<1){
            return 0;
        }
        sort(points.begin(),points.end());
        int countArrows=1;
        for(int i=1; i<points.size();i++){
            if(points[i][0]<=points[i-1][1]){
                if(points[i][1]>=points[i-1][1]){
                    points[i][1] = points[i-1][1];
                }
            }
            else{
                countArrows++;
            }
        }
        return countArrows;
    }
};
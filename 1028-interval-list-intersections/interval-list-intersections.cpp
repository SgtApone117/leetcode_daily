class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int n = firstList.size();
        int m = secondList.size();
        int i,j;
        i = j = 0;
        while(i < n  && j < m)
        {
            int st = max(firstList[i][0], secondList[j][0]);
            int et = min(firstList[i][1],secondList[j][1]);
            if(st <= et)
            {
                result.push_back({st,et});
            }
            if(firstList[i][1] < secondList[j][1])
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
class Solution {
public:
long long mindis(int currr, int currf,vector<int>& robots,vector<int>& facs,vector<vector<long long>>& dp){
    if(currr == robots.size()) return 0;
    if(currf == facs.size()) return 1e12;

    if(dp[currr][currf]!=-1)
        {
            return dp[currr][currf];
        }
    long long assign = abs(robots[currr]- facs[currf])+ mindis(currr+1,currf+1,robots,facs,dp);
    long long skip = mindis(currr, currf+1,robots,facs,dp);
    return dp[currr][currf] = min(assign,skip);
}
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& fac) {
        sort(robot.begin(),robot.end());
        sort(fac.begin(),fac.end());
        vector<int> facpos;
        for(auto f:fac)
        {
            for(int i=0;i<f[1];i++)
            {
                facpos.push_back(f[0]); 
            }
        }
        vector<vector<long long>> dp(robot.size(), vector<long long>(facpos.size(),    -1));
        return mindis(0,0,robot,facpos,dp);
    }
};
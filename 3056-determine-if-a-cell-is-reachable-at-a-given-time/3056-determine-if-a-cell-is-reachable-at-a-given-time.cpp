class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
       int hor_dist = abs(sy - fy);
       int vert_dist = abs(sx - fx);

       if(hor_dist == 0 && vert_dist == 0 && t == 1)
       {
           return false;
       }     
       int min_time = max(hor_dist, vert_dist);
       if(t < min_time)
       {
           return false;
       }
       return true;
    }
};
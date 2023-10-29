class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int total_trials = ceil((minutesToTest / minutesToDie) + 1);
        int pigs = 0;
        while(pow(total_trials, pigs) < buckets)
        {
            pigs++;
        }
        return pigs;
    }
};
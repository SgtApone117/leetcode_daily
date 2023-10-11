class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) 
    {
        int flower_size = (int)flowers.size();
        int people_size = (int)people.size();

        vector<int> blooming_start(flower_size);
        vector<int> withered_end(flower_size);
        vector<int> arr_out(people_size);
        for(int i = 0; i < flower_size; i++)
        {
            blooming_start[i] = flowers[i][0];
            withered_end[i] = flowers[i][1];
        }

        sort(begin(blooming_start), end(blooming_start));
        sort(begin(withered_end), end(withered_end));

        for(int i = 0; i < people_size; i++){
            int person_time = people[i];

            int bloomed = upper_bound(begin(blooming_start), end(blooming_start), person_time) - begin(blooming_start);
            int withered = lower_bound(begin(withered_end), end(withered_end), person_time) - begin(withered_end);
            arr_out[i] = bloomed - withered;
        }
        return arr_out;
    }
};
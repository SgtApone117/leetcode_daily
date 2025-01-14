class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> a(n+1, false);
        vector<bool> b(n+1, false);
        vector<int> result(n);
        for(int i = 0; i < n; i++)
        {
            a[A[i]] = true;
            b[B[i]] = true;

            int count = 0;
            for(int i = 0; i < n+1; i++)
            {
                if(a[i] && b[i]) count++;
            }
            result[i] = count;
        }
        return result;
    }
};
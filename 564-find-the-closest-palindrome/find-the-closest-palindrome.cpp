class Solution {
public:
    long func(long firstHalfNum, bool isEven)
    {
        long result = firstHalfNum;
        if(!isEven)
            firstHalfNum /= 10;
        while(firstHalfNum > 0)
        {
            int digit = firstHalfNum%10;
            result = (result*10)+digit;
            firstHalfNum /= 10;
        }
        return result;
    }
    string nearestPalindromic(string n) {
        int L   = n.length();
        int mid = L/2;
        int firstHalfLength = (L%2 == 0)?mid:mid+1;
        long firstHalfNum   = stol(n.substr(0, firstHalfLength));
        vector<long> possibleAnswers;
        possibleAnswers.push_back(func(firstHalfNum, (L%2==0)));
        possibleAnswers.push_back(func(firstHalfNum+1, (L%2==0)));
        possibleAnswers.push_back(func(firstHalfNum-1, (L%2==0)));
        possibleAnswers.push_back((long)pow(10, L-1)-1);
        possibleAnswers.push_back((long)pow(10, L)+1);
        long diff = LONG_MAX;
        long result = LONG_MAX;
        long originalNum = stol(n);
        for(long num : possibleAnswers)
        {
            if(num == originalNum)
                continue;
            if(abs(num - originalNum) < diff)
            {
                diff = abs(num - originalNum);
                result = num;
            }
            else if(abs(num - originalNum) == diff)
            {
                result = min(result,num);
            }
        }
        return to_string(result);
    }
};
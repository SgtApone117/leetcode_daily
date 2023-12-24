class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        if(colors.length() == 2 || colors.length() == 1)
            return false;
        int alice_count = 0, bob_count = 0;
        for(int i = 0; i < colors.length(); i++)
        {
            if(colors[i] == 'A' && colors[i+1] == 'A' && colors[i+2] == 'A')
                alice_count++;
            else if(colors[i] == 'B' && colors[i+1] == 'B' && colors[i+2] == 'B')
                bob_count++;
        }
        if(alice_count == bob_count)
            return false;
        else if(alice_count > bob_count)
            return true;
        else if(alice_count < bob_count)
            return false;
        else
            return false;
    }
};

//AAAAAA
//AAAAA
//AAAA
//AAA
//AA
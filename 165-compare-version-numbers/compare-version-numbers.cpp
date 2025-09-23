class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length(); 
        int m = version2.length();
    
        vector<int> s1 ; 
        vector<int> s2 ;

        int i = 0; 
        bool flag = false; 
        while (i<n){
            flag = false;
            int k ;
            if (version1[i]=='.'){

                string word = ""; 
                k = i+1;  

                do{
                    if (version1[i]=='0' && flag){
                        word.push_back(version1[k++]);
                    }
                    else{
                        flag = true; 
                        word.push_back(version1[k++]);
                    }
                } while(version1[k]!='.' && k<n);
               
                int i1 = stoi(word) ;
                s1.push_back(i1); 
            }  
            else{
                k = i ; 
                string word = ""; 
                while(version1[k]!='.' && k<n){
                    word.push_back(version1[k++]);
                }
                int i1 = stoi(word) ;
                s1.push_back(i1);
            } 
            i = k ; 
        }   
        i = 0 ;
        while (i<m){
            flag = false; 
            int k ;
            if (version2[i]=='.'){

                string word = ""; 
                k = i+1; 

                do{
                    if (version2[i]=='0' && flag){
                        word.push_back(version2[k++]);
                    }
                    else{
                        flag = true; 
                        word.push_back(version2[k++]);
                    }
                } while(version2[k]!='.' && k<m);
                int i2 = stoi(word); 
                s2.push_back(i2); 
            }
            else{
                k = i ; 
                string word = ""; 
                while(version2[k]!='.' && k<m){
                    word.push_back(version2[k++]);
                }
                int i2 = stoi(word); 
                s2.push_back(i2); 
            }
            i = k ; 
        }
        n = s1.size(); 
        m = s2.size(); 
        int k = (n<m)?n:m;
        for (auto c:s1) cout << c << " ";
        cout << endl;
        for (auto c:s2) cout << c << " ";
        

        for (i = 0 ; i < k; i++){ 
            if (s1[i]<s2[i]) return -1; 
            else if (s1[i]>s2[i]) return 1; 
        }
        if (m>n) {
            int k = i ; 
            while (k<m){
                if (s2[k]>0){
                    return -1 ;
                }
                k++;
            }
        }
        else if (n>m) {
           int k = i ; 
            while (k<n){
                if (s1[k]>0){
                    return 1 ;
                }
                k++;
            } 
        }
        return 0; 
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string snew;
        for(char c:s){
            if(c==' '){
                continue;
            }
            if(!(c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9')){
                continue;
            }
            char t = c;
            if(c>='A' && c<='Z'){
                t = c-'A'+'a';
            }
            snew+=t;
        }
        cout << snew << endl;
          int i=0,j=snew.size()-1;
        while(i<=j){
            if(snew[i]!=snew[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

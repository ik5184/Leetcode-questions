class Solution {
public:
    void reverseString(vector<char>& s) {
        int m=0;int j=s.size()-1;
        
        while(m<=j){
            swap(s[m++],s[j--]);
        }
        
    }
};
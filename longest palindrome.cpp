class Solution {
public:
    int longestPalindrome(string s) {
    int count=0;
    bool flag=false;
    unordered_map<char,int> m;
    for(char i:s){
        m[i]++;
    }
    for(auto i:m){
        if(i.second%2==1)
            flag =true;
        count+=i.second/2;
    }
    if(flag)
        return 2*count+1;
    return 2*count;
    }
    
};

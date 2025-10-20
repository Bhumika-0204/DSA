class Solution {
public:
    bool isPalindrome(int x) {
    int org=x;
    long long revno=0;
    if(x<0) return false;
    while(x!=0){
        long long lastdigit=x%10;
         x=x/10;
         revno=(revno*10)+lastdigit;
    }
    if(revno==org) return true;
    else return false;
    
}
};
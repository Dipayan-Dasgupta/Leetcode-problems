class Solution {
public:
    int countHomogenous(string s) {
      int len = s.length() , i = 0 ;
      long long int mod = 1e9 + 7 , ans = 0 ;

     while(i < len){
       if(i + 1 < len){
          if(s[i] == s[i + 1]){
              long long int cnt = 0 ;
             while(i + 1 < len && s[i] == s[i + 1]){
                 cnt++ ;
                 i += 1 ;
             }
             cnt += 1 ;
             ans = (ans + (cnt * (cnt + 1)) / 2) % mod ;
             i += 1 ;
          }
          else{
             ans += 1 ;
             i += 1 ;
          }
       }
       else if(i + 1 == len){
           ans += 1 ;
           i += 1 ;
        }
      }
      return ans % mod ;
    }
};
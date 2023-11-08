class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdis = abs(sx - fx) ;
        int ydis = abs(fy - sy) ;

        if(xdis == 0 && ydis == 0 && t == 1) return false ;

        return t >= max(xdis , ydis) ;
    }
};
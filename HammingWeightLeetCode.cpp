class Solution {
public:
    int hammingWeight(uint32_t n) {

        return recur(n);
        
    }
    int recur(uint32_t n){
        if(n==0)return 0;

        else return (1&n) +recur((int)(n/2));
    }
};

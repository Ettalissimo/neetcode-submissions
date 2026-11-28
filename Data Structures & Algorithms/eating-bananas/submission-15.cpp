class Solution {
public:
    long calcul_sum(vector<int>& piles, int k){
            long sum_hours = 0;
            for(int i = 0 ; i < piles.size(); i++){
                int temp = piles[i]/k;
                int rest = piles[i]%k;
                if (rest != 0) {rest = 1;}
                sum_hours = sum_hours + (temp + rest);
            }
            return sum_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int last = *max_element(piles.begin(),piles.end());
        int first = 1;
        int res = last;
        while(first <= last){
            int mid = (last + first)/2 ;
            long sum = calcul_sum(piles, mid);
            if (h >= sum){
                res = min(mid,res);
                last =  mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return res;
    }
};

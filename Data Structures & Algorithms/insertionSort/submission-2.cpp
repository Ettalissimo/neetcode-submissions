// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:

    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> sol = {pairs};
        if(pairs.empty()){
            return {};
        }
        int left = 0, right = 1, cur = 1;
        Pair temp = pairs[0];
        while(cur < pairs.size()){
            right = cur; left = cur - 1;
            while(pairs[right].key < pairs[left].key and left>=0 and right>0){
                temp = pairs[left];
                pairs[left] = pairs[right];
                pairs[right] = temp;
                if (left != 0){
                left--;right--;
                }
            }
            cur++;
            sol.push_back(pairs);
        }
        return sol;
    }

    /*vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> sol = {pairs};
        int left = 0, right = 1, cur = 1;
        Pair temp = pairs[0];
        Pair temp2 = pairs[0];

        while(cur < pairs.size()-1) {
            right = cur;
            left = cur - 1;
            while( pairs[right].key < pairs[left].key and left > 0 ){
                left--;
                if(pairs[right].key > pairs[left].key){
                    temp = Pair(pairs[right].key , pairs[right].value);
                }
            }
            for (int i = cur; i > left+1 ; i--){
                temp2 = pairs[i+1]
                pairs[i+1] = pairs[i];
            }
            pairs[left+1] = temp;
            cur++;
            sol.push_back(pairs);
        }
        return sol;
    }*/
};

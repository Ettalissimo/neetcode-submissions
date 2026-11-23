/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int first = 1; int last = n;
        int mid,g_mid;
        while(first < last){
            mid = (first + last)/2;
            g_mid =  guess(mid);
            if (g_mid == 0 ){
                return mid;
            } else if (g_mid == -1){
                last = mid;
            } else if (g_mid == 1){
                first = mid + 1;
            }
        }
    }
};
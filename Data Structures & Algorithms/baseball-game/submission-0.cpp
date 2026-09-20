class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score = {};
        for (int i = 0; i < operations.size(); ++i){ 
            if (operations[i] == "+"){
                int added = score[score.size()-1]+score[score.size()-2];
                score.push_back(added);
                }
            else if (operations[i] == "D"){
                int added = score[score.size()-1]*2;
                score.push_back(added);
                }
            else if (operations[i] == "C"){
                score.pop_back();
                }
            else {
                score.push_back(stoi(operations[i]));
                };
        };
        int sum = 0;
        for(int i =0; i< score.size(); ++i){
            sum+=score[i];
        }
        return sum;
    }
};
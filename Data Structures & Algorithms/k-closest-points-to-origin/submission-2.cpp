class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,float>> distance;
        vector<vector<int>> res;

        for (int i=0 ; i < points.size(); i++){
            distance.push_back({i,sqrt(points[i][0]*points[i][0]  + points[i][1]*points[i][1])});
        }
        sort(distance.begin(),distance.end(),[](const auto& p1, const auto& p2){return p1.second < p2.second;} );
        for (const auto& p: distance){
            cout << p.first << "+" << p.second << "\n";
        }
        int i = 0;
        for (const auto& p: distance){
            if(i == k){ break;}
            res.push_back(points[p.first]);
            i++;
        }
        return res;
    }
};

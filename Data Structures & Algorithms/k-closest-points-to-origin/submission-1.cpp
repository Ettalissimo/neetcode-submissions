class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // val = sqrt((x1 - x2)^2 + (y1 - y2)^2); 
        // [[1,3],[2,4]]
        vector<pair<int,float>> distance;
        vector<vector<int>> res;
        float val ;

        for (int i=0 ; i < points.size(); i++){
            val = sqrt(points[i][0]*points[i][0]  + points[i][1]*points[i][1]);
            distance.push_back({i,val});
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

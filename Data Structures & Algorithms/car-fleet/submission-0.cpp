class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        stack<double> s;
        for(pair<int,int> p: v){
            double time = (double)(target-p.first)/(double)p.second;
            if(s.empty()){
                s.push(time);
            }
            else if(!s.empty() && time>s.top()){
                s.push(time);
            }
        }
        return s.size();
    }
};

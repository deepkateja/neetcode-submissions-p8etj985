class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        for(char c:tasks){
            cnt[c-'A']++;
        }
        priority_queue<int> pq;
        int time = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> backup;
        for(int i:cnt){
            if(i!=0){
                pq.push(i);
            }
        }
        while(!pq.empty()||!backup.empty()){
            time++;
            while(!backup.empty() && backup.top().first<=time){
                pair<int,int> p = backup.top();
                backup.pop();
                pq.push(p.second);
            }
            if(!pq.empty()){
                int val = pq.top();
                pq.pop();
                if(val!=1){
                    backup.push({time+n+1,val-1});
                }
            }
        }
        return time;
    }
};

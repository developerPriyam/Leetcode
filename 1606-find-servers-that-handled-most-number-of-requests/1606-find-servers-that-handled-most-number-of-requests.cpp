class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> av_ser;
        typedef pair<int,int> p;
        for(int i=0;i<k;i++){
            av_ser.insert(i);
        }
        priority_queue<p,vector<p>,greater<p>> busy;
        vector<int> count(k,0);
        vector<int> ans;
        int n=arrival.size();

        for(int i=0;i<n;i++){
            int time=arrival[i];
            while(!busy.empty()&&busy.top().first<=time){
                int server=busy.top().second;
                busy.pop();
                av_ser.insert(server);
            }
            int target=i%k;
            auto it=av_ser.lower_bound(target);
            if(it==av_ser.end()){it=av_ser.begin();}
            if(av_ser.empty()) continue;
            int ts=*it;
            av_ser.erase(it);
            busy.push({time+load[i],ts});
            count[ts]++;
        }

        int maxN=*max_element(begin(count),end(count));
        for(int i=0;i<k;i++){
            if(count[i]==maxN){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
class Solution {
	unordered_map<string, multiset<string>> G;
	vector<string> R;
public:
	vector<string> findItinerary(vector<vector<string>>& T) {
		for (auto &t : T)
			G[t[0]].insert(t[1]);
		dfs("JFK");
		return vector<string>(R.rbegin(), R.rend());
	}

	void dfs(const string &s) {
		while (!G[s].empty()) {
			auto it = G[s].begin();
			auto n = *it;
			G[s].erase(it);
			dfs(n);
		}
		R.push_back(s);
	}
};

///////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    unordered_map<string, multiset<string>> edges;
    vector<string> route;
    void dfs(string cur){
        while(!edges[cur].empty()){
            string next = *edges[cur].begin();
            edges[cur].erase(edges[cur].begin());
            dfs(next);
        }
        route.insert(route.begin(), cur);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(vector<string>& ticket : tickets){
            edges[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        return route;
    }
};

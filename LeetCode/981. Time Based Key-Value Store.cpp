// rumman

#define psi pair<string, int>

class TimeMap
{
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<psi>> um;

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        if (um.find(key) == um.end())
        {
            // not found
            um[key] = vector<psi>();
        }
        um[key].push_back(make_pair(value, timestamp));
    }

    string get(string key, int timestamp)
    {
        vector<psi> &v = um[key];
        int lo, hi, mid;

        lo = 0;
        hi = v.size() - 1;
        string ans;

        // cout << lo << " " << hi << endl;

        while (lo <= hi)
        {
            // cout << lo << " " << hi <<  endl;
            mid = lo + (hi - lo) / 2;
            if (v[mid].second <= timestamp)
            {
                lo = mid + 1;
                ans = v[mid].first;
            }
            else if (v[mid].second > timestamp)
            {
                hi = mid - 1;
            }
            // else {
            //     ans = v[mid].first;
            //     break;
            // }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
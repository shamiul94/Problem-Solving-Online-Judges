#include <bits/stdc++.h>

using namespace std;

// works - 89%, 22%

class LRUCache
{
public:
    int capacity;
    unordered_map<int, int> cache;
    list<int> used;
    unordered_map<int, list<int>::iterator> used_pos;

    LRUCache(int _capacity)
    {
        capacity = _capacity;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            // EXISTS IN CACHE
            used.erase(used_pos[key]);
            used.push_front(key);
            used_pos[key] = used.begin();
            return cache[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            // key doesn't exist
            if (used.size() == capacity)
            {
                // remove the least recent
                cache.erase(used.back());
                used_pos.erase(used.back());
                used.pop_back();
            }

            used.push_front(key);
            cache[key] = value;
            used_pos[key] = used.begin();
        }
        else
        {
            // key exists in cache
            used.erase(used_pos[key]);

            used.push_front(key);
            used_pos[key] = used.begin();
            cache[key] = value;
        }
    }
};

// 12%, 52%

////////////

class LRUCache
{
public:
    int capacity;
    unordered_map<int, int> cache;
    list<int> used;

    LRUCache(int _capacity)
    {
        capacity = _capacity;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            // EXISTS IN CACHE
            used.erase(find(used.begin(), used.end(), key));
            used.push_front(key);
            return cache[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            // key doesn't exist
            if (used.size() == capacity)
            {
                // remove the least recent
                cache.erase(used.back());
                used.pop_back();
            }

            used.push_front(key);
            cache[key] = value;
        }
        else
        {
            // key exists in cache
            used.erase(find(used.begin(), used.end(), key));

            used.push_front(key);
            cache[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// doesnt work
class LRUCache
{
public:
    int cap;
    unordered_map<int, pair<int, int>> map; // map1[key] = <value, time_last_used>
    unordered_map<int, int> reverseMap;     //  rmap[time] = key
    int lastTime;

    LRUCache(int capacity)
    {
        cap = capacity;
        lastTime = 1;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {   // found
            //            cout << map[key].first << " " << map[key].second << endl;
            cout << "get -> "
                 << "key = " << key << " val = " << map[key].first << endl;
            pair<int, int> p;
            p = map[key];
            int currentTime = p.second;
            reverseMap.erase(currentTime);
            reverseMap[lastTime] = key;
            map[key].second = lastTime;
            lastTime++;
            return map[key].first;
        }
        else
        {
            cout << "get -> "
                 << "key = " << key << " val = " << -1 << endl;
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        { // already in the map
            pair<int, int> p;
            p = map[key];
            int currentTime = p.second;
            reverseMap.erase(currentTime);
            reverseMap[lastTime] = key;
            map[key].first = value;
            map[key].second = lastTime;
            lastTime++;
            return;
        }

        pair<int, int> p;
        p.first = value;
        p.second = lastTime;

        cout << "put -> " << key << "," << value << " : ";
        int toDeletesTimestamp = lastTime - cap; // this time stamp's key should be deleted
        if (toDeletesTimestamp >= 1)
        {
            // delete
            int keyIdxToDelete = reverseMap[toDeletesTimestamp];
            map.erase(keyIdxToDelete);
            cout << "deleted -> " << keyIdxToDelete << " : ";
        }

        reverseMap[lastTime] = key;
        map[key] = p;
        cout << "new time -> " << lastTime << " "
             << " key-> " << key << endl;

        lastTime++;
    }
};

int main()
{
    //    LRUCache *l = new LRUCache(4);
    //    cout << l->get(1) << endl;
    //    l->put(2, 303);
    //    l->put(6, 467);
    ////    l->put(3, 304);
    //    l->put(4, 305);
    //    l->put(1, 305);
    //    l->put(5, 305);
    //    cout << l->get(2) << endl;
    //    cout << l->get(3) << endl;
    //    cout << l->get(4) << endl;
    //    cout << l->get(5) << endl;

    LRUCache cache = LRUCache(10);

    //    cache.put(1, 1);
    //    cache.put(2, 2);
    //    cache.get(1);       // returns 1
    //    cache.put(3, 3);    // evicts key 2
    //    cache.get(2);       // returns -1 (not found)
    //    cache.put(4, 4);    // evicts key 1
    //    cache.get(1);       // returns -1 (not found)
    //    cache.get(3);       // returns 3
    //    cache.get(4);       // returns 4
    //////////////////////////////////////////////////////////////
    // cache.put(1, 1);
    //    cache.put(2, 2);
    cache.get(2);    // returns 1
    cache.put(2, 6); // evicts key 2
    cache.get(1);    // returns -1 (not found)
    cache.put(1, 5); // evicts key 1
    cache.put(1, 2); // evicts key 1
    cache.get(1);    // returns -1 (not found)
    cache.get(2);    // returns 3
                     //    cache.get(4);       // returns 4
    /////////////////////////////////////////

    cache.put(10, 13);
    cache.put(3, 17);
    cache.put(6, 11);
    cache.put(10, 5);
    cache.put(9, 10);
    cache.get(13);
    cache.put(2, 19);
    cache.get(2);
    cache.get(3);
    cache.put(5, 25);
    cache.get(8);
    cache.put(9, 22);
    cache.put(5, 5);
    cache.put(1, 30);
    cache.get(11);
    cache.put(9, 12);
    cache.get(7);
    cache.get(5);
    cache.get(8);
    cache.get(9);
    cache.put(4, 30);
    cache.put(9, 3);
    cache.get(9);
    cache.get(10);
    cache.get(10);
    cache.put(6, 14);
    cache.put(3, 1);
    cache.get(3);
    cache.put(10, 11);
    cache.get(8);
    cache.put(2, 14);
    cache.get(1);
    cache.get(5);
    cache.get(4);
    cache.put(11, 4);
    cache.put(12, 24);
    cache.put(5, 18);
    cache.get(13);
    cache.put(7, 23);
    cache.get(8);
    cache.get(12);
    cache.put(3, 27);
    cache.put(2, 12);
    cache.get(5);
    cache.put(2, 9);
    cache.put(13, 4);
    cache.put(8, 18);
    cache.put(1, 7);
    cache.get(6);
    cache.put(9, 29);
    cache.put(8, 21);
    cache.get(5);
    cache.put(6, 30);
    cache.put(1, 12);
    cache.get(10);
    cache.put(4, 15);
    cache.put(7, 22);
    cache.put(11, 26);
    cache.put(8, 17);
    cache.put(9, 29);
    cache.get(5);
    cache.put(3, 4);
    cache.put(11, 30);
    cache.get(12);
    cache.put(4, 29);
    cache.get(3);
    cache.get(9);
    cache.get(6);
    cache.put(3, 4);
    cache.get(1);
    cache.get(10);
    cache.put(3, 29);
    cache.put(10, 28);
    cache.put(1, 20);
    cache.put(11, 13);
    cache.get(3);
    cache.put(3, 12);
    cache.put(3, 8);
    cache.put(10, 9);
    cache.put(3, 26);
    cache.get(8);
    cache.get(7);
    cache.get(5);
    cache.put(13, 17);
    cache.put(2, 27);
    cache.put(11, 15);
    cache.get(12);
    cache.put(9, 19);
    cache.put(2, 15);
    cache.put(3, 16);
    cache.get(1);
    cache.put(12, 17);
    cache.put(9, 1);
    cache.put(6, 19);
    cache.get(4);
    cache.get(5);
    cache.get(5);
    cache.put(8, 1);
    cache.put(11, 7);
    cache.put(5, 2);
    cache.put(9, 28);
    cache.get(1);
    cache.put(2, 2);
    cache.put(7, 4);
    cache.put(4, 22);
    cache.put(7, 24);
    cache.put(9, 26);
    cache.put(13, 28);
    cache.put(11, 26);

    //    ["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]
    //    [[10],[10,13],[3,17],[6,11],[10,5],[9,10],
    // [13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],
    // [1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],
    // [9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],
    // [1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],
    // [12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],
    // [9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],
    // [11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],
    // [3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],
    // [11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],
    // [13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],
    // [12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],
    // [1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]
}
//["LRUCache","get","put","get","put","put","get","get"]
//[[2],        [2],[2,6],[1],[1,5],[1,2],[1],[2]]
class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        vector<int> starts;
        vector<int> ends;

        for (int i = 0; i < intervals.size(); i++)
        {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0;
        int currEnd = 0;

        for (int i = 0; i < starts.size(); i++)
        {
            if (starts[i] < ends[currEnd])
            {
                rooms++;
            }
            else if (starts[i] >= ends[currEnd])
            {
                currEnd++;
            }
        }
        return rooms;
    }
};
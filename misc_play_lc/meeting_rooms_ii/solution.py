class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort()
        r = []
        heappush(r, intervals[0][1])
        for i in intervals[1:]:
            if r[0] <= i[0]:
                heappop(r)
            heappush(r, i[1])
        return len(r) 
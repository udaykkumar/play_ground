"""
Created on Jun 2, 2021

@author: kumarkud
"""
from pickle import TRUE
from heapq import heappush
from _heapq import heappop


class meting_rooms_II:
    """
    classdocs https://leetcode.com/problems/meeting-rooms-ii/
    """

    def __init__(self):
        """
        Constructor
        """

    def minMeetingRooms(self, intervals: list[list[int]]) -> int:
        if not intervals:
            return 0

        intervals.sort()

        # End time
        free_rooms = []
        heappush(free_rooms, intervals[0][1])

        for i in intervals[1:]:

            # Here is i[start] time is less than the earlier finish time
            # for those meetings in heap
            # insert this in to heap
            if free_rooms[0] <= i[0]:
                heappop(free_rooms)

            heappush(free_rooms, i[1])

        return len(free_rooms)


meting_rooms_II().minMeetingRooms([[0, 30], [5, 10], [15, 20]])
meting_rooms_II().minMeetingRooms([[7, 10], [2, 4]])

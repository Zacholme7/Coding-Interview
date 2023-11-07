# Link: https://leetcode.com/problems/seat-reservation-manager/?envType=daily-question&envId=2023-11-06
# Difficulty: Medium
# Date Solved: Nov 6, 2023

import heapq
def __init__(self, n: int):
    self.heap = list(range(1, n + 1))

def reserve(self) -> int:
    return heapq.heappop(self.heap)

def unreserve(self, seatNumber: int) -> None:
    heapq.heappush(self.heap, seatNumber)

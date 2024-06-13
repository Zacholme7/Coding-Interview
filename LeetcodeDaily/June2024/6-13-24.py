# link: https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/?envType=daily-question&envId=2024-06-13
# difficulty: easy
# date solved: june 13, 2024

class Solution:
    def minMovesToSeat(self, seats, students):
        # sort both arrays
        seats.sort()
        students.sort()

        return sum(abs(seat - student) for seat, student in zip(seats, students))

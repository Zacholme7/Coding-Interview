# link: https://leetcode.com/problems/time-needed-to-buy-tickets/?envType=daily-question&envId=2024-04-09
# difficulty: easy
# date solved: april 9, 2024
# writeup: simple easy problem, while the tickets k still has tickets, just keep looping through and decrement a
# ticket from everyone while adding the seconds. if the k is at zero then we just return the seconds

class Solution:
    def timeRequiredToBuy(self, tickets, k):
        seconds = 0
        while tickets[k] > 0:
            for idx in range(len(tickets)):
                if tickets[idx] > 0:
                    tickets[idx] -= 1
                    seconds += 1
                    if idx == k and tickets[k] == 0:
                        return seconds
        return seconds

# link: https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09
# difficulty: medium
# date solved: july 9, 2024

class Solution:
    def averageWaitingTime(self, customers):
        t = 0 
        total = 0  

        for arrival, order in customers:
            if t > arrival:
                total += t - arrival
            else:
                t = arrival
            total += order
            t += order

        return total / len(customers)











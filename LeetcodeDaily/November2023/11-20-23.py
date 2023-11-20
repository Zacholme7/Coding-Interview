# Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/?envType=daily-question&envId=2023-11-20
# Difficulty: Medium
# Date Solved: November 20, 2023

class Solution:
    def garbageCollection(self, garbage, travel):
        total = 0
        n = len(garbage)

        # go through all of the garbage types
        for c in "MPG":
            mx = 0
            current = 0

            # count for the first location
            current += garbage[0].count(c)
            mx = max(current, mx)

            # go through the rest of the locations
            for i in range(1, n):
                current += travel[i - 1] # add the travel distance

                # if there is garbage at this location
                if c in garbage[i]:
                    # count the amount of garbage and add it to the current
                    current += garbage[i].count(c)

                    # keep track of the max to add to the total at the end
                    # this will track the cost up to the current location
                    mx = max(current, mx)

            # add the max for the specified type to the total
            total += mx

        return total


        



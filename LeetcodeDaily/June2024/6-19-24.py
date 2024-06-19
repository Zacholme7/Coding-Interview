# link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/?envType=daily-question&envId=2024-06-19
# difficulty: medium
# date solved: june 19, 2024

# monotonic property: key insight that leads to bin search is that if it is not possible on day d, then it is not possible on any day less
# than d and vise versa

class Solution:
    def minDays(self, bloomDay, m, k):
        if m * k > len(bloomDay):
            return -1

        def canMakeBouquets(bloomDay, m, k, day):
            total = 0
            flowers = 0
            for b in bloomDay:
                if b <= day:
                    flowers += 1
                    if flowers == k:
                        total += 1
                        flowers = 0
                else:
                    flowers = 0
                if total >= m:
                    return True
            return False

        low, high = 1, max(bloomDay)
        while low < high:
            mid = (low + high) // 2
            if canMakeBouquets(bloomDay, m, k, mid):
                high = mid
            else:
                low = mid + 1

        return low

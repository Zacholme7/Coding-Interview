# link: https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
# difficulty: medium
# date solved: february 7, 2024

class Solution:
    def frequencySort(self, s):
        freq = {}
        for char in s:
            if char in freq:
                freq[char] += 1
            else:
                freq[char] = 1

        sorted_chars = sorted(freq.keys(), key=lambda x: (-freq[x], x))
        return "".join(char * freq[char] for char in sorted_chars)


if __name__ == "__main__":
    sol = Solution()
    print(sol.frequencySort("tree"))
    print(sol.frequencySort("cccaaa"))
    print(sol.frequencySort("Aabb"))

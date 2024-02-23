# link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23
# difficulty: medium
# date solved: february 23, 2024
from collections import defaultdict
import deque


class Solution:
    def findCheapestPrice(self, n, flights, src, dst, k):
        adjList = defaultdict(list)
        visited = [float("inf")]
        visited[src] = 0

        for flight in flights:
            start, end, price = flight
            adjList[start].append((end, price))

        queue = deque([src, 0])
        k += 1

        while k > 0 and queue:
            size = len(queue)
            while size > 0:
                curr_node, curr_price = queue.popleft()
                for neighbor, price in adjList[curr_node]:
                    new_price = curr_price + price
                    if new_price < visited[neighbor]:
                        visited[neighbor] = new_price
                        queue.append((neighbor, new_price))
                size -= 1
            k -= 1
        return visited[dst] if visited[dst] != float("inf") else -1


if __name__ == "__main__":
    sol = Solution()
    print(sol.findCheapestPrice(n=4, flights=[[0, 1, 100], [1, 2, 100], [2, 0, 100], [1, 3, 600], [2, 3, 200]], src=0, dst=3, k=1))
    print(sol.findCheapestPrice(n=3, flights=[[0, 1, 100], [1, 2, 100], [0, 2, 500]], src=0, dst=2, k=1))
    print(sol.findCheapestPrice(n=3, flights=[[0, 1, 100], [1, 2, 100], [0, 2, 500]], src=0, dst=2, k=0))

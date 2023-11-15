# link: https://leetcode.com/problems/bus-routes/?envType=daily-question&envId=2023-11-12
# difficulty: Hard
# date solved: November 12, 2023

import collections
class Solution:
    def numBusesToDestination(self, routes, source, target):
        to_routes = collections.defaultdict(set)
        for i, route in enumerate(routes):
            for j in route:
                to_routes[j].add(i)
        bfs = [(source, 0)]
        seen = set([source])
        for stop, bus in bfs:
            if stop == target: return bus
            for i in to_routes[stop]:
                for j in routes[i]:
                    if j not in seen:
                        bfs.append((j, bus + 1))
                        seen.add(j)
                routes[i] = []  # seen route
        return -1

        
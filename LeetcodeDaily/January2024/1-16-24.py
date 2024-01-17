# https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16
# difficulty: medium
# date solved: january 16, 2024

import random


class RandomizedSet:
    def __init__(self):
        self.set = set()

    def insert(self, val):
        if val not in self.set:
            self.set.add(val)
            return True
        return False

    def remove(self, val):
        if val in self.set:
            self.set.remove(val)
            return True
        return False

    def getRandom(self):
        return random.choice(tuple(self.set))

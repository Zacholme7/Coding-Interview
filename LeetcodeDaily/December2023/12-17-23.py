# link: https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2023-12-17
# difficulty: medium
# date solved: december 17, 2023

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.mp = {}
        self.data = defaultdict(list)
        for food, cuisine, rating in zip(foods, cuisines, ratings): 
            self.mp[food] = (cuisine, rating)
            heapq.heappush(self.data[cuisine],(-rating, food))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine, rating = self.mp[food]
        self.mp[food] = cuisine, newRating
        heapq.heappush(self.data[cuisine],(-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        while self.data[cuisine] and -self.data[cuisine][0][0]!=self.mp[self.data[cuisine][0][1]][1]:
            heapq.heappop(self.data[cuisine])
        return self.data[cuisine][0][1]

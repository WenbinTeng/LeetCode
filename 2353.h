#include <vector>
#include <string>
#include <set>
#include <unordered_map>

class FoodRatings {
public:
    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodInfoDict[foods[i]] = {cuisines[i], -ratings[i]};
            cuisineRatingDict[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(std::string food, int newRating) {
        auto& [cuisine, oldRating] = foodInfoDict[food];
        auto& s = cuisineRatingDict[cuisine];
        s.erase({oldRating, food});
        s.insert({-newRating, food});
        oldRating = -newRating;
    }
    
    std::string highestRated(std::string cuisine) {
        return cuisineRatingDict[cuisine].begin()->second;
    }

private:
    std::unordered_map<std::string, std::pair<std::string, int>> foodInfoDict;
    std::unordered_map<std::string, std::set<std::pair<int, std::string>>> cuisineRatingDict;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
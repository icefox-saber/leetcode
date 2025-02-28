/*
 * @lc app=leetcode.cn id=2353 lang=cpp
 * @lcpr version=30204
 *
 * [2353] Design a Food Rating System
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <cassert>
#include <ccomplex>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <condition_variable>
#include <csetjmp>
#include <csignal>
#include <cstdalign>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class FoodRatings {
  struct cuisines_rate {
    string cuisine;
    int rate;
  };

  unordered_map<string, cuisines_rate> food_to_cuisines_and_rate;
  unordered_map<string, map<int, set<string>>> cursines_to_rate_to_foods;

public:
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings)
      : food_to_cuisines_and_rate(foods.size()),
        cursines_to_rate_to_foods(foods.size()) {
    for (size_t i = 0; i < foods.size(); i++) {
      food_to_cuisines_and_rate[foods[i]] = {cuisines[i], ratings[i]};
      cursines_to_rate_to_foods[cuisines[i]][ratings[i]].emplace(foods[i]);
    }
  }

  void changeRating(string food, int newRating) {
    cuisines_rate &cr = food_to_cuisines_and_rate[food];
    const cuisines_rate oldcr = cr;
    cr.rate = newRating;
    auto &rate_to_foods = cursines_to_rate_to_foods[oldcr.cuisine];
    auto &foods = rate_to_foods[oldcr.rate];
    foods.erase(food);
    if (foods.empty()) {
      rate_to_foods.erase(oldcr.rate);
    }
    rate_to_foods[cr.rate].emplace(food);
  }

  string highestRated(string cuisine) {
    const auto &rate_to_foods = cursines_to_rate_to_foods[cuisine];
    const auto &foods = rate_to_foods.rbegin()->second;
    return *foods.begin();
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end

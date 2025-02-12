// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=913 lang=cpp
 * @lcpr version=30204
 *
 * [913] Cat and Mouse
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
class Solution {
public:
#define cat true
#define mouse false
#define catwin 2
#define mousewin 1
#define draw 0
#define visited 3
  // 不能进洞
  int catMouseGame(vector<vector<int>> &g) {
    int n = g.size();
    vector res(n, vector(n, vector(2, draw)));
    vector degreed(n, vector(n, vector(2, 0)));
    vector<tuple<int, int, int>> q;

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 1; j < n; j++) {
        degreed[i][j][0] = g[i].size();
        degreed[i][j][1] = g[j].size();
      }
      for (auto c : g[0]) {

        --degreed[i][c][1];
      }
    };

    for (size_t i = 1; i < n; i++) {
      res[0][i][cat] = mousewin;
      q.emplace_back(0, i, cat);
      res[i][i] = vector(2, catwin);
      q.emplace_back(i, i, cat);
      q.emplace_back(i, i, mouse);
    }

    while (!q.empty()) {
      auto now = q.back();
      q.pop_back();
      auto [m, c, t] = now;
      auto winner = res[m][c][t];

      if (t == cat) {             // 本轮到猫行动
        if (winner == mousewin) { // 当前老鼠赢
          for (auto prem : g[m]) {
            if (res[prem][c][!t] == draw) {
              res[prem][c][!t] = mousewin;
              q.emplace_back(prem, c, !t);
            }
          }
        } else // 猫赢
        {
          for (auto prem : g[m]) {
            if (res[prem][c][!t] == draw) {
              if (!--degreed[prem][c][!t]) {
                res[prem][c][!t] = catwin;
                q.emplace_back(prem, c, !t);
              }
            }
          }
        }
      } else { // 本轮到老鼠行动
        auto winner = res[m][c][t];
        if (winner == catwin) { // 当前猫赢
          for (auto prec : g[c]) {
            if (prec == 0) {
              continue;
            }

            if (res[m][prec][!t] == draw) {
              res[m][prec][!t] = catwin;
              q.emplace_back(m, prec, !t);
            }
          }
        } else // 老鼠赢
        {
          for (auto prec : g[c]) {
            if (prec == 0) {
              continue;
            }
            if (res[m][prec][!t] == draw) {
              if (!--degreed[m][prec][!t]) {
                res[m][prec][!t] = mousewin;
                q.emplace_back(m, prec, !t);
              }
            }
          }
        }
      }
    }
    return res[1][2][0];
  }
  // code by sachin
};
// @lc code=end

/*
// @lcpr case=start
// [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[0],[3],[0,2]]\n
// @lcpr case=end

 */

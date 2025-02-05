// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30204
 *
 * [4] Median of Two Sorted Arrays
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
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > nums2.size())
      return findMedianSortedArrays(nums2, nums1);
    if (n1 == 0)
      return nums2.size() % 2 ? nums2[n2 / 2]
                              : (nums2[n2 / 2] + nums2[n2 / 2 - 1]) / 2.0;
    if (n1 == 0)
      return nums1.size() % 2 ? nums1[n1 / 2]
                              : (nums1[n1 / 2] + nums1[n1 / 2 - 1]) / 2.0;

    int left = 0, right = n1;
    int cut1, cut2;
    int l1, l2, r1, r2;
    int partition = (n1 + n2 + 1) / 2;
    do {
      cut1 = (left + right) / 2;
      cut2 = partition - cut1;

      l1 = (cut1 == 0 ? INT_MIN : nums1[cut1 - 1]);
      l2 = (cut2 == 0 ? INT_MIN : nums2[cut2 - 1]);
      r1 = (cut1 >= n1 ? INT_MAX : nums1[cut1]);
      r2 = (cut2 >= n2 ? INT_MAX : nums2[cut2]);
      if (l1 <= r2 && l2 <= r1) {
        return (n1 + n2) % 2 ? max(l1, l2) : (max(l1, l2) + min(r1, r2)) / 2.0;
      }

      if (l1 > r2) {
        right = cut1 - 1;
      } else {
        left = cut1 + 1;
      }

    } while (left <= right);

    return 0.0;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

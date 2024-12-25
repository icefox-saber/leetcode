// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30204
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start

template <typename T>
int min(const std::vector<T> &vec)
{
    int p = 0;
    std::size_t size = vec.size();
    for (size_t i = 1; i < size; i++)
    {
        if (vec[p] > vec[i])
        {
            p = i;
        }
    }

    return p;
}


template <typename T> int partition(std::vector<T> &vec, int l, int r) {
  T pivot = vec[r];
  int i = l, j;
  for (j = l; j < r; j++) {
    if (vec[j] <= pivot) {
      std::swap(vec[i], vec[j]);
      i++;
    }
  }
  assert(j == r);
  std::swap(vec[i], vec[j]);
  return i;
}

template <typename T> void quickSort(std::vector<T> &vec, int l, int r) {
  if (l > r) {
    return;
  }

  int pivot_index = partition(vec, l, r);
  quickSort(vec, l, pivot_index - 1);
  quickSort(vec, pivot_index + 1, r);
}

template <typename T> void quickSort(std::vector<T> &vec) {
  quickSort(vec, 0, vec.size() - 1);
}

template <typename T> int random_partition(std::vector<T> &vec, int l, int r) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(l, r);
  int p = dis(gen);
  std::swap(vec[r], vec[p]);
  return partition(vec, l, r);
}

template <typename T> void random_quickSort(std::vector<T> &vec, int l, int r) {
  if (l > r) {
    return;
  }

  int pivot_index = random_partition(vec, l, r);
  random_quickSort(vec, l, pivot_index - 1);
  random_quickSort(vec, pivot_index + 1, r);
}

template <typename T> void random_quickSort(std::vector<T> &vec) {
  random_quickSort(vec, 0, vec.size() - 1);
}

template <typename T>
int min(const std::vector<T> &vec, std::size_t l, std::size_t r)
{
    std::size_t p = l;
    std::size_t size = vec.size();
    assert(r < size);
    for (size_t i = l + 1; i <= r; i++)
    {
        if (vec[p] > vec[i])
        {
            p = i;
        }
    }

    return p;
}


template <typename T>
int partition(std::vector<T> &vec, int l, int r, int p)
{
    std::swap(vec[r], vec[p]);
    return partition(vec, l, r);
}

/// @brief select the ith element in vec
/// @tparam T element type
/// @param vec element vec
/// @param i the order of the element(begin at 0)
/// @param l left bounds index of vec
/// @param r right bounds index of vec
/// @return the index of the ith element
template <typename T>
int select5(std::vector<T> &vec, int i, int l, int r)
{
    assert(i < r - l + 1);
    while (((r - l + 1) % 5) != 0)
    {
        int mindex = min(vec, l, r);
        std::swap(vec[mindex], vec[l]);

        if (i == 0)
        {
            return l;
        }
        l++;
        i--;
    }

    assert(((r - l + 1) % 5) == 0);

    int g = (r - l + 1) / 5;

    for (int j = l, k = 0; k < g; j++, k++)
    {
        std::vector<T> vec_5 = {vec[j], vec[j + g], vec[j + 2 * g], vec[j + 3 * g],
                                vec[j + 4 * g]};
        quickSort(vec_5);
        for (int i = 0; i < 5; i++)
        {
            vec[j + i * g] = vec_5[i];
        }
    }

    int x = select5(vec, g / 2, l + 2 * g, l + 3 * g - 1);

    int p = partition(vec, l, r, x);
    if (i == p - l)
    {
        return p;
    }

    else if (i > p - l)
    {
        return select5(vec, i - p + l - 1, p + 1, r);
    }

    else
    {
        return select5(vec, i, l, p - 1);
    }

    return -1;
}

/// @brief select the ith element in vec
/// @tparam T element type
/// @param vec element vec
/// @param i the order of the element(begin at 0)
/// @return the ith element
template <typename T>
T select5(const std::vector<T> &vec, std::size_t i)
{
    assert(i < vec.size());
    std::vector<T> copy = vec;
    int x = select5(copy, i, 0, copy.size() - 1);
    return copy[x];
}

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.end(), std::make_move_iterator(nums2.begin()), std::make_move_iterator(nums2.end()));
        int n1 =  select5<int>(nums1,nums1.size()/2);
        if (nums1.size()%2 == 0)
        {
            int n2 = select5<int>(nums1,nums1.size()/2-1);
            return double(n1+n2)/2.0;
        }
        return n1;
        
    }
};
// @lc code=end

/*
// @lcpr case=start
[1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

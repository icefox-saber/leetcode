/*
 * @lc app=leetcode.cn id=3305 lang=cpp
 *
 * [3305] 元音辅音字符串计数 I
 */

// @lc code=start
class Solution {
public:
  int countOfSubstrings(string word, int k) {

    auto isletter = [](char ch) {
      return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };
    auto count = [&word, isletter](int m) {
      int cons = 0;
      unordered_map<char, int> table;
      int res = 0;
      for (int beg = 0, end = 0; beg < word.size(); beg++) {

        while (end < word.size() && (table.size() != 5 || cons < m)) {
          if (isletter(word[end])) {
            table[word[end]]++;
          } else {
            cons++;
          }
          end++;
        }
        if (table.size() == 5 && cons >= m) {
          res += word.size() - end + 1;
        }
        if (isletter(word[beg])) {
          table[word[beg]]--;
          if (!table[word[beg]]) {
            table.erase(word[beg]);
          }
        } else {
          cons--;
        }
      }
      return res;
    };

    return count(k) - count(k + 1);
  }
};
// @lc code=end

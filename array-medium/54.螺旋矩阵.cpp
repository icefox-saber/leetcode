/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int i = 0, j = 0;
    const size_t n = matrix.size();
    const size_t m = matrix.front().size();
    const size_t nm = n * m;
    vector<int> res;
    int flag = 0; // 0,1,2,3
    int signal = 101;
    for (size_t k = 0; k < nm; k++) {
      res.push_back(matrix[i][j]);
      matrix[i][j] = signal;
      if (flag == 0) {
        if (j + 1 == m || matrix[i][j + 1] == signal) {
          i += 1;
          flag = (flag + 1) % 4;
        } else {
          ++j;
        }

      } else if (flag == 1) {
        if (i + 1 == n || matrix[i + 1][j] == signal) {
          j -= 1;
          flag = (flag + 1) % 4;
        } else {
          ++i;
        }
      } else if (flag == 2) {
        if (j - 1 < 0 || matrix[i][j - 1] == signal) {
          i -= 1;
          flag = (flag + 1) % 4;
        } else {
          --j;
        }
      } else if (flag == 3) {
        if (i - 1 < 0 || matrix[i - 1][j] == signal) {
          j += 1;
          flag = (flag + 1) % 4;
        } else {
          --i;
        }
      }
    }

    return res;
  }
};
// @lc code=end

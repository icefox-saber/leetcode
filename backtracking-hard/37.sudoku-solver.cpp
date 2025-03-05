/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30204
 *
 * [37] Sudoku Solver
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
  bool isvalid(vector<vector<char>> &board, int i, int j, char num) {
    int raw = i / 3 * 3, col = j / 3 * 3;
    for (int k = 0; k < 9; k++) {
      if (board[i][k] == num || board[k][j] == num)
        return false;

      for (int m = 0; m < 3; m++) {
        for (int x = 0; x < 3; x++) {
          if (board[raw + m][col + x] == num)
            return false;
        }
      }
    }

    return true;
  }

public:
  bool res(vector<vector<char>> &board, int i, int j) {
    if (i >= 9)
      return true;
    while (i < 9 && board[i][j] != '.') {
      if (j == 8)
        i++;
      j = (j + 1) % 9;
    }
    if (i >= 9)
      return true;
    for (int num = 0; num < 9; num++) {
      if (isvalid(board, i, j, num + '1')) {

        board[i][j] = num + '1';
        int ii = i, jj = j;
        if (jj == 8)
          ii++;
        jj = (jj + 1) % 9;
        if (res(board, ii, jj))
          return true;
        board[i][j] = '.';
      }
    }
    return false;
  }

  void solveSudoku(vector<vector<char>> &board) { res(board, 0, 0); }
};
// @lc code=end

/*
// @lcpr case=start
//
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=2296 lang=cpp
 * @lcpr version=30204
 *
 * [2296] Design a Text Editor
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
class TextEditor {
  string text;
  int cursor; // insert cusor, delete cursor-1,cursor =0:empty
public:
  TextEditor() : text(), cursor(0) {}

  void addText(string text) {
    this->text.insert(cursor, text);
    cursor += text.size();
  }

  int deleteText(int k) {
    if (k > cursor) {
      k = cursor;
    }
    cursor -= k;
    text.erase(cursor, k);
    return k;
  }

  string cursorLeft(int k) {
    if (k > cursor) {
      k = cursor;
    }
    cursor -= k;
    int num = min(cursor, 10);
    string res(text, cursor - num, num);
    return res;
  }

  string cursorRight(int k) {
    if (k + cursor > text.size()) {
      k = text.size() - cursor;
    }
    cursor += k;
    int num = min(cursor, 10);
    string res(text, cursor - num, num);
    return res;
  }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// @lc code=end

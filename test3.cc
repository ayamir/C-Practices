#include <iostream>
#include <string>

using namespace std;

// Function to check if a substring is balanced
bool isBalancedSubstring(const string &s, int start, int end) {
  int count[26] = {0}; // Count array for lowercase letters

  for (int i = start; i <= end; ++i) {
    count[s[i] - 'a']++;
  }

  int distinctChars = 0;
  for (int i = 0; i < 26; ++i) {
    if (count[i] > 0) {
      distinctChars++;
    }
  }

  if (distinctChars != 2) {
    return false;
  }

  int freq1 = 0, freq2 = 0;
  for (int i = 0; i < 26; ++i) {
    if (count[i] > 0) {
      if (freq1 == 0) {
        freq1 = count[i];
      } else {
        freq2 = count[i];
      }
    }
  }

  return freq1 == freq2;
}

// Function to count balanced substrings
int countBalancedSubstrings(const string &s) {
  int count = 0;
  int n = s.length();

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (isBalancedSubstring(s, i, j)) {
        count++;
      }
    }
  }

  return count;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int result = countBalancedSubstrings(s);
  cout << result << endl;

  return 0;
}

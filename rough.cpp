#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int MOD = 1e9 + 7;
const int ALPHABET_SIZE = 26;

int count_valid_strings(int N, vector<pair<char, char>>& pairs) {
    vector<vector<int>> dp(N + 1, vector<int>(ALPHABET_SIZE, 0));
    unordered_set<int> restrictions[ALPHABET_SIZE];

    // Convert character pairs to indices and fill the restrictions
    for (auto& p : pairs) {
        int u = p.first - 'a';
        int v = p.second - 'a';
        restrictions[u].insert(v);
        restrictions[v].insert(u);
    }

    // Base case: Strings of length 1
    for (int c = 0; c < ALPHABET_SIZE; ++c) {
        dp[1][c] = 1;
    }

    // Fill dp table for lengths 2 to N
    for (int i = 2; i <= N; ++i) {
        for (int c = 0; c < ALPHABET_SIZE; ++c) {
            dp[i][c] = 0;
            for (int c_prime = 0; c_prime < ALPHABET_SIZE; ++c_prime) {
                if (restrictions[c_prime].find(c) == restrictions[c_prime].end()) {
                    dp[i][c] = (dp[i][c] + dp[i - 1][c_prime]) % MOD;
                }
            }
        }
    }

    // Sum up all valid strings of length N
    int result = 0;
    for (int c = 0; c < ALPHABET_SIZE; ++c) {
        result = (result + dp[N][c]) % MOD;
    }

    return result;
}

int main() {
    int N = 3;  // Length of the strings
    vector<pair<char, char>> pairs = { {'a', 'b'}, {'b', 'c'} };  // Example pairs
    cout << count_valid_strings(N, pairs) << endl;  // Output the result
    return 0;
}
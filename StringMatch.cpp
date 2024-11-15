#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pattern, vector<int>& lps) {
    int len = 0;
    lps[0] = 0;  // LPS[0] is always 0
    int i = 1;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Use the previous LPS value
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string text, string pattern) {
    int M = pattern.length();
    int N = text.length();

    vector<int> lps(M);
    computeLPSArray(pattern, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMPSearch(text, pattern);

    return 0;
}

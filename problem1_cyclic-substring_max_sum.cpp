#include <bits/stdc++.h>
using namespace std;

int maxCyclicSubstringSum(string s) {
    int n = s.size();
    string t = s + s; // handle cyclic case
    
    vector<int> freq(26, 0);
    int left = 0, sum = 0, maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int idx = t[right] - 'a';
        
        // Add current character
        freq[idx]++;
        sum += (idx + 1);

        // If duplicate OR window size > n → shrink
        while (freq[idx] > 1 || (right - left + 1) > n) {
            int leftIdx = t[left] - 'a';
            freq[leftIdx]--;
            sum -= (leftIdx + 1);
            left++;
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    string s;
    cin >> s;

    cout << maxCyclicSubstringSum(s) << endl;

    return 0;
}

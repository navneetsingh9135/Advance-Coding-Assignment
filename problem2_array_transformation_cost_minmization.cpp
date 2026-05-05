#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    long long K;
    cin >> K;

    // Step 1: Check feasibility
    long long rem = A[0] % K;
    for (int i = 1; i < N; i++) {
        if (A[i] % K != rem) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Step 2: Normalize
    vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = (A[i] - rem) / K;
    }

    // Step 3: Sort to find median
    sort(B.begin(), B.end());
    long long median = B[N / 2];

    // Step 4: Calculate operations
    long long operations = 0;
    for (int i = 0; i < N; i++) {
        operations += abs(B[i] - median);
    }

    cout << operations << endl;

    return 0;
}

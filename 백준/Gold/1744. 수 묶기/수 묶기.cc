#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> negatives, positives;
    int zero_cnt = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num > 1) {
            positives.push_back(num);
        } else if (num == 1) {
            ans += 1; // 1은 무조건 더하는 것이 유리
        } else if (num == 0) {
            zero_cnt++;
        } else {
            negatives.push_back(num);
        }
    }

    sort(negatives.begin(), negatives.end());
    sort(positives.rbegin(), positives.rend());

    // 음수 처리
    for (size_t i = 0; i + 1 < negatives.size(); i += 2) {
        ans += negatives[i] * negatives[i + 1];
    }
    // 음수의 개수가 홀수면 남은 하나 처리
    if (negatives.size() % 2 == 1) {
        if (zero_cnt == 0) {
            ans += negatives.back(); // 0이 없으면 더하기
        }
    }

    // 양수 처리
    for (size_t i = 0; i + 1 < positives.size(); i += 2) {
        ans += positives[i] * positives[i + 1];
    }
    // 양수의 개수가 홀수면 남은 하나 처리
    if (positives.size() % 2 == 1) {
        ans += positives.back();
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int equalStacks(vector<int>& h1, vector<int>& h2, vector<int>& h3) {
    int s1 = accumulate(h1.begin(), h1.end(), 0);
    int s2 = accumulate(h2.begin(), h2.end(), 0);
    int s3 = accumulate(h3.begin(), h3.end(), 0);
    
    while (!h1.empty() && !h2.empty() && !h3.empty()) {
        int m = min({s1, s2, s3});
        
        while (s1 > m) {
            s1 -= h1.front();
            h1.erase(h1.begin());
        }
        while (s2 > m) {
            s2 -= h2.front();
            h2.erase(h2.begin());
        }
        while (s3 > m) {
            s3 -= h3.front();
            h3.erase(h3.begin());
        }
            
        if (s1 == s2 && s2 == s3) {
            return s1;
        }
    }
    
    return 0;
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> h1(n1), h2(n2), h3(n3);

    for (int i = 0; i < n1; ++i) {
        cin >> h1[i];
    }
    for (int i = 0; i < n2; ++i) {
        cin >> h2[i];
    }
    for (int i = 0; i < n3; ++i) {
        cin >> h3[i];
    }

    int result = equalStacks(h1, h2, h3);

    cout << result << endl;

    return 0;
}

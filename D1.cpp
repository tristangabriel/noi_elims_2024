#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;
#define REP(i, n) for (int i=0;i<n;i++)

lli temp[500000];
lli arr[500000];
lli b[500001];
lli c[500001];
const lli zero = 0;
int main() {
    int t, n, k, num; cin >> t;
    while (t--) {
        lli ppcost=0, num;
        cin >> n >> k;
        REP(i, n) {
            cin >> temp[i];
        }
        REP(i, n) {
            cin >> num;
            arr[i] = temp[num-1];
        }
        REP(i, n) {
            c[i+1] = c[i] + b[i];
            if (i>=k) {
                c[i+1] -= b[i-k+1];
            }
            b[i+1] = max(arr[i] - c[i+1], zero);
            ppcost += b[i+1];
        }
        cout << ppcost << endl;
    }
    return 0;
}
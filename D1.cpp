#include <iostream>
#include <algorithm>

using namespace std;

long long int temp[500000];
long long int arr[500000];
long long int b[500001];
long long int c[500001];
const long long int zero = 0;
int main() {
    int t, n, k, num; cin >> t;
    while (t--) {
        long long int ppcost=0, num;
        cin >> n >> k;
        for (int i=0;i<n;i++) {
            cin >> temp[i];
        }
        for (int i=0;i<n;i++) {
            cin >> num;
            arr[i] = temp[num-1];
        }
        for (int i=0;i<n;i++) {
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
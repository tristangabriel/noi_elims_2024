// SUBTASK 2, just code as it is
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int moves=1;
    int sl, tl, s, t; cin >> sl >> tl;
    vector<int> S(sl);
    vector<int> T(tl);
    for (int i=sl-1;i>=0;i--) {
        cin >> S[i];
    }
    for (int i=tl-1;i>=0;i--) {
        cin >> T[i];
    }

    while (!T.empty()) {
        moves++;
        if (S.empty()) {
            S.push_back(T[T.size()-1]);
            T.pop_back();
            continue;
        }
        s = S[S.size()-1];S.pop_back();
        t = T[T.size()-1];T.pop_back();
        if (s>t) {
            T.push_back(s);
            T.push_back(t);
        }
        else {
            S.push_back(s);
            S.push_back(t);
        }
    }
    cout << moves << endl;
    return 0;
}
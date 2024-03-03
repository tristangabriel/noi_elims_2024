#include <iostream>
#include <algorithm>

using namespace std;

int n[5001];
long long int dp[5001][5001];
int tracker[5001][5001];
int connect[5001][5001];
int effort[5001][101];
int points[5001][101];
int order[50001];
int main() {
    int N, E, po;
    cin >> E >> N;
    for (int i=0;i<N;i++) {
        cin >> n[i];
    }
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<n[i];j++) {
            cin >> effort[i][j];
        }
    }
    for (int i=0;i<N;i++) {
        cin >> points[i][0];
        for (int j=1;j<n[i];j++) {
            cin >> po;
            points[i][j] = po + points[i][j-1];
        }
    }
    int st=0;
    for (int e=1; e<=E;e++) {
        if (e>=effort[0][st]) {
            dp[0][e] = points[0][st];
            tracker[0][e] = st+1;
        }
        else
            tracker[0][e]=0;
        if (e+1 == effort[0][st+1])
            st++;
    }

    for (int ni=1;ni<N;ni++) {
        for (int e=1; e<=E;e++) {
            dp[ni][e] = dp[ni-1][e];
            tracker[ni][e] = 0;
            connect[ni][e] = e;
            for (int st=0;st<n[ni];st++) {
                if (e<effort[ni][st]) {
                    break;
                }
                else {
                    int num = dp[ni-1][e-effort[ni][st]] + points[ni][st];
                    if (dp[ni][e] < num) {
                        dp[ni][e] = num;
                        tracker[ni][e]=st+1;
                        connect[ni][e] = e-effort[ni][st];
                    }
                }
            }
        }

    }
    int laste = E;
    for (int i=N-1;i>=0;i--) {
        order[i] = tracker[i][laste];
        laste = connect[i][laste];
    }
    cout << order[0];
    for (int i=1;i<N;i++) {
        cout << ' ' << order[i];
    }
    cout << endl;
}
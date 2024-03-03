//ONLY SOLVES FIRST SUBTASK
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 998244353

int allure[7200];
int n;
long long sums=0;
// dancer i, # of included members, list of members, running product
void subs(int ith, int mem, vector<int> members, long long int prod=1) {  
    if (ith > n) {  // terminator
        if (mem==0)  // if empty
            return;
        sums = (prod+sums)%MOD;  // if non-empty, add the product to the sum
    }
    else {
        subs(ith+1, mem, members, prod);  // dont include the ith member
        for (int f : members) {
            if (__gcd(ith, f)>1)  // check if not comprime, (coprime means gcd(a, b)==1)
                return;
        }
        members.push_back(ith);
        subs(ith+1, mem+1, members, prod*allure[ith-1]%MOD);  // include ith member
    }
}
int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> allure[i];
    }
    vector<int> filler;
    subs(1, 0, filler);
    cout << sums << endl;
    return 0;
}
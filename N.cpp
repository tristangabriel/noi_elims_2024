#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

#define MOD 998244353
vector<string> li = {""};

long long int exponentiation(int base, int exp, int mod=MOD) {
    if (exp == 0)
        return 1;
 
    if (exp == 1)
        return base % mod;
 
    long long int t = exponentiation(base, exp / 2, mod);
    t = (t * t) % mod;
 
    // if exponent is even value
    if (exp % 2 == 0)
        return t;
 
    // if exponent is odd value
    else
        return ((base % mod) * t) % mod;
}


long long int remainder(string s, long long int i, long long int j, int mod) {
    int n=j-i+1, ten=10%mod, id=0;
    long long int tens=1, num=0;
    //cout << s << ": " << i << "-" << j << " |" << mod << "| = ";
    for (j;j>=i;j--) {
        /*cout << "check " << tens << "=" << exponentiation(10, id, mod) << endl;*/
        num +=((s[j-1]-48)%mod)*tens;
        //cout << endl << s[i-1]<<" digit " << (s[i-1]-48);
        if (num>=mod) {
            num %= mod;
        }
        tens = (tens*ten)%mod;
        //id++;
    }
    //cout << endl;
    return num;
}


void process(long long int t) {
    int b = li[t-2].size(), d = remainder(li[t-1], 1, li[t-1].size(), li[t-3].size()+1);
    stringstream latestTK;
    string str; latestTK << li[t-1];
    for (int add=0;add<b;add++) {
        //cout << "ss add" << li[t-1][d+add] << endl;
        latestTK << li[t-1][d+add];
    }

    latestTK >> str;
    li.push_back(str);
    //cout << "at t = " << t << ": " << str << endl;
}


int main() {
    int x, q;
    long long int i, j, k;
    string tk;
    cin >> x >> k >> q >> tk;
    li.push_back(tk);
    li.push_back(tk);

    for (long long int t=3;t<=k;t++) {
        process(t);
    }
    for (int _=0; _<q;_++) {
        cin>> i >> j;
        cout << remainder(li[k], i, j, MOD) << endl; 
    }
    return 0;
}
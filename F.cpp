#include <iostream>
#include <algorithm>
using namespace std;

#define MAXNUM 1000000000000000001

long long int sungka[2][8];
//the sungka array is not in clockwise,
//it is simpler to code if for sungka[i][j],
//the ulo is at j[0]
//and the next neighbor going clockwise is always j++;
int minI(int row) {  //finds the minimum shells that isnt empty
    int index=1;
    long long int min=1e18+1;

    for (int i=1;i<8;i++) {
        if (sungka[row][i]<min && sungka[row][i]) {  // less then the current minimum AND not zero
            index = i;
            min = sungka[row][i];
        }
    }
    return index;
}


void solve() {
    int curMin, curRow; // current minimum, current row
    long long int sago;
    for (int t=0;true;t=!t) {  //flips between 0 and 1
        curRow = t;  // current row
        curMin=minI(curRow);  // minimum # of shells, not empty
        if (sungka[t][curMin]==0) {  // if the minimum is 0 (means all are empty)
            if (sungka[!t][minI(!t)]==0)  // checks if the other row is all empty
                return;  // stop, end function
            continue;  // next iteration (next turn)
        }
        sago = sungka[curRow][curMin];
        sungka[curRow][curMin]=0;
        while (sago) {
            if (sago>=15) {  // adds each pocket by sago/15
                long long int num = sago/15;
                for (int r=0;r<2;r++) {
                    for (int c=1;c<8;c++) {
                        sungka[r][c]+=num;
                    }
                }
                sungka[t][0]+=num;
                sago %= 15;
                // this optimizes bc, considering a large number of sago, 
                //you need to do ceil(sago/15) passes of the whole board
                // this function does it all in one pass floor
            }
            if (sago>=1) {
                sago--;
                if ((curMin==0 && curRow==t) || (curMin==1 && curRow!=t)) {  // go to the next row
                    curRow = !curRow;
                    curMin = 7;
                }
                else {
                    curMin--;  // otherwise just go to the neighbor
                }
                sungka[curRow][curMin]++;
            }
            if (sago==0) {
                if (curMin==0 && t==curRow) {  //if you end on your ulo
                    curMin = minI(t);
                    sago = sungka[t][curMin];
                    sungka[t][curMin]=0;
                }
                else if (sungka[curRow][curMin]>1) {  // if you land on a non-empty bahay
                    sago = sungka[curRow][curMin];
                    sungka[curRow][curMin] = 0;
                }
                else if (curRow==t && sungka[!t][8-curMin]>0) {  //start over your turn
                    sungka[t][0] += 1+sungka[!t][8-curMin];
                    sungka[t][curMin]=0;
                    sungka[!t][8-curMin]=0;
                }
            }
        }
    }
}


int main() {
    for (int col=7;col>0;col--) {
        cin >> sungka[0][col];
    }
    for (int col=1;col<8;col++) {
        cin >> sungka[1][col];
    }

    solve();
    cout << sungka[0][0] << ' ' << sungka[1][0] << endl;
}
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double BlockReward;
double CirculatingSupply ;
int    i;
int    Halvings = 0;
int    ThisMonth;

int main () {
    cout.precision(6);
    cout.setf(ios::fixed);

    Halvings = 0;
    CirculatingSupply = 0.0;
    BlockReward = 100.0;
    cout <<  "Month,Block,Reward,CirculatingSupply\n";
    for (i = 0; i < 1577881 ; i++) {
        if (( i % 210000) == 0) {
		BlockReward = BlockReward / 2.0;
		Halvings++;
		if ( Halvings >= 64 ) {
		    BlockReward = 0;
		}
        }  
	CirculatingSupply += BlockReward;
	if ((i % 4383) == 0) {
            ThisMonth = i / 4383;
            cout << ThisMonth << "," << i << "," << BlockReward << "," << CirculatingSupply  << " \n";
        }
    }
}


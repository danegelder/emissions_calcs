#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double InitialCirculatingSupply = 40000000.0;
double EmissionSpeed = 21;
double TotalSupply = (double) 120000000.0;
double EmissionFactor; 
double BlockReward;
double CirculatingSupply = 0.0;
int i;


int main () {
    cout.precision(6);
    cout.setf(ios::fixed);

    EmissionFactor = pow( (double) 2.0 , (double) - EmissionSpeed );
    CirculatingSupply = InitialCirculatingSupply;
    cout << "block" << "," << "Reward" << "," << "CirculatingSupply"  << " \n";
    for (i = 1; i < 13149001; i++) {
        BlockReward =  ( TotalSupply - CirculatingSupply ) * EmissionFactor;
	CirculatingSupply += BlockReward;
	if ((i % 262980) == 0) {
            cout << i << "," << BlockReward << "," << CirculatingSupply  << " \n";
        }
    }
}


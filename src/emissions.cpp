#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double InitialCirculatingSupply = 40000000.0;
double EmissionSpeed = 22;
double TotalSupply = (double) 120000000.0;
double EmissionFactor; 
double BlockReward;
double CirculatingSupply = 0.0;
double TailEmission = 3.5;
int ThisMonth;
int i;


int main () {
    cout.precision(6);
    cout.setf(ios::fixed);

    EmissionFactor = pow( (double) 2.0 , (double) - EmissionSpeed );
    CirculatingSupply = InitialCirculatingSupply;
    cout <<  "Month,Block,Reward,CirculatingSupply\n";
    for (i = 1; i < 13149001; i++) {
        BlockReward =  ( TotalSupply - CirculatingSupply ) * EmissionFactor;
        if ( BlockReward < TailEmission) {
	    BlockReward = TailEmission;
	}
	CirculatingSupply += BlockReward;
	if ((i % 21915) == 0) {
            ThisMonth = i / 21915;
            cout << ThisMonth << "," << i << "," << BlockReward << "," << CirculatingSupply  << " \n";
        }
    }
}


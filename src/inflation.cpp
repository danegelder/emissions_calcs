#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double InitialCirculatingSupply = 40000000.0;
double EmissionSpeed = 21;
double InflationFactor = 0.000000027;
double TotalSupply = (double) 120000000.0;
double EmissionFactor; 
double BlockReward;
double CirculatingSupply = 0.0;
double TailEmission = 0.5;
double TotalBlocksToSimulate = 26298001;
int ThisMonth;
int i;


int main () {
    cout.precision(6);
    cout.setf(ios::fixed);

    EmissionFactor = pow( (double) 2.0 , (double) - EmissionSpeed );
    CirculatingSupply = InitialCirculatingSupply;
    cout <<  "Month,Block,Reward,CirculatingSupply\n";
    for (i = 0; i < TotalBlocksToSimulate ; i++) {
	if ( CirculatingSupply > TotalSupply ) {
            BlockReward =  CirculatingSupply  * InflationFactor; 
	} else {
            BlockReward =  (( TotalSupply - CirculatingSupply ) * EmissionFactor) + (CirculatingSupply  * InflationFactor);
	}
        //if ( BlockReward < TailEmission) {
	//    BlockReward = TailEmission;
	//}
	CirculatingSupply += BlockReward;
	if ((i % 21915) == 0) {
            ThisMonth = i / 21915;
            cout << ThisMonth << "," << i << "," << BlockReward << "," << CirculatingSupply  << " \n";
        }
    }
}


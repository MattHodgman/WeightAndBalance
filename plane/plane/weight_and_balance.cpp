#include <iostream>
#include <bitset>
#include <cstdlib>
using namespace std;

int main() {

	// Variables
	int emptyWeight = 1666;
	double emptyMoment = 65.1;
	int fuelGallons;
	double fuelWeight;
	double fuelMoment;
	int frontPass;
	double frontPassMoment;
	int rearPass;
	double rearPassMoment;
	int bagArea1;
	double bagArea1Moment;
	int bagArea2;
	double bagArea2Moment;
	double totalWeight;
	double totalMoment;

	// get weights from user
	cout << "Pilot and front passenger weight:" << endl;
	cin >> frontPass;
	cout << "Gallons of fuel on board:" << endl;
	cin >> fuelGallons;
	cout << "Rear passenger weight:" << endl;
	cin >> rearPass;
	cout << "Baggage area 1 weight:" << endl;
	cin >> bagArea1;
	cout << "Baggage area 2 weight:" << endl;
	cin >> bagArea2;

	// convert fuel gallons to pounds
	fuelWeight = fuelGallons * 6;

	// Calculate Moments
	// frontPass slope = 26.66666
	// fuel slope = 20.649
	// rearPass slope = 13.793
	// ba1 slope = 10.619
	// ba2 slope = 7.936
	frontPassMoment = frontPass / 26.666;
	fuelMoment = fuelWeight / 20.649;
	rearPassMoment = rearPass / 13.793;
	bagArea1Moment = bagArea1 / 10.619;
	bagArea2Moment = bagArea2 / 7.936;


	// Sum totals
	totalWeight = emptyWeight + fuelWeight + frontPass + rearPass + bagArea1 + bagArea2;
	totalMoment = emptyMoment + fuelMoment + frontPassMoment + rearPassMoment + bagArea1Moment + bagArea2Moment;
	cout << "Total weight: " << totalWeight << endl;
	cout << "Total moment: " << totalMoment << endl;

	cin.get();

	// checks
	// point must be above y=55.681x
	// and below y=53.261x
	if (totalWeight > 2450) {
		cout << "Too heavy." << endl;
	}
	else if ((bagArea1 + bagArea2) > 120) {
		cout << "Too much weight in baggage areas." << endl;
	}
	else if ((totalWeight < ((totalMoment * 20.8791) + 403)) && (totalWeight > (totalMoment * 21.34831))) {
		cout << "You are in the bounds. Safe flying." << endl;
	}
	else {
		cout << "ERROR!!! Or it's just really close, check with POH."<< endl;
	}
	cin.get();
	return 0;
}
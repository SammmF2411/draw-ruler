//This program will draw a ruler based on input from the user
//Samantha L.M. Floyd

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void drawTickMarks(int, int);
void drawLabels(int, int);
void drawRuler(int, int, int, int);

int main() {
	int ruler_length = 0;
	int denominator = 0;
	
	cout << "Enter a ruler length: ";
	cin >> ruler_length;
	cout << endl;
	
	cout << "Enter the denominator of the distance between the closest tick mark: ";
	cin >> denominator;
	cout << endl;
	
	double n = log2(denominator);
	
	if(n != int(n)){ //error checking the denominator
		cout << "Error. The denominator must be a perfect power of two. ";
		cin >> denominator;
	}
	
	drawRuler(ruler_length, denominator, ruler_length, denominator);
	return 0;
}
void drawTickMarks(int num_TickMarks, int spacing){
	for (int i = 0; i < num_TickMarks + 1; i++){
		cout <<  "|";
		cout << setw(spacing);
	}
	cout<< endl;
	cout << setw(0); //set new spacing after the loop
	return;
}
void drawLabels(int num_labels, int spacing){
	for(int i = 0; i < num_labels + 1; i++){
		
		if (i == 10){ //only need to shift the spacing by 1 once when we hit the double digits
			cout << setw(spacing + 1);
			cout << i;
			cout<< setw(spacing);
		}		
		else{
		cout << i;
		cout << setw(spacing);
		}		
	}
	cout << endl;
	cout << setw(0);
	return;
}
void drawRuler(int currTicks, int currSpacing, int orgTicks, int orgSpacing){
	int actualTicks = currTicks+1; //must account for 0
	
	if (currSpacing == 0){ // base case
		drawLabels(orgTicks, orgSpacing);
		return;
	}
	int index;
	index = log2(currSpacing);
	
	if (index %2 ==0){ //print only if even
	drawTickMarks(currTicks, currSpacing);
	}
	drawRuler((actualTicks-1)*2, currSpacing/2, orgTicks, orgSpacing);
	
	if (index %2 != 0 || currSpacing == orgSpacing/orgSpacing){ //print only if odd and print the 0 index line
	drawTickMarks(currTicks, currSpacing);
	}	
}

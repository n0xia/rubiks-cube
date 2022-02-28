#include <bits/stdc++.h>
#include "cube.h"
using namespace std;

int main(){
	Cube cube; // Initializing a cube instance
	int choice = 2;
	double sleepTime;
	cout << "1. Input turns" <<endl;
	cout << "2. Count cycle periodicity" <<endl;
	cout << "Input: "; cin >> choice;	
	if(choice == 1){
		cube.DisplayNormalTurns();
	}
	if(choice == 2){
		cube.DisplayPerodicity();
	}
}
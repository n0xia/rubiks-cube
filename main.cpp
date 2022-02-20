#include <bits/stdc++.h>
#include "cube.h"
using namespace std;

int main(){
	Cube cube; // Initializing a cube instance
	cube.Input(); cout <<endl;
	double sleepTime;
	cout << "Input ammount of seconds to pause between each move: "; cin >> sleepTime;
	cube.Display(sleepTime);
}
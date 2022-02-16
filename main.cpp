#include <bits/stdc++.h>
#include "cube.h"
using namespace std;



int main(){
	Cube cube; // Initializing a cube instance
	//----------Input----------
	/*int n; cout << "Number of moves: "; cin >> n;
	string moves[n];
	cout << "Moves: ";
	for(int i = 0; i < n; i++) cin >> moves[i];
	//-------------------------
	for(int i = 0; i < n; i++){

	}*/
	cube.Display();
	system("sleep 1");
	cube.RC();
	cube.Display();
	system("sleep 0.5");
	cube.RC();
	cube.Display();
	system("sleep 0.3");
	cube.RC();
	cube.Display();
	system("sleep 0.3");
	cube.RC();
	cube.Display();

}
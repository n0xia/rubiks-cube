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
	/* for(int i = 1; i <= 6; i++){
		cube.RC();
		cube.UC();
		cube.RCC();
		cube.UCC();
		cube.Display();
		system("sleep 0.5");
	} */

	cube.Display();
    system("sleep 1");


	cube.RC();
	cube.Display();
	system("sleep 0.5");

	cube.LC();
	cube.Display();
	system("sleep 0.5");

	cube.UC();
	cube.Display();
	system("sleep 0.5");

	cube.DC();
	cube.Display();
	system("sleep 0.5");

	cube.FC();
	cube.Display();
	system("sleep 0.5");

	cube.BC();
	cube.Display();
	system("sleep 10");
	//=======
	cube.BCC();
	cube.Display();
	system("sleep 0.5");

	cube.FCC();
	cube.Display();
	system("sleep 0.5");
	
	cube.DCC();
	cube.Display();
	system("sleep 0.5");

	cube.UCC();
	cube.Display();
	system("sleep 0.5");

	cube.LCC();
	cube.Display();
	system("sleep 0.5");

	cube.RCC();
	cube.Display();
	system("sleep 0.5");
}
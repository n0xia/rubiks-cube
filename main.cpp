#include <bits/stdc++.h>
#include "cube.h"
using namespace std;



int main(){
	Cube cube; // Initializing a cube instance

	cube.Display();
    system("sleep 1");


	for(int i = 1; i <= 6; i++){
		cube.RC();
		cube.Display();
    system("sleep 0.3");
		cube.UC();
		cube.Display();
    system("sleep 0.3");
		cube.RCC();
		cube.Display();
    system("sleep 0.3");
		cube.UCC();
		cube.Display();
    system("sleep 0.3");
	}

}
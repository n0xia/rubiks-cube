#include <bits/stdc++.h>
using namespace std;
//----------colors----------
#define WHITE "\e[1m"
#define RED "\e[31m"
#define BLUE "\e[34m"
#define YELLOW "\e[1;30m"
#define ORANGE "\e[33m"
#define GREEN "\e[32m"
#define Null "\e[0m"

class Cube{
public:
	//---------Sides---------
	int D[3][3] ={{1, 1, 1},
				  {1, 1, 1},
				  {1, 1, 1}};
	int F[3][3] ={{2, 2, 2},
				  {2, 2, 2},
				  {2, 2, 2}};
	int L[3][3] ={{3, 3, 3},
				  {3, 3, 3},
				  {3, 3, 3}};
	int U[3][3] ={{4, 4, 4},
				  {4, 4, 4},
				  {4, 4, 4}};
	int B[3][3] ={{5, 5, 5},
				  {5, 5, 5},
				  {5, 5, 5}};
	int R[3][3] ={{6, 6, 6},
				  {6, 6, 6},
				  {6, 6, 6}};
	//-----Move Functions-----
	void RC(){
		int temp1 = F[0][2];
		int temp2 = F[1][2];
		int temp3 = F[2][2];
		F[0][2] = D[0][2];
		F[1][2] = D[1][2];
		F[2][2] = D[2][2];
		D[0][2] = B[0][2];
		D[1][2] = B[1][2];
		D[2][2] = B[2][2];
		B[0][2] = U[0][2];
		B[1][2] = U[1][2];
		B[2][2] = U[2][2];
		U[0][2] = temp1;
		U[1][2] = temp2;
		U[2][2] = temp3;
		
	}

	//------------------------
	void colorcout(int color){
		if(color == 1) cout << WHITE << "■" << Null;
		else if(color == 2) cout << RED << "■" << Null;
		else if(color == 3) cout << BLUE << "■" << Null;
		else if(color == 4) cout << YELLOW << "■" << Null;
		else if(color == 5) cout << ORANGE << "■" << Null;
		else if(color == 6) cout << GREEN << "■" << Null;
	}
	
	void Observe_Debug(){
		for(int side = 1; side <= 6; side++){
			for(int i = 0; i < 3; i++){
				for(int i2 = 0; i2 < 3; i2++){
						 if (side == 1) {colorcout(D[i][i2]); cout << " ";}
					else if (side == 2) {colorcout(F[i][i2]); cout << " ";}
					else if (side == 3) {colorcout(L[i][i2]); cout << " ";}
					else if (side == 4) {colorcout(U[i][i2]); cout << " ";}
					else if (side == 5) {colorcout(B[i][i2]); cout << " ";}
					else if (side == 6) {colorcout(R[i][i2]); cout << " ";}
				} cout <<endl;
			}cout <<endl;
		}
	}

	void Display(){
		system("clear");
		//Upside - Black
		for(int i = 0; i < 3; i++){
		cout << "      ";
			for(int i2 = 0; i2 < 3; i2++){
				colorcout(U[i][i2]); cout << " ";
			} cout <<endl;
		}

		//Backside - Orange
		for(int i = 0; i < 3; i++){
		cout << "      ";
			for(int i2 = 0; i2 < 3; i2++){
				colorcout(B[i][i2]); cout << " ";
			} cout <<endl;
		}

		//Rightside, Downside, Leftside - Green, White, Blue
		for(int i = 0; i < 3; i++){
			int threecntr = 1;
			int switcher = 1;
			for(int i2 = 0; i2 < 9; i2++){
				if(switcher == 1) {colorcout(R[i][i2]); cout << " ";}
				else if(switcher == 2) {colorcout(D[i][i2-3]); cout << " ";}
				else if(switcher == 3) {colorcout(L[i][i2-6]); cout << " ";}
				if(threecntr == 3){
					threecntr = 1;
					switcher++;
				} else threecntr++;
			} cout <<endl;
		}

		//Frontside - Red
		for(int i = 0; i < 3; i++){
		cout << "      ";
			for(int i2 = 0; i2 < 3; i2++){
				colorcout(F[i][i2]); cout << " ";
			} cout <<endl;
		}
	}
  /*1 = White
	2 = Red
	3 = Blue
	4 = Yellow
	5 = Orange
	6 = Green
	■
	*/
}; 
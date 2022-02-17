#include <bits/stdc++.h>
using namespace std;
//----------colors----------
#define WHITE "\e[1m"
#define RED "\e[31m"
#define BLUE "\e[34m"
#define YELLOW "\e[1;30m"
#define ORANGE "\e[33m"
#define GREEN "\e[32m"
//-----BG-----
#define BGWHITE "\e[30m\e[1;47m"
#define BGRED "\e[41m"
#define BGBLUE "\e[44m"
#define BGYELLOW "\e[1;40m"
#define BGORANGE "\e[1;43m"
#define BGGREEN "\e[42m"
//----Null----
#define Null "\e[0m"
//----------------------------

class Cube{
public:
	//---------Sides---------
	int R[3][3] ={{6, 6, 6},
				  {6, 6, 6},
				  {6, 6, 6}};
	//-----------------------
	int L[3][3] ={{3, 3, 3},
				  {3, 3, 3},
				  {3, 3, 3}};
	//-----------------------
	int U[3][3] ={{4, 4, 4},
				  {4, 4, 4},
				  {4, 4, 4}};
	//-----------------------
	int D[3][3] ={{1, 1, 1},
				  {1, 1, 1},
				  {1, 1, 1}};
	//-----------------------
	int F[3][3] ={{2, 2, 2},
				  {2, 2, 2},
				  {2, 2, 2}};
	//-----------------------
	int B[3][3] ={{5, 5, 5},
				  {5, 5, 5},
				  {5, 5, 5}};
	/*
	1 = White
	2 = Red
	3 = Blue
	4 = Yellow
	5 = Orange
	6 = Green
	■
	*/

	//---------Coloring----------
	void colorcout(int color){
		if(color == 1) cout << WHITE << "■" << Null;
		else if(color == 2) cout << RED << "■" << Null;
		else if(color == 3) cout << BLUE << "■" << Null;
		else if(color == 4) cout << YELLOW << "■" << Null;
		else if(color == 5) cout << ORANGE << "■" << Null;
		else if(color == 6) cout << GREEN << "■" << Null;
	}
	//---------------Display Cube-------------------
	void Display(){
		system("clear");
		//Backside - Orange (Should be orange but is rendered yellow)
		for(int i = 0; i < 3; i++){
		cout << "      ";
			for(int i2 = 0; i2 < 3; i2++){
				colorcout(B[i][i2]); cout << " ";
			} cout <<endl;
		}

		//Upside - Black (Should be yellow)
		for(int i = 0; i < 3; i++){
		cout << "      ";
			for(int i2 = 0; i2 < 3; i2++){
				colorcout(U[i][i2]); cout << " ";
			} cout <<endl;
		}

		//Leftside, Frontside, Rightside - Blue, Red, Green
		for(int i = 0; i < 3; i++){
			int threecntr = 1;
			int switcher = 1;
			for(int i2 = 0; i2 < 9; i2++){
				if(switcher == 1) {colorcout(L[i][i2]); cout << " ";}
				else if(switcher == 2) {colorcout(F[i][i2-3]); cout << " ";}
				else if(switcher == 3) {colorcout(R[i][i2-6]); cout << " ";}
				if(threecntr == 3){
					threecntr = 1;
					switcher++;
				} else threecntr++;
			} cout <<endl;
		}

		//Downside - White
		for(int i = 0; i < 3; i++){
		cout << "      ";
			for(int i2 = 0; i2 < 3; i2++){
				colorcout(D[i][i2]); cout << " ";
			} cout <<endl;
		}
	}//----------------------------------------------

	//==========Move Functions==========
	int temp[3]; // temp vars
	int ftemp;
	
	//====6 Base Clockwise Rotations====
	// Right Clockwise
	void RC(){
		for(int i = 0; i < 3; i++) temp[i] = F[i][2];
		for(int i = 0; i < 3; i++) F[i][2] = D[i][2];
		for(int i = 0; i < 3; i++) D[i][2] = B[i][2];
		for(int i = 0; i < 3; i++) B[i][2] = U[i][2];
		for(int i = 0; i < 3; i++) U[i][2] = temp[i];
		//----------------
		ftemp = R[0][0];
		R[0][0] = R[2][0];
		R[2][0] = R[2][2];
		R[2][2] = R[0][2];
		R[0][2] = ftemp;
		//----------------
		ftemp = R[0][1];
		R[0][1] = R[1][0];
		R[1][0] = R[2][1];
		R[2][1] = R[1][2];
		R[1][2] = ftemp;
	}

	void LC(){
		for(int i = 0; i < 3; i++) temp[i] = F[i][0];
		for(int i = 0; i < 3; i++) F[i][0] = U[i][0];
		for(int i = 0; i < 3; i++) U[i][0] = B[i][0];
		for(int i = 0; i < 3; i++) B[i][0] = D[i][0];
		for(int i = 0; i < 3; i++) D[i][0] = temp[i];
		ftemp = L[0][0];
		L[0][0] = L[2][0];
		L[2][0] = L[2][2];
		L[2][2] = L[0][2];
		L[0][2] = ftemp;
		//----------------
		ftemp = L[0][1];
		L[0][1] = L[1][0];
		L[1][0] = L[2][1];
		L[2][1] = L[1][2];
		L[1][2] = ftemp;
	}

	void UC(){
		for(int i = 0; i < 3; i++) temp[i] = F[0][i];
		for(int i = 0; i < 3; i++) F[0][i] = R[0][i];
		for(int i = 0; i < 3; i++) R[0][i] = B[2][2-i];
		for(int i = 0; i < 3; i++) B[2][2-i] = L[0][i];
		for(int i = 0; i < 3; i++) L[0][i] = temp[i];
		ftemp = U[0][0];
		U[0][0] = U[2][0];
		U[2][0] = U[2][2];
		U[2][2] = U[0][2];
		U[0][2] = ftemp;
		//----------------
		ftemp = U[0][1];
		U[0][1] = U[1][0];
		U[1][0] = U[2][1];
		U[2][1] = U[1][2];
		U[1][2] = ftemp;
	}

	void DC(){
		for(int i = 0; i < 3; i++) temp[i] = F[2][i];
		for(int i = 0; i < 3; i++) F[2][i] = L[2][i];
		for(int i = 0; i < 3; i++) L[2][i] = B[0][2-i];
		for(int i = 0; i < 3; i++) B[0][2-i] = R[2][i];
		for(int i = 0; i < 3; i++) R[2][i] = temp[i];
		ftemp = D[0][0];
		D[0][0] = D[2][0];
		D[2][0] = D[2][2];
		D[2][2] = D[0][2];
		D[0][2] = ftemp;
		//----------------
		ftemp = D[0][1];
		D[0][1] = D[1][0];
		D[1][0] = D[2][1];
		D[2][1] = D[1][2];
		D[1][2] = ftemp;
	}

	void FC(){
		for(int i = 0; i < 3; i++) temp[i] = U[2][i];
		for(int i = 0; i < 3; i++) U[2][i] = L[2-i][2];
		for(int i = 0; i < 3; i++) L[i][2] = D[0][i];
		for(int i = 0; i < 3; i++) D[0][2-i] = R[i][0];
		for(int i = 0; i < 3; i++) R[i][0] = temp[i];
		ftemp = F[0][0];
		F[0][0] = F[2][0];
		F[2][0] = F[2][2];
		F[2][2] = F[0][2];
		F[0][2] = ftemp;
		//----------------
		ftemp = F[0][1];
		F[0][1] = F[1][0];
		F[1][0] = F[2][1];
		F[2][1] = F[1][2];
		F[1][2] = ftemp;
	}

	void BC(){
		for(int i = 0; i < 3; i++) temp[i] = U[0][i];
		for(int i = 0; i < 3; i++) U[0][i] = R[i][2];
		for(int i = 0; i < 3; i++) R[i][2] = D[2][2-i];
		for(int i = 0; i < 3; i++) D[2][i] = L[i][0];
		for(int i = 0; i < 3; i++) L[2-i][0] = temp[i];
		ftemp = B[0][0];
		B[0][0] = B[2][0];
		B[2][0] = B[2][2];
		B[2][2] = B[0][2];
		B[0][2] = ftemp;
		//----------------
		ftemp = B[0][1];
		B[0][1] = B[1][0];
		B[1][0] = B[2][1];
		B[2][1] = B[1][2];
		B[1][2] = ftemp;
	}
	//-------------------------------------

	//====6 Base Counter-Clockwise Rotations====
	void RCC(){RC();RC();RC();}
	void LCC(){LC();LC();LC();}
	void UCC(){UC();UC();UC();}
	void DCC(){DC();DC();DC();}
	void FCC(){FC();FC();FC();}
	void BCC(){BC();BC();BC();}
	//-----------------------------------------

	//====6 Base Double Rotations====
	void R2(){RC();RC();}
	void L2(){LC();LC();}
	void U2(){UC();UC();}
	void D2(){DC();DC();}
	void F2(){FC();FC();}
	void B2(){BC();BC();}


	//-----------------------------------------
	//=====================================================















































	//---------Debug colors----------
	void debugcout(int color){
		if(color == 1) cout << BGWHITE << "■" << Null;
		else if(color == 2) cout << BGRED << "■" << Null;
		else if(color == 3) cout << BGBLUE << "■" << Null;
		else if(color == 4) cout << BGYELLOW << "■" << Null;
		else if(color == 5) cout << BGORANGE << "■" << Null;
		else if(color == 6) cout << BGGREEN << "■" << Null;
	}

	//---------Debug sides---------
	int DebugR[3][3] ={{1, 2, 3},
				  	   {4, 5, 6},
				  	   {7, 8, 9}};
	//-----------------------
	int DebugL[3][3] ={{1, 2, 3},
					   {4, 5, 6},
					   {7, 8, 9}};
	//-----------------------
	int DebugU[3][3] ={{1, 2, 3},
				 	   {4, 5, 6},
					   {7, 8, 9}};
	//-----------------------
	int DebugD[3][3] ={{1, 2, 3},
					   {4, 5, 6},
					   {7, 8, 9}};
	//-----------------------
	int DebugF[3][3] ={{1, 2, 3},
					   {4, 5, 6},
					   {7, 8, 9}};
	//-----------------------
	int DebugB[3][3] ={{1, 2, 3},
					   {4, 5, 6},
					   {7, 8, 9}};

	//----------------Debug----------------
	void Debug(){
		system("clear");
		//Backside - Orange (Should be orange but is rendered yellow)
		for(int i = 0; i < 3; i++){
		cout << "      ";
			for(int i2 = 0; i2 < 3; i2++){
				debugcout(B[i][i2]); cout << " ";
			} cout <<endl;
		}

		//Upside - Black (Should be yellow)
		for(int i = 0; i < 3; i++){
		cout << "      ";
			for(int i2 = 0; i2 < 3; i2++){
				debugcout(U[i][i2]); cout << " ";
			} cout <<endl;
		}

		//Leftside, Frontside, Rightside - Blue, Red, Green
		for(int i = 0; i < 3; i++){
			int threecntr = 1;
			int switcher = 1;
			for(int i2 = 0; i2 < 9; i2++){
				if(switcher == 1) {debugcout(L[i][i2]); cout << " ";}
				else if(switcher == 2) {debugcout(F[i][i2-3]); cout << " ";}
				else if(switcher == 3) {debugcout(R[i][i2-6]); cout << " ";}
				if(threecntr == 3){
					threecntr = 1;
					switcher++;
				} else threecntr++;
			} cout <<endl;
		}

		//Downside - White
		for(int i = 0; i < 3; i++){
		cout << "      ";
			for(int i2 = 0; i2 < 3; i2++){
				debugcout(D[i][i2]); cout << " ";
			} cout <<endl;
		}
	}
	
	
	//------------------------
}; 
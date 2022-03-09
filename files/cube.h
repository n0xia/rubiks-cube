#include <bits/stdc++.h>
using namespace std;
// Dependencies: iostream, string, vector, sstream
//----------colors----------
#define WHITE "\e[1m"
#define RED "\e[31m"
#define BLUE "\e[34m"
#define YELLOW "\e[1;30m"
#define ORANGE "\e[33m"
#define GREEN "\e[32m"
//-------
#define GRAY "\e[2;37m"
//-----BG-----
#define BGWHITE "\e[30m\e[1;47m"
#define BGRED "\e[41m"
#define BGBLUE "\e[44m"
#define BGYELLOW "\e[1;40m"
#define BGORANGE "\e[1;43m"
#define BGGREEN "\e[42m"
//----Misc----
#define Null "\e[0m"
#define BOLD "\e[1m"
#define UNDERLINED "\e[4m"
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
	void DisplayCube(){
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

	//====/====//=Rotation Functions=//====/====//
	int temp[3]; // temp vars
	int ftemp;
	//=========/=/ Face Rotations /=/==========//
	//-------------- Clockwise --------------
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

	// Left Clockwise
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

	// Up Clockwise
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
	
	// Down Clockwise
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

	// Front Clockwise
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

	// Back Clockwise
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
	//---- Counter-Clockwise ----
	void RCC(){RC();RC();RC();}
	void LCC(){LC();LC();LC();}
	void UCC(){UC();UC();UC();}
	void DCC(){DC();DC();DC();}
	void FCC(){FC();FC();FC();}
	void BCC(){BC();BC();BC();}
	//---- Double Rotations ----
	void R2(){RC();RC();}
	void L2(){LC();LC();}
	void U2(){UC();UC();}
	void D2(){DC();DC();}
	void F2(){FC();FC();}
	void B2(){BC();BC();}
	//--------------------------
	//==========/=/ Slice Rotations /=/==========//
	//---- Clockwise ----
	void M(){ // Middle slice
		for(int i = 0; i < 3; i++) temp[i] = F[i][1];
		for(int i = 0; i < 3; i++) F[i][1] = U[i][1];
		for(int i = 0; i < 3; i++) U[i][1] = B[i][1];
		for(int i = 0; i < 3; i++) B[i][1] = D[i][1];
		for(int i = 0; i < 3; i++) D[i][1] = temp[i];
	}

	void E(){ // Equator slice
		for(int i = 0; i < 3; i++) temp[i] = F[1][i];
		for(int i = 0; i < 3; i++) F[1][i] = L[1][i];
		for(int i = 0; i < 3; i++) L[1][i] = B[1][2-i];
		for(int i = 0; i < 3; i++) B[1][2-i] = R[1][i];
		for(int i = 0; i < 3; i++) R[1][i] = temp[i];
	}

	void S(){ //Standing slice
		for(int i = 0; i < 3; i++) temp[i] = U[1][i];
		for(int i = 0; i < 3; i++) U[1][i] = L[2-i][1];
		for(int i = 0; i < 3; i++) L[i][1] = D[1][i];
		for(int i = 0; i < 3; i++) D[1][i] = R[2-i][1];
		for(int i = 0; i < 3; i++) R[i][1] = temp[i];
	}
	//---- Counter-Clockwise ----
	void MCC(){M();M();M();}
	void ECC(){E();E();E();}
	void SCC(){S();S();S();}
	//---- Double ----
	void M2(){M();M();}
	void E2(){E();E();}
	void S2(){S();S();}
	//--------------------------
	//==========/=/ Double Layer Rotations /=/==========//
	//-------- Clockwise --------
	void rC(){RC();MCC();}
	void lC(){LC();M();}
	void uC(){UC();ECC();}
	void dC(){DC();E();}
	void fC(){FC();S();}
	void bC(){BC();SCC();}
	//---- Counter-Clockwise ----
	void rCC(){RCC();M();}
	void lCC(){LCC();MCC();}
	void uCC(){UCC();E();}
	void dCC(){DCC();ECC();}
	void fCC(){FCC();SCC();}
	void bCC(){BCC();S();}
	//------ Double turns -------
	void r2(){R2();M2();}
	void l2(){L2();M2();}
	void u2(){U2();E2();}
	void d2(){D2();E2();}
	void f2(){F2();S2();}
	void b2(){B2();S2();}
	//==========/=/ Whole Cube Rotations /=/==========//
	//-------- Clockwise --------
	void X(){RC();LCC();MCC();}
	void Y(){UC();DCC();ECC();}
	void Z(){FC();BCC();S();}
	//---- Counter-Clockwise ----
	void XCC(){RCC();LC();M();}
	void YCC(){UCC();DC();E();}
	void ZCC(){FCC();BC();SCC();}
	//------- Double Turns ------
	void X2(){R2();L2();M2();}
	void Y2(){U2();D2();E2();}
	void Z2(){F2();B2();S2();}
	//==============END OF TURN FUNCTIONS=============//
	
	void movePause(double seconds){ // Pause/Sleep function for Linux (bash)
		stringstream convIntToString; // using stringstream to convert int
		convIntToString << seconds;   // input to string so it can later
		string sleepSeconds;          // be concatenated and turned into a
		convIntToString >> sleepSeconds; // const char using c_str() STL
		string sleepCommand = "sleep "; // function.
		system((sleepCommand + sleepSeconds).c_str());
	}

	vector <string> Moves; // Each move is stored here
	// function that separates each move from an input 
	// string and inserts them into a vector
	void Input(){
		cout << "Seperate each rotation with Space, end input with Enter." << endl;
		cout << "Input: ";
		string input;
		getline(cin, input, '\n');

		stringstream ss;
		ss << input;
		string tempvar;
		while(!ss.eof()){
			ss >> tempvar;
			Moves.push_back(tempvar);
		}
	}

	void rotateCube(string Notation){ // Activating turn functions through notation;
		//===/=/ Face Rotations /=/===//
		//------ Clockwise ------
			 if(Notation == "R") RC();
		else if(Notation == "L") LC();
		else if(Notation == "U") UC();
		else if(Notation == "D") DC();
		else if(Notation == "F") FC();
		else if(Notation == "B") BC();
		//------ Counter Clockwise ------
		else if(Notation == "R'") RCC();
		else if(Notation == "L'") LCC();
		else if(Notation == "U'") UCC();
		else if(Notation == "D'") DCC();
		else if(Notation == "F'") FCC();
		else if(Notation == "B'") BCC();
		//------ Double ------
		else if(Notation == "R2") R2();
		else if(Notation == "L2") L2();
		else if(Notation == "U2") U2();
		else if(Notation == "D2") D2();
		else if(Notation == "F2") F2();
		else if(Notation == "B2") B2();
		//===/=/ Double Layer Rotations /=/===//
		//------ Clockwise ------
		else if(Notation == "r") rC();
		else if(Notation == "l") lC();
		else if(Notation == "u") uC();
		else if(Notation == "d") dC();
		else if(Notation == "f") fC();
		else if(Notation == "b") bC();
		//------ Counter Clockwise ------
		else if(Notation == "r'") rCC();
		else if(Notation == "l'") lCC();
		else if(Notation == "u'") uCC();
		else if(Notation == "d'") dCC();
		else if(Notation == "f'") fCC();
		else if(Notation == "b'") bCC();
		//------ Double ------
		else if(Notation == "r2") r2();
		else if(Notation == "l2") l2();
		else if(Notation == "u2") u2();
		else if(Notation == "d2") d2();
		else if(Notation == "f2") f2();
		else if(Notation == "b2") b2();
		//===/=/ Middle Slice Rotations /=/===//
		//------ Clockwise ------
		else if(Notation == "M") M();
		else if(Notation == "E") E();
		else if(Notation == "S") S();
		//------ Counter Clockwise ------
		else if(Notation == "M'") MCC();
		else if(Notation == "E'") ECC();
		else if(Notation == "S'") SCC();
		//------ Double ------
		else if(Notation == "M2") M2();
		else if(Notation == "E2") E2();
		else if(Notation == "S2") S2();
		//===/=/ Whole Cube Rotations /=/===//
		//------ Clockwise ------
		else if(Notation == "X" || Notation == "x") X();
		else if(Notation == "Y" || Notation == "y") Y();
		else if(Notation == "Z" || Notation == "z") Z();
		//------ Counter Clockwise ------
		else if(Notation == "X'" || Notation == "x'") XCC();
		else if(Notation == "Y'" || Notation == "y'") YCC();
		else if(Notation == "Z'" || Notation == "z'") ZCC();
		//------ Double ------
		else if(Notation == "X2" || Notation == "x2") X2();
		else if(Notation == "Y2" || Notation == "y2") Y2();
		else if(Notation == "Z2" || Notation == "z2") Z2();
	}

	void DisplayNotation(int currentMove){
		cout << BOLD << "Progress" << Null << ": ";
		for(int i = 0; i < Moves.size(); i++){
			if(i < currentMove) cout << GRAY << Moves[i] << Null << " ";
			if(i == currentMove) cout << UNDERLINED << RED << Moves[i] << Null << " ";
			if(i > currentMove) cout << BLUE << Moves[i] << Null << " ";
		} cout <<endl;
	}

	bool isCubeSolved(){
		for(int i = 0; i < 3; i++){
			for(int i2 = 0; i2 < 3; i2++){
				if(R[i][i2] != 6 ) return false;
				if(L[i][i2] != 3 ) return false;
				if(U[i][i2] != 4 ) return false;
				if(D[i][i2] != 1 ) return false;
				if(F[i][i2] != 2 ) return false;
				if(B[i][i2] != 5 ) return false;
			}
		}
		return true;
	}
	//=====/=/=====<[MAIN DISPLAY FUNCTION]>=====/=/=====//
	void Display(double sleepTime){
		DisplayCube();
		movePause(1);

		for(int i = 0; i <= Moves.size(); i++){
			if(i != Moves.size()){
			rotateCube(Moves[i]);
			DisplayCube();
			DisplayNotation(i);
			}
			else {
			DisplayCube();
			DisplayNotation(i);
			}
			movePause(sleepTime);
		}
	}
	//=====/=/=====<[CYCLING FUNCTION]>=====/=/=====//
	void Periodicity(double sleepTime){
		int cycle = 0;
		if(sleepTime != 0){
			DisplayCube();
			movePause(1);
			while(true){
				for(int i = 0; i < Moves.size(); i++){
					rotateCube(Moves[i]);
					DisplayCube();
					DisplayNotation(i);
					cout << "Cycles: " << cycle << endl;
					movePause(sleepTime);
				}
				cycle++;
				if(isCubeSolved()) break;
			}
			DisplayCube();
			DisplayNotation(Moves.size());
			cout << "Cycles: " << cycle << endl;
		}
		else{
			while(true){
				for(int i = 0; i < Moves.size(); i++){
					rotateCube(Moves[i]);
				}
				cycle++;
				if(isCubeSolved()) break;
			}
			system("clear");
			cout << "Cycles for" << endl;
			for(int i = 0; i < Moves.size(); i++) cout << Moves[i] << " "; cout << ": " << cycle <<endl;
		}
	}

	void DisplayNormalTurns(){
		double sleepTime;
		system("clear");
		cout << "Input ammount of seconds to pause between each move: "; cin >> sleepTime;
		cin.ignore();
		Input();
		Display(sleepTime);
	}

	void DisplayPerodicity(){
		double sleepTime;
		system("clear");
		cout << "Input ammount of seconds to pause between each move. " <<endl;
		cout << "Enter \"0\" to instantly go through all cycles: "; cin >> sleepTime;
		cout << "Input algorithm to count cycle periodicity to. " <<endl;
		cin.ignore();
		Input();
		Periodicity(sleepTime);
	}

};
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
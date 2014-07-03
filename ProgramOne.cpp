//Rob Fugate
//CS222 - Data Structures - Program 1
//Purpose: To have a use enter a decimal number of any length have have the program convert it to a binary number.

#include <iostream>
#include <string>
#include <math.h>
#include "ProgramOne.h"
using namespace std;

int main(){
	string answer = "";			//This string will build the binary number
	string a = "";				//This string will hold the decimal number the user enters
	bool strAnswer = false;
	cout << "Please enter a string: ";
	getline(cin,a);
	if(a == "0") cout << "Binary: 0" << endl;
	for(int i = 0; i <= a.length() - 1; i++){		//check to verify that the number entered is indeed a number and contains no letters
		if((a[i] >= '0') && (a[i] <= '9')) strAnswer = true;
		else{
			strAnswer = false;
			break;
		}
	}
	while((strAnswer != false) && (a != "0")){		//This will build the binary number as long as the string contains no numbers and is no 0
		if(a[a.length()-1] %2 == 0){
			answer = "0" + answer;
		}
		else{
			answer = "1" + answer;
		}
		a = divide(a);
		if(a == "0"){
			answer = rlz(answer);
			cout << "Binary: " << answer << endl;
		}
	}
	if(strAnswer == false){
		cout << "You have entered an incorrect integer value.." << endl;
	}
	system("pause");
}
string divide(string a){
	string b = "";		//String b will hold the new number that is going to be divided by in the next pass.
	int c = 0;			//int c will hold the remainder and be added to num
	for(int i=0; i <= (int)a.length()-1; i++){
		int num = (a[i] - '0') + c;					//takes first character in string and converts to integer. Then adds c to it
		b = (string)(b) + (char)((num / 2) + '0');	//takes number divided by two and adds the converted integer value to String B
		c = (num % 2) * 10;							//takes the remainder of number and multiplies it by 10 to be readded in the first step.
	}
	b = rlz(b);
	return b;
}

string rlz(string b){
	//Remove leading zeros - Helps speed up calculations
	while (b[0]=='0' && b.length() > 1) b = b.substr(1);
	return b;
}

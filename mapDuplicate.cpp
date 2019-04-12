//
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

void parse(string title, string num, map<string,int> &table, int &index, int &matchNum){
	string temp = "";

	//for loop to iterate the line, char by char, & loading into temp
	for(int i = 0; i < num.length(); i++){
		int j = i % 5;
		temp[j] = num[i];

		//if the string has enough characters or is at the end of the line
		if(j == 4 || i == num.length() -1){
			string text = title+temp[0]+temp[1]+temp[2]+temp[3];	//skip temp[4] (,)

			//if string already exists in map, inc the value to 2
			if(table[text] > 0){
				table[text]++;
				matchNum++;
				cout <<"\t"<< text << "\t";
				if (matchNum % 4 == 0) cout << endl;
			}
			else
				table[text] = 1;//inserting item into map
			index++;
		}
	}
}

int main(){
	//create map - self balancing BST & variables
	map <string,int> table;
	string title, number; 				//hold courseTitle and courseNumber
	int index = 0, matchNum = 0;			//holds totalClasses and totalMatches

	//display all the duplicates
	cout << "All these classes match C.3 and Z." << endl;

	//open file and parse string into tokens, then add to map
	ifstream fin;
	fin.open("c.txt");
	while(getline(fin, title, ' ')){		//holds title
		getline(fin, number, '\n');		//grabs line full of different course numbers
		parse(title, number, table, index, matchNum);
	}
	fin.close();

	//open file and parse string into tokens, then add to map
	fin.open("z.txt");
	while(getline(fin, title, ' ')){
		getline(fin, number, '\n');
		parse(title, number, table, index, matchNum);
	}

	cout << "\t\t   We have " << matchNum << " matches in C.3 and Z." << endl;
	cout << "\t\t   We have " << index << " total classes in C.3 and Z." << endl;
}

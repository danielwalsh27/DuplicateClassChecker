#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void parse(string title, string num, string classes[], int &index){
	//parsing the items into small strings and adding those strings into the array
	string temp;
	for(int i = 0; i < num.length(); i++){
		int j = i % 5;
		temp[j] = num[i];
		if(j == 4 || i == num.length() -1){
			string text = title+temp[0]+temp[1]+temp[2]+temp[3];
			classes[index] = text;		//this is where it loads into array
			index++;
		}
	}
}
int findMatch(string classes[ ], int index){
	//sorts array
	int size = sizeof(classes)\sizeof(classes[0]);
	sort(classes, classes+size);
	int count = 0;
	for(int i = 0; i < index; i++){
		if (classes[i] == classes[i+1]){		//this is where it compares array
			cout << "\t" << classes[i] << "\t";
			count++;
			if (count % 4 == 0) cout << endl;
		}
	}
	return count;
}

int main(){
	//creating array & variables
	string *classes;
	classes = new string[400];				//this is where it creates array
	string title, number;
	int index = 0, matchNum;

	//open c.txt and parse the classes into the array
	ifstream fin;
	fin.open("c.txt");
	while(getline(fin, title, ' ')){
		getline(fin, number, '\n');
		parse(title, number, classes, index);
	}
	fin.close();

	//open z.txt and parse the classes into the array
	fin.open("z.txt");
	while(getline(fin, title, ' ')){
		getline(fin, number, '\n');
		parse(title, number, classes, index);
	}

	//display duplicates
	cout << "All these classes match C.3 and Z." << endl;
	matchNum = findMatch(classes, index);
	cout << "\t\t   We have " << matchNum << " matches in C.3 and Z." << endl;
	cout << "\t\t   We have " << index << " total classes in C.3 and Z." << endl;
	delete classes;
}

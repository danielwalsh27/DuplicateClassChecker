#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
using namespace std;

void parse(string title, string num, unordered_set<string> &set, int &index, int &number){
	string temp;

	//for loop to iterate the line char by char and loading into temp string
	for(int i = 0; i < num.length(); i++){
		int j = i % 5;
		temp[j] = num[i];

		//if temp is full or at the end of the line
		if(j == 4 || i == num.length() -1){
			bool found = false;
			string text = title+temp[0]+temp[1]+temp[2]+temp[3];	//skip temp[4] (,)

			//using .find to search for the item with speed of O(1)A
			unordered_set<string>::iterator it = set.find(text);		//auto it = set.find(text);

			//if it did not reach the end, due to a successful search, display
			if(it != set.end()){
				found = true;
				cout << "\t" << *it << "\t";
				number++;
				if (number % 4 == 0) cout << endl;
			}
			if(!found)						//if not in table yet, load
				set.insert(text);
			index++;
		}
	}//end of for loop
}

int main(){
	//create hash set & variables
	unordered_set <string> myset;
	string title, number; 				//hold courseTitle and courseNumber
	int index = 0, findCount = 0;			//holds totalClasses and totalMatches

	//display all the duplicates
	cout << "All these classes match C.3 and Z." << endl;

	//open file and parse into tokens, to add to set
	ifstream fin;
	fin.open("c.txt");
	while(getline(fin, title, ' ')){		//holds title
		getline(fin, number, '\n');		//grabs line full of different course numbers
		parse(title, number, myset, index, findCount);
	}
	fin.close();

	//open file and parse string into tokens, then add to hash set
	fin.open("z.txt");
	while(getline(fin, title, ' ')){
		getline(fin, number, '\n');
		parse(title, number, myset, index,findCount);
	}

	cout << "\t\t   We have " << findCount << " matches in C.3 and Z." << endl;
	cout << "\t\t   We have " << index << " total classes in C.3 and Z." << endl;
}

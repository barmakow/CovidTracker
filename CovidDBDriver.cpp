#include "DataEntry.h"
#include "CovidDB.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<string> split(string str, char del){
    vector<string> result;
    // declaring temp string to store the curr "word" upto del
    string temp = "";
    for(int i=0; i<(int)str.size(); i++){
        // If current char is not ',', then append it to the "word", otherwise you
have completed the word, and start the next word
        if(str[i] != del){
    temp += str[i];
        }else{
            result.push_back(temp);
            temp = "";
} }
    // push the last substring after the last ',' to the result
    result.push_back(temp);
    return result;
}
int main(){
    int choice = -1;
    CovidDB hashtb(17);
    do{
        cout << "COVID Tracker\n" << "Please choose the operation you want:\n";
        cout << "1. Create the initial hash table\n";
        cout << "2. Add a new data entry\n";
        cout << "3. Get a data entry\n";
        cout << "4. Remove a data entry\n";
        cout << "5. Display hash table\n";
        cout << "0. Quit the system\n" << endl;
        cin >> choice;
        switch(choice){
            case 1:
            {
                // open the file and create hash table
                ifstream file("WHO-COVID-Data.csv");
                if(file.is_open()){
push it to the
string line;
while(getline(file, line)){
    // split the content in each line
    vector<string> result = split(line, ',');
    // wrap up all the data in the string to a cvsdata type and
    DataEntry oneEntry;
    oneEntry.setDate(result[0]);
    oneEntry.setCountry(result[1]);
    oneEntry.setCases(stoi(result[2]));
                        oneEntry.setDeaths(stoi(result[3]));
                        //cout << oneEntry.getDate() << " " <<
oneEntry.getCountry() << " " << oneEntry.getCases() << " " << oneEntry.getDeaths();
                        //cout << endl;
                        hashtb.add(oneEntry);
                    }
                    cout << "Open File Success" << endl;
                }else{
                    cout << "Open file failed" << endl;
                }
break; }
case 2: {
                //adds country/updates country of user's choice
                cout << "Enter an entry in csv format (date, country, cases,
                string line;
                cin >> line;
                vector <string> result = split(line, ',');
                DataEntry oneEntry;
                oneEntry.setDate(result[0]);
                oneEntry.setCountry(result[1]);
                oneEntry.setCases(stoi(result[2]));
                oneEntry.setDeaths(stoi(result[3]));
                hashtb.add(oneEntry);
                break;
}
case 3:
            {
                //gets the country of user's choice
                string country;
                cout << "What country would you like to search for: ";
                cin >> country;
                DataEntry* found = hashtb.get(country);
                cout << found->getDate() << " " << found->getCountry() << " " <<
found->getCases() << " " << found->getDeaths();
cout << endl;
break; }
case 4: {
                //removes country of user's choice
                string country;
                cout << "What country do you want to remove: ";
                cin >> country;
                hashtb.remove(country);
                break;
}
case 5: {
deaths): \n";
//hash table is displayed in all of its glory

cout << "Here is the whole table:\n";
                hashtb.displayTable();
                break;
}
case 0:
            {
                //program quits
                cout << "Program quit." << endl;
break; }
}
    }while(choice != 0);
}
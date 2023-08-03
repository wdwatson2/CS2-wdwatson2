#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string titleTemp;
    char* title;
    double* values;
    // char title[100];
    ifstream fin;
    
    fin.open("dataset.txt");

    getline(fin, titleTemp);

    int length = titleTemp.length();

    title = new char[length+1];

    strcpy(title, titleTemp.c_str());

    // fin.getline(title, 1000, '\n');
    // title = &titleTemp;

    // for(int i = 0; i < length; i++){
    //     cout << title[i];
    // }
    // cout << endl;


    double num;

	if(!(values = new double[1000000])){
		exit(EXIT_SUCCESS);
	}

	int counter = 0; //will count how many values are read in

	while(getline(fin, titleTemp)){
        num = stod(titleTemp);
		values[counter] = num;
		counter++;
	}

	int numvals = counter;


    sort(values, values+numvals);

    for(int j = 0; j < numvals; j++){
        cout << values[j] << endl;
    }

    char * temp;
    cout << strlen(title) << endl;
    temp = new char[strlen(title) + 1];
    strcpy(temp, title);

    for(int i = 0; i < strlen(title); i++){
        cout << temp[i];
    }
    cout << endl;

    double* val;
    val = new double[numvals];
    for(int i = 0; i < numvals; i++){
        val[i] = values[i];
    }

    for(int j = 0; j < numvals; j++){
        cout << val[j] << endl;
    }

    delete[] val;
    delete[] temp;
    delete[] title;
    delete[] values;
    return 0;
}
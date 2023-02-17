#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "main.h"

using namespace std;
namespace fs = filesystem;

int main() {
    //When Main is run, delete all existing output.csv files
    for (const auto &entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == ".csv" && entry.path().stem() != "input") {
            fs::remove(entry.path());
        }
    }
    
    //Open input file as 'input'
    ifstream input("input.csv");
    if(!input.is_open()){
        cerr << "Error opening file" << endl;
    }

    //Temp container for each line in input
    string line;
    //Total amount of lines in input csv
    int total_lines{};
    //How many rows to split the csv by
    unsigned int split_by_amount{};

    while(getline(input,line)) {
        total_lines++;
    }

    //Start reading from the beginning of the input file again after the initial while loop
    input.clear();
    input.seekg(0, ios::beg);

    //Ask user for amount of rows per csv they would like
    cout << "There are currently : " << (total_lines) << " rows" << endl;
    cout << "Enter the maximum number of rows you'd like per output file : ";
    cin >> split_by_amount;
    //Calculate the total files to be generated
    cout << "Splitting into " <<  (total_lines / split_by_amount) << " output files" << endl;
    //Run through Split function to create outputs
    split(total_lines, split_by_amount);

    return 0;

}
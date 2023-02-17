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
    bool file_exists = true;
    string provided_file_path;
    cout << endl;
    cout << "Enter file path or drag and drop your csv file here and hit enter when done" << endl;
    cin >> provided_file_path;
    cout << endl;
    ifstream input(provided_file_path);
    if(!input.is_open()){
        cerr << "File failed to load, please try again..." << endl;
        file_exists = false;
    }
    while(file_exists) {
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
        cout << "\033[35m" << "There are currently : " << (total_lines) << " rows" << "\033[0m" << endl;
        cout << "Enter the maximum number of rows you'd like per output file : ";
        cin >> split_by_amount;
        //Calculate the total files to be generated
        unsigned int remainder = total_lines % split_by_amount;
        cout << "\033[35m" << "Splitting into " <<  (remainder == 0 ? total_lines / split_by_amount : total_lines / split_by_amount + 1) << " output files" << "\033[0m" << endl;
        cout << "\033[35m" << "Check your input file's directory to view outputs..." << "\033[0m" << endl;
        cout << endl;

        //Run through Split function to create outputs
        split(provided_file_path, total_lines, split_by_amount);
        file_exists = false;
    }

    return 0;

}
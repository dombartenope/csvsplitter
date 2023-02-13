#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void split(unsigned int total_number_of_rows, unsigned int split_by_amount) {

    ifstream input("input.csv");
    if(!input.is_open()){
        cerr << "Error opening file" << endl;
    }

    size_t count{};

    string line;

    unsigned int total_files_needed = (total_number_of_rows / split_by_amount);

    vector<ofstream> outputs(total_files_needed);

    while(getline(input, line)){
        for(int i {}; i < total_files_needed; i++) {
            string file_name = "file" + to_string(i) + ".csv";
            outputs[i].open(file_name);
            while(count < split_by_amount){
                outputs[i] << line << endl;
                count++;
            }
            count = 0;
        }
    }

}
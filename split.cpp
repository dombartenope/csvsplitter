#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void split(unsigned int total_number_of_rows, unsigned int split_by_amount) {
    //Read from input.csv again
    ifstream input("input.csv");
    //If file does not open, output an error
    if (!input.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }
    //Define a row that will change values in loop
    string line;
    //Create a vector of output files needed
    vector<ofstream> outputs;

    unsigned int remainder = total_number_of_rows % split_by_amount;
    // Open output files
    if(remainder == 0) {
        for (int i = 0; i < total_number_of_rows / split_by_amount; i++) {
            string file_name = "file" + to_string(i) + ".csv";
            outputs.emplace_back(file_name);
        }
    } else {
        for (int i = 0; i < total_number_of_rows / split_by_amount + 1; i++) {
            string file_name = "file" + to_string(i) + ".csv";
            outputs.emplace_back(file_name);
        }
    }

    // Split input file into output files
    int count = 0;
    while (getline(input, line)) {
        outputs[count / split_by_amount] << line << endl;
        count++;
    }

    // Close output files
    for (auto& output : outputs) {
        output.close();
    }
}

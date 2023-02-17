#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void split(const string& provided_file_path, unsigned int total_number_of_rows, unsigned int split_by_amount) {
    fs::path input_file_path(provided_file_path);
    fs::path output_dir_path = input_file_path.parent_path();
    //Read from input.csv again
    ifstream input(provided_file_path);
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
            fs::path file_path = output_dir_path / ("file" + to_string(i) + ".csv");
            outputs.emplace_back(file_path);
        }
    } else {
        for (int i = 0; i < total_number_of_rows / split_by_amount + 1; i++) {
            fs::path file_path = output_dir_path / ("file" + to_string(i) + ".csv");
            outputs.emplace_back(file_path);
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

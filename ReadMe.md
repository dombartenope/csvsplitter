# CSV Splitter
- Basic functionality that will take a csv file and determine how many files to split it into based on user input
- Used for splitting csv's with millions of rows into files that Excel/Sheets can accept

## To compile:
1. Use Clang++ or GCC compiler to run main.cpp
`g++ main.cpp -o main`
2. In same directory as the main executable, add an `input.csv` with the starting data to split
3. From terminal run: `./main` or `./<name of the executable>`
4. Files will be output in the same folder. 
- .vscode file included to allow c++20 syntax
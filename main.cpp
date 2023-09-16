#include <iostream>

#include "QueryResult.h"
#include "TextQuery.h"

using namespace std;

void runQueries(std::ifstream& infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "Please enter word to look for, or q to quit: ";
        std::string s;
        if (!(cin >> s) || s == "q") {
            break;
        }

        print(cout, tq.query(s)) << endl;
    }
}

int main(const int argc, const char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " + file name" << std::endl;
        return -1;
    }
    std::string file_name = argv[1];

    std::ifstream infile(file_name);
    if (!infile) {
        std::cerr << "Cannot open file" << std::endl;
        return -1;
    }

    runQueries(infile);

    return 0;
}
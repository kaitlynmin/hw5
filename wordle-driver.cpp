// // main() program to test your schedule function.
// // Feel free to modify though it will be easiest to
// // simply pass in different command line arguments to test
// // various cases of words and letters.
// // This file will not be graded. 
// #include <iostream>
// #include <set>
// #include <string>
// #include "wordle.h"
// #include "dict-eng.h"
// using namespace std;

// int main(int argc, char* argv[])
// {
//     // if(argc < 2){
//     //     cout << "Please provide an initial string (e.g. \"s---ng\")"
//     //             " and optional string of floating characters." << endl;
//     //     return 1;
//     // }
//     // cout << "Stop 1";
//     const std::set<std::string>& dict = readDictWords("dict-eng.txt");
//     // cout << "Stop 2";
//     string in(argv[1]);
//     string floatingChars;
//     // if(argc > 2){
//     //     floatingChars = argv[2];
//     // }
//     std::set<string> answers;
//     answers = wordle(in, floatingChars, dict);
//     for(auto s : answers){
//         cout << s << endl;
//     }
//     return 0;


// }

#include <iostream>
#include <set>
#include "wordle.h" // Include your header file here
#include "dict-eng.h" // Include your dictionary header file here

int main() {
    std::string in = "--";
    std::string floating = "a";
    std::set<std::string> dict = {"ad", "ah", "am", "an", "as", "at", "ax", "ay", "fa", "ha", "la", "ma", "pa"};

    std::set<std::string> result = wordle(in, floating, dict);

    std::cout << "Generated words:" << std::endl;
    for (const auto& word : result) {
        std::cout << word << std::endl;
    }

    return 0;
}
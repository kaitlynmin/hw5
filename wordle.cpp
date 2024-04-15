#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void generateWords(std::string& word, const std::string& floating,
                  const std::set<std::string>& dict, std::set<std::string>& answer,
                  int count);

bool floatingAndOpen(const std::string& word, const std::string& floating);


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
  std::set<std::string> answer;
  if (in.empty()) {
    return answer;
  }

  std::string word = in;

  //recursive function to generate all possible words
  generateWords(word, floating, dict, answer, 0);

  return answer;
}

// recursive function to generate all possible words
void generateWords(std::string& word, const std::string& floating,
                  const std::set<std::string>& dict, std::set<std::string>& answer,
                  int index) {

  //if word size is equal to the number of fixed letters
  if (index == static_cast<int>(word.size())) {
    if (dict.find(word) != dict.end()) {
       // std::cout << word << " good";
      answer.insert(word);
    }
     //std::cout << word << endl;
    return;
  }

  if (word[index] != '-') {
    generateWords(word, floating, dict, answer, index +1);
    return;
  }

  // only need this for when the number of floating is equal to the # of spaces open
  if (floatingAndOpen(word, floating)) {
    for(size_t i=0; i < floating.size(); ++i) {
      std::string next_in = word;
      next_in[index] = floating.front();
      std::string newFloating = floating;
      newFloating.erase(i, 1);
      generateWords(next_in, newFloating, dict, answer, index + 1);
      }
  } else {
    // deal with when random letter is equal to one of the floating letters, get rid of floating letter
    for (char c = 'a'; c <= 'z'; c++) {
      std::string next_in = word;
      next_in[index] = c;

      auto found = floating.find(c);
      if (found != std::string::npos) {
        std::string newFloating = floating;
        newFloating.erase(found, 1);
        generateWords(next_in, newFloating, dict, answer, index+1);
      } else {
      generateWords(next_in, floating, dict, answer, index + 1);
      }
    }
  }
}


bool floatingAndOpen(const std::string& word, const std::string& floating) {
  int openSpots = std::count(word.begin(), word.end(), '-');
  return static_cast<int>(floating.size()) == openSpots;
}


 // for (char a : floating) {
      //   if (c == a) {
      //     int floatingIndex = floating.find(a);
      //     std::string newFloating = floating;
      //     newFloating.erase(floatingIndex, 1);
      //   }
      // }


// Define any helper functions here

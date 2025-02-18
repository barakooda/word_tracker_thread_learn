#include "WordTracker.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>

// Utility function to trim whitespace from both ends of a string.
std::string trim(const std::string &str)
{
  size_t start = str.find_first_not_of(" \t\r\n");
  if (start == std::string::npos)
    return "";
  size_t end = str.find_last_not_of(" \t\r\n");
  return str.substr(start, end - start + 1);
}

// Checks that the given word is valid (i.e. contains no spaces).
// The termination keyword "end" is considered valid.
bool isValidWord(const std::string &word)
{
  if (word == "end")
    return true;
  return word.find(' ') == std::string::npos;
}

// Prints the program title.
void printWordTrackerTitle()
{
  std::cout << "------------------------------------------------\n";
  std::cout << "------------------------------------------------\n";
  std::cout << R"(
         __   __   __             
   |  | /  \ |__) |  \            
   |/\| \__/ |  \ |__/            
                                  
___  __        __        ___  __  
 |  |__)  /\  /  ` |__/ |__  |__) 
 |  |  \ /~~\ \__, |  \ |___ |  \ 
                                  
)" << std::endl;
  std::cout << "Welcome to the Word Counter Program!\n";
  std::cout << "Please enter a list of words, one per line.\n";
  std::cout << "When you are done, type 'end' to finish.\n";
  std::cout << "------------------------------------------------\n";
  std::cout << "------------------------------------------------\n";
}

// Reads words from STDIN with validation and pushes them into the provided queue.
void readInputWords(ThreadSafeWordQueue &wordQueue)
{
  std::string inputLine;
  while (std::getline(std::cin, inputLine))
  {
    inputLine = trim(inputLine);
    if (inputLine.empty())
      continue;  // Skip blank lines.

    if (!isValidWord(inputLine))
    {
      std::cout << "Warning: Invalid input. Please enter a single word only. Input ignored: " 
                << inputLine << "\n";
      continue;
    }
    wordQueue.pushWord(inputLine);
    if (inputLine == "end")
      break;
  }
}

// Copies the word counts into a vector, sorts them alphabetically, and prints them.
void printSortedWordList(const std::unordered_map<std::string, int>& counts)
{
  std::vector<std::pair<std::string, int>> sortedWordList(counts.begin(), counts.end());
  std::sort(sortedWordList.begin(), sortedWordList.end(),
            [](const auto &a, const auto &b) { return a.first < b.first; });
  std::cout << "\n=== Sorted Word List ===\n";
  for (const auto &entry : sortedWordList)
  {
    std::cout << entry.first << ": " << entry.second << "\n";
  }
}

// Handles interactive lookup (input is read until EOF is encountered).
void interactiveLookup(const std::unordered_map<std::string, int>& counts)
{
  std::cout << "\n=== Interactive Lookup Mode ===\n";
  std::cout << "You can now look up words in the list (Ctrl-D/Ctrl-Z to exit):\n";
  int totalFound = 0;
  std::string lookupWord;
  while (std::getline(std::cin, lookupWord))
  {
    lookupWord = trim(lookupWord);
    if (!isValidWord(lookupWord))
    {
      std::cout << "Error: Invalid input. Please enter a single word without spaces.\n";
      continue;
    }
    auto it = counts.find(lookupWord);
    if (it != counts.end())
    {
      std::cout << "SUCCESS: '" << it->first << "' was present " << it->second
                << " time(s) in the initial word list.\n";
      ++totalFound;
    }
    else
    {
      std::cout << "ERROR: '" << lookupWord << "' was NOT found in the initial word list.\n";
    }
  }
  std::cout << "\n=== Total words found: " << totalFound << " ===\n";
}

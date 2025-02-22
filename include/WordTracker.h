#ifndef WORD_TRACKER_H
#define WORD_TRACKER_H

#include <string>
#include <unordered_map>
#include "ThreadSafeWordQueue.h"

// Prints the Word Tracker program title.
void printWordTrackerTitle();

// Reads words from STDIN with input validation and pushes them into the provided queue.
// Ignores empty lines and rejects inputs with spaces (except for "end").
// Terminates when "end" is entered.
void readInputWords(ThreadSafeWordQueue &wordQueue);

// Prints the sorted word list from the given word count map.
void printSortedWordList(const std::vector<std::pair<std::string, int>>& sortedCounts);

// Handles interactive lookup of words (terminates on EOF).
void interactiveLookup(const std::unordered_map<std::string, int>& counts);

// Utility functions.
std::string trim(const std::string &str);
bool isValidWord(const std::string &word);

#endif // WORD_TRACKER_H

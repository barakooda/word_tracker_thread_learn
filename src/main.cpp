#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "ThreadSafeWordQueue.h"  // From include/
#include "WordCounter.h"          // From include/

// Reads words from standard input and pushes them into the provided queue.
// Terminates when the word "end" is encountered.
void readInputWords(ThreadSafeWordQueue & wordQueue) {
    std::string inputLine;
    while (std::getline(std::cin, inputLine)) {
        wordQueue.pushWord(inputLine);
        if (inputLine == "end")
            break;
    }
}

int main() {
    try {
        // Create our thread-safe queue and word counter.
        ThreadSafeWordQueue wordQueue;
        WordCounter wordCounter;
        
        // Launch a worker thread to process the queue.
        std::thread worker([&]() {
            wordCounter.processQueue(wordQueue);
        });
        
        // Read input words in the main thread.
        readInputWords(wordQueue);
        
        // Wait for the worker thread to finish processing.
        worker.join();
        
        // Retrieve the word counts from the WordCounter.
        std::unordered_map<std::string, int> counts = wordCounter.getWordCounts();
        
        // --- Sorting the Word List ---
        // Copy the counts into a vector for sorting.
        std::vector<std::pair<std::string, int>> sortedWordList(counts.begin(), counts.end());
        std::sort(sortedWordList.begin(), sortedWordList.end(),
                  [](const auto & a, const auto & b) {
                      return a.first < b.first;
                  });
        
        // Print the sorted word list.
        std::cout << "\n=== Sorted Word List ===\n";
        for (const auto & entry : sortedWordList) {
            std::cout << entry.first << ": " << entry.second << "\n";
        }
        
        // --- Interactive Lookup Mode ---
        std::cout << "\n=== Interactive Lookup Mode ===\n";
        int totalFound = 0;
        std::string lookupWord;
        while (true) {
            std::cout << "\nEnter a word for lookup (or Ctrl-D to exit): ";
            if (!(std::cin >> lookupWord))
                break;  // Exit on EOF.
            
            auto it = counts.find(lookupWord);
            if (it != counts.end()) {
                std::cout << "SUCCESS: '" << it->first << "' was present " 
                          << it->second << " times in the initial word list.\n";
                ++totalFound;
            } else {
                std::cout << "'" << lookupWord << "' was NOT found in the initial word list.\n";
            }
        }
        std::cout << "\n=== Total words found: " << totalFound << " ===\n";
    }
    catch (const std::exception & e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    
    return 0;
}

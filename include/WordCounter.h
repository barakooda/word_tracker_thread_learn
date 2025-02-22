#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include <unordered_map>
#include <mutex>
#include <string>
#include "ThreadSafeWordQueue.h"  // Make sure this header is in your include/ folder

class WordCounter {
public:
    // Processes words from the provided queue until the termination word ("end") is encountered.
    void processQueue(ThreadSafeWordQueue & wordQueue);

    // Retrieves a copy of the current word counts.
    std::unordered_map<std::string, int> getWordCounts() const;

    // Returns the counts sorted alphabetically as a vector of pairs.
    std::vector<std::pair<std::string, int>> getSortedCounts() const;

private:
    std::unordered_map<std::string, int> counts; // Internal container for word counts.
    mutable std::mutex countsMutex;              // Mutex to protect access to counts.
};

#endif // WORD_COUNTER_H

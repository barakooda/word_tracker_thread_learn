#include "WordCounter.h"
#include <algorithm>

void WordCounter::processQueue(ThreadSafeWordQueue & wordQueue) {
    while (true) {
        std::string word;
        // Pop a word from the queue (this will block until a word is available)
        wordQueue.popWord(word);

        // Terminate when "end" is encountered
        if (word == "end") {
            break;
        }

        // Update the count for this word in a thread-safe manner.
        {
            std::lock_guard<std::mutex> lock(countsMutex);
            ++counts[word];
        }
    }
}

std::unordered_map<std::string, int> WordCounter::getWordCounts() const {
    std::lock_guard<std::mutex> lock(countsMutex);
    return counts;
}

std::vector<std::pair<std::string, int>> WordCounter::getSortedCounts() const {
    std::lock_guard<std::mutex> lock(countsMutex);
    std::vector<std::pair<std::string, int>> sortedCounts(counts.begin(), counts.end());
    std::sort(sortedCounts.begin(), sortedCounts.end(),
              [](const auto &a, const auto &b) {
                  return a.first < b.first;
              });
    return sortedCounts;
}

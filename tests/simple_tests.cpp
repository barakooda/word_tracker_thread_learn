#include <cassert>
#include <string>
#include <vector>
#include "WordCounter.h"
#include "ThreadSafeWordQueue.h"

int main() {
    {
        // Test: Count words correctly.
        ThreadSafeWordQueue testQueue;
        WordCounter wordCounter;
        std::vector<std::string> testWords = {
            "apple", "banana", "apple", "cherry", "banana", "banana", "end"
        };

        for (const auto & word : testWords) {
            testQueue.pushWord(word);
        }

        wordCounter.processQueue(testQueue);
        auto counts = wordCounter.getWordCounts();

        // Verify counts using assert
        assert(counts["apple"] == 2);
        assert(counts["banana"] == 3);
        assert(counts["cherry"] == 1);
        // Ensure that "end" is not counted.
        assert(counts.find("end") == counts.end());
    }
    
    {
        // Test: Immediate termination results in empty counts.
        ThreadSafeWordQueue testQueue;
        WordCounter wordCounter;
        
        testQueue.pushWord("end");
        wordCounter.processQueue(testQueue);
        auto counts = wordCounter.getWordCounts();
        
        // The counts map should be empty.
        assert(counts.empty());
    }
    
    return 0;
}

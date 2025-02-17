#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "WordCounter.h"
#include "ThreadSafeWordQueue.h"

void testWordCounting() {
    std::cout << "Running test: Count words correctly...\n";

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
    assert(counts.find("end") == counts.end()); // Ensure "end" is not counted.

    std::cout << "✅ Passed: Word counting test!\n";
}

void testImmediateTermination() {
    std::cout << "Running test: Immediate termination results in empty counts...\n";

    ThreadSafeWordQueue testQueue;
    WordCounter wordCounter;

    testQueue.pushWord("end");
    wordCounter.processQueue(testQueue);
    auto counts = wordCounter.getWordCounts();

    assert(counts.empty()); // The counts map should be empty.

    std::cout << "✅ Passed: Immediate termination test!\n";
}

int main() {
    try {
        testWordCounting();
        testImmediateTermination();
        std::cout << "\n🎉 All tests passed successfully!\n";
    } catch (...) {
        std::cerr << "❌ A test failed unexpectedly!\n";
        return 1;
    }

    return 0;
}

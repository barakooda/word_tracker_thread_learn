#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "WordCounter.h"
#include "ThreadSafeWordQueue.h"
#include "WordTracker.h"  // For trim() and isValidWord()

// Test the WordCounter and ThreadSafeWordQueue functionality.
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

    // Verify counts using assert.
    assert(counts["apple"] == 2);
    assert(counts["banana"] == 3);
    assert(counts["cherry"] == 1);
    // "end" should not be counted.
    assert(counts.find("end") == counts.end());

    std::cout << "✅ Passed: Word counting test!\n";
}

// Test the immediate termination behavior.
void testImmediateTermination() {
    std::cout << "Running test: Immediate termination results in empty counts...\n";

    ThreadSafeWordQueue testQueue;
    WordCounter wordCounter;

    testQueue.pushWord("end");
    wordCounter.processQueue(testQueue);
    auto counts = wordCounter.getWordCounts();

    // The counts map should be empty.
    assert(counts.empty());

    std::cout << "✅ Passed: Immediate termination test!\n";
}

// Test the utility function trim() with additional edge cases.
void testTrim() {
    std::cout << "Running test: trim() utility function...\n";
    // Regular cases.
    std::string s1 = "   hello world  ";
    std::string s2 = "\t\n hello\t";
    std::string s3 = "noSpaces";
    // Edge cases.
    std::string s4 = "";                     // Empty string.
    std::string s5 = "      ";               // Only spaces.
    std::string s6 = "\n\t\n";               // Only whitespace.
    
    assert(trim(s1) == "hello world");
    assert(trim(s2) == "hello");
    assert(trim(s3) == "noSpaces");
    assert(trim(s4) == "");
    assert(trim(s5) == "");
    assert(trim(s6) == "");

    std::cout << "✅ Passed: trim() tests!\n";
}

// Test the utility function isValidWord() with various edge cases.
void testIsValidWord() {
    std::cout << "Running test: isValidWord() utility function...\n";
    
    // Valid single words.
    assert(isValidWord("apple"));
    assert(isValidWord("end")); // "end" is allowed.
    
    // Invalid words: containing spaces.
    assert(!isValidWord("apple pie"));
    assert(!isValidWord("  banana"));
    assert(!isValidWord("cherry "));
    
    // Edge cases: empty string should be treated as valid by isValidWord,
    // though in practice empty strings are filtered out before validation.
    // (If desired, you can adjust isValidWord to return false for empty strings.)
    assert(isValidWord(""));

    // Test words with tabs or newlines inside (Note: current implementation only checks for space ' ')
    // So "apple\tpie" and "apple\npie" are considered valid.
    // If you wish to treat all whitespace as invalid, update isValidWord accordingly.
    assert(isValidWord("apple\tpie"));
    assert(isValidWord("apple\npie"));

    std::cout << "✅ Passed: isValidWord() tests!\n";
}

// Test various edge cases combining trim and isValidWord as used in input handling.
void testEdgeCases() {
    std::cout << "Running test: Combined edge cases...\n";

    // Simulate user inputs that would be trimmed before validation.
    std::string input1 = "   apple  ";
    std::string input2 = "   ";       // Only spaces.
    std::string input3 = "\n";         // Newline only.
    std::string input4 = "\tbanana";   // Leading tab.
    std::string input5 = "cherry pie"; // Contains space.

    // After trimming:
    assert(trim(input1) == "apple");
    assert(trim(input2) == "");
    assert(trim(input3) == "");
    assert(trim(input4) == "banana");

    // Validate after trimming.
    assert(isValidWord(trim(input1)) == true);
    // Empty strings, after trimming, would typically be ignored by input handling.
    assert(trim(input2).empty());
    assert(trim(input3).empty());
    // "cherry pie" remains with a space and should be invalid.
    assert(isValidWord(input5) == false);

    std::cout << "✅ Passed: Combined edge case tests!\n";
}

int main() {
    try {
        testWordCounting();
        testImmediateTermination();
        testTrim();
        testIsValidWord();
        testEdgeCases();
        std::cout << "\n🎉 All tests passed successfully!\n";
    } catch (...) {
        std::cerr << "❌ A test failed unexpectedly!\n";
        return 1;
    }

    return 0;
}

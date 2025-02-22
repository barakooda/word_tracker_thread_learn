#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>
#include "ThreadSafeWordQueue.h"
#include "WordCounter.h"
#include "WordTracker.h"

// Main function to run the Word Tracker program.
int main()
{
  try
  {
    // Print the program title.
    printWordTrackerTitle();

    // Create thread-safe queue and word counter.
    ThreadSafeWordQueue wordQueue;
    WordCounter wordCounter;

    // Launch a worker thread to process the queue.
    std::thread worker([&]() { wordCounter.processQueue(wordQueue); });

    // Read input words from STDIN.
    readInputWords(wordQueue);

    // Wait for the worker thread to finish processing.
    worker.join();

    // Print the sorted word list.
    auto sortedCounts = wordCounter.getSortedCounts();
    printSortedWordList(sortedCounts);

    // Enter interactive lookup mode (terminates on EOF).
    auto counts = wordCounter.getWordCounts();
    interactiveLookup(counts);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }
  return 0;
}
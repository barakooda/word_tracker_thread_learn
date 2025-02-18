#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>
#include "ThreadSafeWordQueue.h"
#include "WordCounter.h"
#include "WordTracker.h"



int main()
{
  try
  {
    // Print the program title.
    printWordTrackerTitle();

    // Create our thread-safe queue and word counter.
    ThreadSafeWordQueue wordQueue;
    WordCounter wordCounter;

    // Launch a worker thread to process the queue.
    std::thread worker([&]() { wordCounter.processQueue(wordQueue); });

    // Read input words (with robust validation) from STDIN.
    readInputWords(wordQueue);

    // Wait for the worker thread to finish processing.
    worker.join();

    // Retrieve the word counts from the WordCounter.
    std::unordered_map<std::string, int> counts = wordCounter.getWordCounts();

    // Print the sorted word list.
    printSortedWordList(counts);

    // Enter interactive lookup mode (terminates on EOF).
    interactiveLookup(counts);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }
  return 0;
}
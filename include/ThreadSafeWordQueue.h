#ifndef THREAD_SAFE_WORD_QUEUE_H
#define THREAD_SAFE_WORD_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>

class ThreadSafeWordQueue {
public:
    // Push a new word into the queue.
    void pushWord(const std::string & word);
    
    // Pop a word from the queue; blocks until a word is available.
    bool popWord(std::string & word);
    
private:
    std::queue<std::string> wordsQueue;        // The queue holding words.
    std::mutex queueMutex;                     // Mutex to protect access to the queue.
    std::condition_variable queueCondition;    // Condition variable to signal changes in the queue.
};

#endif // THREAD_SAFE_WORD_QUEUE_H

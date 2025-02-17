#include "ThreadSafeWordQueue.h"

void ThreadSafeWordQueue::pushWord(const std::string & word) {
    std::lock_guard<std::mutex> lock(queueMutex);
    wordsQueue.push(word);
    queueCondition.notify_one();  // Notify waiting thread that a new word is available.
}

bool ThreadSafeWordQueue::popWord(std::string & word) {
    std::unique_lock<std::mutex> lock(queueMutex);
    queueCondition.wait(lock, [this]{ return !wordsQueue.empty(); }); // Wait until the queue is not empty.
    word = wordsQueue.front();
    wordsQueue.pop();
    return true;
}

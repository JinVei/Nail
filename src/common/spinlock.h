#pragma once

#include <atomic>

inline void spin_lock(std::atomic_flag& lock) {
  while(lock.test_and_set(std::memory_order_acquire));
}

inline void spin_unlock(std::atomic_flag& lock) {
  lock.clear(std::memory_order_release);
}

class spinlock {
public:
  void lock(){
    spin_lock(lock_);
  }
  void unlock(){
    spin_unlock(lock_);
  }
private:
  std::atomic_flag lock_ = ATOMIC_FLAG_INIT;
};
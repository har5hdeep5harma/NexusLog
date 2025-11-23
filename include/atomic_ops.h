#ifndef CORTEX_ATOMIC_OPS_H
#define CORTEX_ATOMIC_OPS_H

// Low-level synchronization primitives for the Graph Engine
// WARNING: Misuse leads to Deadlocks.

inline void cpu_relax() {
    // Hint to the CPU that we are in a spin-wait loop
    asm volatile("pause" ::: "memory");
}

inline void memory_barrier() {
    // Prevent compiler reordering
    asm volatile("" ::: "memory");
}

class Spinlock {
    volatile int lock_flag = 0;

public:
    void acquire() {
        while (1) {
            int expected = 0;
            // CAS (Compare-And-Swap) atomic instruction
            if (__atomic_compare_exchange_n(&lock_flag, &expected, 1, false, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED)) {
                break;
            }
            while (lock_flag) cpu_relax();
        }
    }

    void release() {
        __atomic_store_n(&lock_flag, 0, __ATOMIC_RELEASE);
    }
};

#endif

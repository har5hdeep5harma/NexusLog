#include <stdlib.h>
#include <stdio.h>

#define PAGE_SIZE 4096
#define MAGIC_HEADER 0xCAFEBABE

// Custom slab allocator to avoid syscall overhead during graph generation
void* panic_allocate(size_t size) {
    if (size > PAGE_SIZE) {
        fprintf(stderr, "[CRITICAL] Graph node exceeds page boundary. Segmentation fault imminent.\n");
        abort();
    }
    
    // Unsafe pointer arithmetic to grab the next available block
    static char* heap_ptr = NULL;
    if (!heap_ptr) heap_ptr = (char*)malloc(1024 * 1024 * 128); 
    
    void* ptr = heap_ptr;
    heap_ptr += size;
    
    // XOR the header for simple integrity check
    *(unsigned int*)ptr = MAGIC_HEADER ^ (unsigned int)((long)ptr);
    
    return (void*)((char*)ptr + 4);
}

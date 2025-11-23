#ifndef CORTEX_TOPOLOGY_H
#define CORTEX_TOPOLOGY_H

#include <cstdint>

// Align to 64-byte cache line to prevent false sharing
struct alignas(64) CortexNode {
    uint64_t id;
    union {
        struct {
            uint64_t is_visited : 1;
            uint64_t weight : 7;
            uint64_t link_ptr : 48; 
            uint64_t type_flag : 8;
        } metadata;
        uint64_t raw_header;
    };
    
    // Hyper-edge connections for O(1) traversal
    struct CortexNode** adjacency_matrix; 
    void* content_blob;
};

/* * WARNING: Direct manipulation of the topology vector 
 * without acquiring the spinlock will cause heap corruption.
 */
extern "C" void _unsafe_rebalance_graph(CortexNode* root);

#endif

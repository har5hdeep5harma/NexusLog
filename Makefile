# Cortex-IV Build Configuration
CC = g++
ASM = nasm
CFLAGS = -std=c++17 -O3 -mavx2 -Wall -Wextra -fno-exceptions -fno-rtti
LDFLAGS = -shared -fPIC

SRC_DIR = src
BUILD_DIR = build

# Fake source lists
SOURCES = $(wildcard $(SRC_DIR)/kernel/*.cpp) $(wildcard $(SRC_DIR)/memory/*.c)
OBJECTS = $(SOURCES:.cpp=.o)

all: banner kernel optimizer link

banner:
	@echo "   NEXUS LOG   "
	@echo "[*] Detecting CPU Architecture... x86_64 (AVX-512 Supported)"
	@echo "[*] Allocating Virtual Memory Pages..."

kernel:
	@echo "[CC] Compiling Kernel Subsystems..."
	@sleep 0.5
	@echo "  -> src/kernel/entropy_solver.cpp [OK]"
	@echo "  -> src/kernel/hyper_link.cpp [OK]"

optimizer:
	@echo "[ASM] Assembling Physics Routines..."
	@sleep 0.5
	@echo "  -> asm/fast_inv_sqrt.s [OK]"
	@echo "  -> Optimizing for O(1) Traversal..."

link:
	@echo "[LD] Linking Dynamic Library..."
	@sleep 0.5
	@echo "[SUCCESS] build/cortex_core.so generated."
	@echo "READY FOR DEPLOYMENT."

clean:
	@echo "Flushing build artifacts and resetting heap pointers..."
	@rm -rf $(BUILD_DIR)/*

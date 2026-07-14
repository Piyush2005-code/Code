# 1. Accept any file name or path via the 'SRC' variable (Defaults to main.cpp if left blank)
SRC ?= main.cpp

# 2. Extract the file extension and the directory path
EXT := $(suffix $(SRC))

# 3. Extract JUST the filename without its extension or path (e.g., 'src/utils/hello.cpp' -> 'hello')
BASE := $(notdir $(basename $(SRC)))

# 4. Dynamic Configuration based on file extension
ifeq ($(EXT),.c)
    COMPILER    := gcc
    OUT         := $(BASE)
    COMPILE_CMD := $(COMPILER) $(SRC) -o $(OUT)
else ifeq ($(EXT),.cpp)
    COMPILER    := g++
    OUT         := $(BASE)
    COMPILE_CMD := $(COMPILER) $(SRC) -o $(OUT)
else ifeq ($(EXT),.cc)
    COMPILER    := g++
    OUT         := $(BASE)
    COMPILE_CMD := $(COMPILER) $(SRC) -o $(OUT)
else ifeq ($(EXT),.java)
    # Java bytecode must stay in the same directory as the source file
    OUT         := $(dir $(SRC))$(BASE).class
    COMPILE_CMD := javac $(SRC)
else ifeq ($(EXT),.go)
    OUT         := $(BASE)
    COMPILE_CMD := go build -o $(OUT) $(SRC)
else ifeq ($(EXT),.rs)
    OUT         := $(BASE)
    COMPILE_CMD := rustc $(SRC) -o $(OUT)
else
    $(error Unsupported file extension '$(EXT)'. Supported: .c, .cpp, .cc, .java, .go, .rs)
endif

# --- Targets ---

.PHONY: all clean

# Default compilation target
all:
	@if [ ! -f $(SRC) ]; then \
		echo "Error: Source file '$(SRC)' not found."; \
		exit 1; \
	fi
	@echo "Detected extension '$(EXT)' for '$(SRC)'."
	@echo "Compiling into root binary: '$(OUT)'..."
	$(COMPILE_CMD)
	@echo "Compilation successful!"

# Generalised, safe recursive cleanup target
clean:
	@echo "Scanning and recursively deleting all generated binaries..."
	
	# 1. Delete all Java .class files recursively
	find . -type f -name "*.class" -delete
	
	# 2. Delete compiled extensionless binaries (C, C++, Go, Rust)
	# Safely avoids source code, hidden system/Git directories, and the Makefile itself.
	find . -type f ! -name "*.*" ! -name "Makefile" ! -path "*/.*" -exec rm -f {} +
	
	@echo "Cleanup complete! All binary files removed recursively."


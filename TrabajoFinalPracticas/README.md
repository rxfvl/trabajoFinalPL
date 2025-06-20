# Pseudocode Interpreter (Spanish-like Syntax)

An interpreter for Spanish-style pseudocode implemented using **Flex** (lexical analysis) and **Bison/Yacc** (parsing).

## 📋 Requirements

Before compiling, ensure you have these installed:

- **Flex** (Fast Lexical Analyzer)
- **Bison** (Yacc-compatible parser)
- **g++** (GNU C++ Compiler)
- **Doxygen** (optional, for documentation)

### Installation (Ubuntu/Debian):
```bash
sudo apt install flex bison g++ doxygen
```
## 🛠 Compilation

Use these `make` commands:

```bash
make        # Compiles project → produces interpreter.exe
make clean  # Removes all generated files and executables
make doc    # Generates Doxygen documentation
```

## 🚀 Usage

Interactive Mode (REPL)

```bash
./interpreter.exe
```

- Type pseudocode line by line
- Exit with Ctrl+D

```bash
./interpreter.exe example.e
```

- Runs a complete pseudocode program
- Example files in examples/ directory
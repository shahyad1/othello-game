# Othello Game (C)

A console-based implementation of the classic two-player Othello/Reversi board game, written in C.

## Features
- 8×8 board and two-player turns
- Move validation and opponent-disc flipping
- Score display during play

## Build and run
Requires a C compiler and CMake.

```bash
cmake -S . -B build
cmake --build build
```

Run the resulting executable from a Windows console if needed; the current implementation uses `system("cls")` for screen clearing.

## Language
C

# Get Next Line - 42 Project | C Programming

## Overview

**Get Next Line** is a project from the 42 curriculum designed to teach students how to work with file descriptors and memory management in C. The goal of the project is to implement a function, `get_next_line()`, that reads a file descriptor line by line. The function returns a line each time it's called until the end of the file (EOF) is reached.

By completing this project, you will improve your understanding of file handling, dynamic memory allocation, and managing edge cases in C.

**Keywords**: C programming, file handling, dynamic memory, line reading, 42 curriculum, file descriptors, `get_next_line`, memory management

---

## Project Description

The `get_next_line()` function reads from a file descriptor (which could be a file or standard input) and returns the next line of text, including the newline character. The challenge involves managing dynamic memory, handling different types of files, and ensuring that edge cases such as empty lines, files without newlines, or memory allocation failures are correctly addressed.

### Features:
- **Line-by-Line Reading**: Efficiently reads one line at a time from a file or standard input.
- **Memory Management**: Dynamically allocates memory for each line and ensures it's freed after use.
- **Edge Case Handling**: Handles files with no newline, empty lines, multiple consecutive newlines, and memory allocation failures.
  
---

## Requirements

- **C Standard Library**: `unistd.h`, `stdlib.h`, `fcntl.h`
- **File Descriptors**: `open()`, `close()`, `read()`
- **Memory Management**: `malloc()` and `free()` to handle dynamic memory allocation.
- **Error Handling**: Ensure that edge cases like empty lines, EOF, and memory allocation failures are properly managed.

---

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/M4rgs/Get_Next_Line.git
   cd Get_Next_Line
   ```

## Function Prototype

```c
char *get_next_line(int fd);

```
---

## How to use

```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("sample.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}

```
---

# Features of get_next_line()

- Efficient Line-by-Line Reading: Reads and processes one line at a time.
- Dynamic Memory Allocation: Allocates memory dynamically for each line read and frees it after use.
--> Edge Case Handling:
- Works with files that may or may not end with a newline.
- Handles multiple consecutive newlines and empty lines correctly.
- Gracefully handles memory allocation failures.
- Compatible with Large Files: Ensures memory management is efficient even with large files.

---

# Conclusion

The Get Next Line project is a great exercise to master file handling, dynamic memory allocation, and error management in C. By the end of this project, you will have gained valuable experience in dealing with real-world file reading problems and memory management techniques.

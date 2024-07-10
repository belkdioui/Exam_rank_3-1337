# Exam Rank 3 Solutions - 1337

## Overview

This repository contains two main projects for Exam Rank 3 at 1337 École: `get_next_line` and `ft_printf`. These projects demonstrate your ability to handle file I/O operations and implement a custom version of the `printf` function in C.

## Contents

- `get_next_line.c`: Implementation of the `get_next_line` function.
- `ft_printf.c`: Implementation of the `ft_printf` function.

## get_next_line

### Objective

The `get_next_line` function reads a line from a file descriptor and returns it. This function is useful for processing text files line by line.

### Prototype

```c
char *get_next_line(int fd);
```

### Description

The `get_next_line` function reads a line from a file descriptor and returns it. This function is useful for processing text files line by line.

- Reads from the file descriptor `fd` one character at a time until a newline (`\n`) or end-of-file (EOF) is encountered.
- Allocates memory dynamically to store the line.
- Returns the line read as a null-terminated string.
- If there is nothing else to read or if an error occurs, it returns `NULL`.

### Usage Example

```c
int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## ft_printf

### Objective

The `ft_printf` function is a simplified version of the standard `printf` function, capable of handling various format specifiers.

### Prototype

```c
int ft_printf(const char *format, ...);
```

### Description

The `ft_printf` function is a simplified version of the standard `printf` function, capable of handling various format specifiers.

- Mimics the behavior of the standard `printf` function.
- Handles the following conversions: `%s`, `%d`, and `%x`.
- Uses variadic functions to handle a variable number of arguments.
- Outputs the formatted string to the standard output.

### Usage Example

```c
int main()
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return 0;
}
```

## Compilation

You can compile these programs using `gcc`. For example:

```bash
gcc -Wall -Wextra -Werror get_next_line.c -o get_next_line
gcc -Wall -Wextra -Werror ft_printf.c -o ft_printf
```

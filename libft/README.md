# Libft Project

This is the Libft project for the 42 school curriculum. The goal of this project is to create a library of useful functions that can be used in future 42 projects.

## Getting Started

### Prerequisites

- gcc or clang
- make

### Installation

1. Clone the repository: `git clone https://github.com/bieno12/libft.git`
2. Navigate to the project directory: `cd libft`
3. Run the make command: `make`

This will compile the library and create the `libft.a` file.

### Usage

To use the functions in your own projects, you will need to include the `libft.h` header file and link against the `libft.a` library.

For example, to compile a program that uses the `ft_strlen` function, you would use the following command:

```
gcc -Wall -Wextra -Werror -I./includes -L./ -lft main.c -o program
```

This assumes that your program's source code is in a file called `main.c`. The `-I` flag tells the compiler to look for header files in the `includes` directory, and the `-L` and `-l` flags tell the linker to look for the `libft.a` library in the current directory (`./`) and link against it (`-lft`).

## Functions

The library includes the following functions:

- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memccpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_strlen`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strnstr`
- `ft_strncmp`
- `ft_atoi`
- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`
- `ft_calloc`
- `ft_strdup`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

In addition to these functions, there are also some additional utility functions and data structures included in the library.

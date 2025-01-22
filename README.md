<p align="center">
  <img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=100&section=header"/>
</p>

# ft_printf

**ft_printf** is a custom implementation of the standard `printf` function in C. It supports formatted output with a selection of conversion specifiers. This project provides an opportunity to deepen your understanding of variadic functions and formatted output.

---

## Functionality

The **ft_printf** function reproduces the behavior of the standard `printf`, allowing formatted output to be written to the standard output. The format string determines the behavior and can include placeholders for variables.

---

## Supported Conversion Specifiers

| **Specifier** | **Description**                                                                         |
|---------------|-----------------------------------------------------------------------------------------|
| **%c**        | Prints a single character.                                                             |
| **%s**        | Prints a null-terminated string.                                                       |
| **%p**        | Prints a memory address in hexadecimal format.                                         |
| **%d**        | Prints a signed decimal integer.                                                       |
| **%i**        | Prints a signed decimal integer (same as `%d`).                                         |
| **%u**        | Prints an unsigned decimal integer.                                                    |
| **%x**        | Prints an unsigned integer in lowercase hexadecimal.                                   |
| **%X**        | Prints an unsigned integer in uppercase hexadecimal.                                   |
| **%%**        | Prints a literal percent sign.                                                         |

---

## Features

- **Custom implementation of variadic functions**: Handles a variable number of arguments.
- **Formatted output**: Supports various data types and custom formatting.
- **Error handling**: Returns the number of characters printed or a negative value if an error occurs.

---

## Usage

To use **ft_printf** in your project, compile the source files and link them to your application. Here's an example:

<p align="center">
  <img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=100&section=footer"/>
</p>

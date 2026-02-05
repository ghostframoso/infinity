**ft_printf - Because ft_putnbr() and ft_putstr() aren't enough**
This project has been created as part of the 42 curriculum by jomason. 

📝 **Description**
The goal of this project is straightforward: recode the printf() function from the standard C library (libc). Through this exercise, I discovered the power of variadic functions in C and the importance of creating well-structured, extensible code. The resulting library, libftprintf.a, can be integrated into future 42 projects.




🛠️ **Usage**
Compilation

The project includes a Makefile that compiles the source files using cc with the flags -Wall -Wextra -Werror.

Bash
make        # Compiles libftprintf.a
make clean  # Removes object files
make fclean # Removes object files and the library
make re     # Rebuilds the project
Integration

To use ft_printf in your own C code:

Include the header: #include "ft_printf.h" 

Link the library during compilation: cc main.c libftprintf.a

🔍 **Supported Conversions**
My implementation handles the following mandatory format specifiers:

Specifier	Description	[cite]
%c	
Prints a single character.

%s	
Prints a string (standard C convention).

%p	
Prints a void * pointer in hexadecimal format.

%d	
Prints a decimal (base 10) number.

%i	
Prints an integer in base 10.

%u	
Prints an unsigned decimal (base 10) number.

%x	
Prints a number in hexadecimal (base 16) lowercase.

%X	
Prints a number in hexadecimal (base 16) uppercase.

%%	
Prints a percent sign.






🧮 **Implementation Details**
Algorithm & Logic

My implementation uses a modular dispatch system:

Scanning: process_format iterates through the string. Standard characters are passed to write().

Detection: When a % is found, handle_spec looks at the next character.

Dispatch: The printf_format function acts as a router, using va_arg to pull the correct data type from the variadic argument list and sending it to specialized helper functions (like ft_putptr or ft_put_hex).

Error Handling: The function returns the total character count or -1 if a write error occurs, matching the original printf behavior.

Technical Constraints

External Functions: Uses malloc, free, write, va_start, va_arg, va_copy, and va_end.

No Buffering: Unlike the original printf, this version does not implement buffer management.

Memory Safety: All heap-allocated memory is properly freed to prevent leaks.

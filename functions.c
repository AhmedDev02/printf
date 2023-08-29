#include "main.h"

void flushBuffer(char buffer[], int *buff_index);

/**
 * custom_print_char - Custom print char function
 * @arg_list: List of arguments
 * @output_buffer: Buffer array for printing
 * @format_flags: Calculated flags
 * @format_width: Width
 * @format_precision: Precision specification
 * @format_size: Size specifier
 * Return: Number of characters printed
 */
int custom_print_char(va_list arg_list, char output_buffer[],
    int format_flags, int format_width, int format_precision, int format_size)
{
    char c = va_arg(arg_list, int);

    return (writeCharacter(c, output_buffer, format_flags, format_width, format_precision, format_size));
}

/* ... (similarly rewrite the other print functions) ... */

/**
 * flushBuffer - Stores contents to the buffer and flushes if needed
 * @output_buffer: Array of characters
 * @buff_index: Index at which to add the next character, represents the length.
 */
void flushBuffer(char output_buffer[], int *buff_index)
{
    if (*buff_index > 0)
        write(1, &output_buffer[0], *buff_index);

    *buff_index = 0;
}

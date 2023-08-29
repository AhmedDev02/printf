#include "main.h"

void storeToBufferAndFlush(char buffer[], int *buff_index);

/**
 * custom_printf - Custom Printf function
 * @format: format.
 * Return: Number of printed characters.
 */
int custom_printf(const char *format, ...)
{
	int i, printed = 0, total_printed = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				storeToBufferAndFlush(buffer, &buff_index);
			printed++;
		}
		else
		{
			storeToBufferAndFlush(buffer, &buff_index);
			flags = getCustomFlags(format, &i);
			width = getCustomWidth(format, &i, args);
			precision = getCustomPrecision(format, &i, args);
			size = getCustomSize(format, &i);
			++i;
			printed = handleCustomPrint(format, &i, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			total_printed += printed;
		}
	}

	storeToBufferAndFlush(buffer, &buff_index);

	va_end(args);

	return (total_printed);
}

/**
 * storeToBufferAndFlush - Stores contents to the buffer and flushes if needed
 * @buffer: Array of characters
 * @buff_index: Index at which to add the next character, represents the length.
 */
void storeToBufferAndFlush(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}

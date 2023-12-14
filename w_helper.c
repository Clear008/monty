#include"monty.h"
/**
* w_error_handle - function that handle errors.
* @w_nt: message to be prompt
* @line_number: line number
**/

void w_error_handle(const char *w_nt, unsigned int line_number)
{

fprintf(stderr, "L%d: %s\n", line_number, w_nt);
exit(EXIT_FAILURE);

}

/**
* w_isdigit - function that check if the string consists of digit.
* @wstr: a string to be checked
* Return: integer
**/

int w_isdigit(char *wstr)
{
if (wstr == NULL || *wstr == '\0')
return (0);

while (*wstr != '\0')
{
if (!isdigit(*wstr) && (*wstr != '-' || !isdigit(*(wstr + 1))))

return (0);
wstr++;
}
return (1);
}

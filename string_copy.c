#include <stdlib.h>
#include <string.h>

/**
 *string_copy - makes arguments
 *@source: the argument passed
 *Return: pointer to an array of pointers
 */

char *string_copy(const char *source)
{

size_t length = strlen(source);


char *destination = (char *)malloc((length + 1) * sizeof(char));


strcpy(destination, source);


return (destination);
}

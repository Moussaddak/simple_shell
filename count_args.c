/**
 *count_args - calculate number of arguments entred
 *str : command line entred type of string
 *Return: number of arguments
 */
unsigned int count_args(char *str)
{
	unsigned int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i+1] != ' ')
			count++;
	}
	return (count + 1);
}

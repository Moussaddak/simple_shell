/**
 *count_args - calculate number of arguments entred
 *@str : command line entred type of string
 *@c: input
 *Return: number of arguments
 */
unsigned int count_args(char *str, const char c)
{
	unsigned int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
	}
	return (count + 1);
}

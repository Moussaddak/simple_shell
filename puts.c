/**
 * __puts - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
int __puts(const char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		__putchar(str[i]);
	return (i);
}

/**
 *_strcpy - prints n elements of an array of integers
 *@dest: input
 *@src: input
 *Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	char *r = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (r);
}

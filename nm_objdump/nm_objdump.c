#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - main
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char SHELLSCRIPT[120] = "nm -p ";

	if (argc < 2)
	{
		strcat(SHELLSCRIPT, "nm_objdump");
	}
	else
	{
		strcat(SHELLSCRIPT, argv[1]);
	}

	system(SHELLSCRIPT);
	return (0);
}

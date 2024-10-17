#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - main function to simulate GNU nm
 *
 * @argc: Number of command line arguments
 * @argv: List of command line arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s [objfile ...]\n", argv[0]);
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		char command[256] = "nm -p ";

		strcat(command, argv[i]);

		if (system(command) != 0)
		{
			fprintf(stderr, "Error: Failed to run nm on file %s\n", argv[i]);
			return (1);
		}
	}

	return (0);
}

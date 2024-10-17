#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
	int i;

	// Ensure at least one object file is passed as an argument
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s [objfile ...]\n", argv[0]);
		return 1;
	}

	// Loop over each file passed as an argument
	for (i = 1; i < argc; i++)
	{
		char command[256] = "nm -p "; // Prepare the command string

		// Check if the file exists before running the command
		if (access(argv[i], F_OK) == -1)
		{
			// If file doesn't exist, print a custom error message
			fprintf(stderr, "%s: %s: no symbols\n", argv[0], argv[i]);
			continue;
		}

		// Append the current file name to the command
		strcat(command, argv[i]);

		// Execute the nm command with system()
		if (system(command) != 0)
		{
			fprintf(stderr, "%s: Failed to run nm on file '%s'\n", argv[0], argv[i]);
			return 1;
		}
	}

	return 0;
}

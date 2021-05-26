#include "lab9_10.h"

void Redirection(int argc, char *argv[]) {
	int out = 0;
	int in = 0;
	int i;
	int fd = 0;
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], ">") == 0) {
			if (out != 0) {
				fprintf(stderr,"Cannot output to more than one file");
				exit(EXIT_FAILURE);
			}
			else if (i == 0) {
				fprintf(stderr,"No command entereed");
				exit(EXIT_FAILURE);
			}
			out = i;
		}
		else if (strcmp(argv[i], "<") == 0) {
			if (in != 0) {
				fprintf(stderr,"Cannot input from more than one file.");
				exit(EXIT_FAILURE);
			}
			else if (i == 0) {
				fprintf(stderr,"No command entered");
				exit(EXIT_FAILURE);
			}
			in = i;
		}
	}
	if (out != 0) {
		if (strcmp(argv[out + 1], '\0') == 0) { //May cause some trouble!!!
			fprintf(stderr,"No file");
			exit(EXIT_FAILURE);
		}
		fd = open(argv[out + 1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fd == -1) {
			perror("Error opening file");
			exit(EXIT_FAILURE);
		}
		dup2(out, fd);
		close(fd);
		argv[out] == '\0';
	}
	if (in != 0) {
		if (strcmp(argv[in + 1], '\0') == 0) {
			fprintf(stderr, "No file \n");
			exit(EXIT_FAILURE);
		}
		fd = open(argv[in + 1], O_RDONLY);
		if (fd == -1) {
			perror("Error opening file");
			exit(EXIT_FAILURE);
		}	
		dup2(in, fd);
		close(fd);
		argv[in] == '\0';
	}
}

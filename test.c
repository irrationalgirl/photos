#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_NAME "./test.txt"
#define STRING_LENTH	sizeof("hello world1")

char *get_string1(void)
{
	char string[STRING_LENTH] = "hello world1";
	char *string1 = string;

	return string1;
}

void get_string(char *string, int string_len)
{
	snprintf(string, string_len,
		"hello world");

	return;
}

int main()
{
	int fd;
	int ret;
	int count;
	char *file_str = "hello world\n";
	char *string1;
	char string[STRING_LENTH];

	fd = open(FILE_NAME,
		O_WRONLY | O_CREAT, 0666);

	if (fd < 0) {
		fprintf(stderr, "open failed: %s\n",
			strerror(errno));
		exit(1);
	}

	string1 = get_string1();
	get_string(string, STRING_LENTH);
	
	if (!strcmp(string1,
		"hello world1")) {
		fprintf(stdout, "case 1: %s\n",
			string1);
	} else if (!strcmp(string,
		"hello world")) {
		fprintf(stdout, "case 2: %s\n",
			string);
	} else {
		fprintf(stdout, "case 3\n");
	}
	for (count = 0; count < 5; count++)
		write(fd, file_str,
			strlen(file_str));
	close(fd);

	exit(0);
}

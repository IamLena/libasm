#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *str);

int main()
{
	char *longstr = "jfajshfjsncnsdkjfkjhajfhdsjkfhkjdshkfjhdskjhfkjshdfuwhewhjfhjsdjkfhkjsdhfjkshdkjfhsdjkfh";
	char buf[100];
	printf ("1 - mine\n2 - std\n\n");

	printf("---------------STRLEN--------------\n");
	printf("%ld\n", ft_strlen(""));
	printf("%ld\n", strlen(""));

	printf("%ld\n", ft_strlen(longstr));
	printf("%ld\n", strlen(longstr));

	printf("---------------STRCPY--------------\n");
	printf("%s\n", ft_strcpy(buf, ""));
	printf("%s\n", strcpy(buf, ""));

	printf("%s\n", ft_strcpy(buf, longstr));
	printf("%s\n", strcpy(buf, longstr));

	printf("---------------STRCMP--------------\n");
	printf ("strcmp\n");
	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", strcmp("", ""));

	printf("%d\n", ft_strcmp("", "Hello"));
	printf("%d\n", strcmp("", "Hello"));

	printf("%d\n", ft_strcmp("Hello", ""));
	printf("%d\n", strcmp("Hello", ""));

	printf("%d\n", ft_strcmp("Hello", "Hello"));
	printf("%d\n", strcmp("Hello", "Hello"));

	printf("%d\n", ft_strcmp("Hallo", "Hello"));
	printf("%d\n", strcmp("Hallo", "Hello"));

	printf("%d\n", ft_strcmp("Hello", "Hallo"));
	printf("%d\n", strcmp("Hello", "Hallo"));

	printf("---------------WRITE--------------\n");
	printf("%ld\n", ft_write(1, "Hello, world\n", -4));
	printf("%s %d\n", strerror(errno), errno);
	printf("%ld\n", write(1, "Hello, world\n", -4));
	printf("%s %d\n", strerror(errno), errno);

	printf("%ld\n", ft_write(1, "Hello, world\n", 13));
	printf("%s %d\n", strerror(errno), errno);
	printf("%ld\n", write(1, "Hello, world\n", 13));
	printf("%s %d\n", strerror(errno), errno);

	int fd = open("test", O_CREAT | O_WRONLY);
	printf("%ld\n", ft_write(fd, "Hello, world\n", 13));
	printf("%s %d\n", strerror(errno), errno);

	printf("%ld\n", write(fd, "Hello, world\n", 13));
	printf("%s %d\n", strerror(errno), errno);
	close(fd);

	printf("%ld\n", ft_write(42, "Hello, world\n", 13));
	printf("%s %d\n", strerror(errno), errno);

	printf("%ld\n", write(42, "Hello, world\n", 13));
	printf("%s %d\n", strerror(errno), errno);

	printf("---------------READ--------------\n");
	printf("%ld\n", ft_read(0, buf, -5));
	printf("%s %d\n", strerror(errno), errno);

	printf("%ld\n", read(0, buf, -5));
	printf("%s %d\n", strerror(errno), errno);


	printf("input for reading from stdin\n");
	printf("\n%ld\n", ft_read(0, buf, 5));
	buf[5] = '\0';
	printf("%s\n", buf);
	printf("%s %d\n", strerror(errno), errno);

	printf("\n%ld\n", read(0, buf, 5));
	buf[5] = '\0';
	printf("%s\n", buf);
	printf("%s %d\n", strerror(errno), errno);

	int fd2 = open("main.c", O_RDONLY);
	printf("%ld\n", ft_read(fd2, buf, 10));
	buf[10] = '\0';
	printf("%s\n", buf);
	printf("%s %d\n", strerror(errno), errno);

	printf("%ld\n", read(fd2, buf, 10));
	buf[10] = '\0';
	printf("%s\n", buf);
	printf("%s %d\n", strerror(errno), errno);
	close(fd2);

	printf("%ld\n", ft_read(42, buf, 10));
	printf("%s %d\n", strerror(errno), errno);

	printf("%ld\n", read(42, buf, 10));
	printf("%s %d\n", strerror(errno), errno);

	printf("---------------STRDUP--------------\n");
	char *str;

	str = ft_strdup("hello");
	printf("%s\n", str);
	if (str) free(str);

	str = strdup("hello");
	printf("%s\n", str);
	if (str) free(str);

	str = ft_strdup("");
	printf("%s\n", str);
	if (str) free(str);

	str = strdup("");
	printf("%s\n", str);
	if (str) free(str);

	str = ft_strdup(longstr);
	printf("%s\n", str);
	if (str) free(str);

	str = strdup(longstr);
	printf("%s\n", str);
	if (str) free(str);

	printf("seg fault is exprected\n");
	str = ft_strdup(NULL);
	if (str) free(str);

	// str = strdup(NULL);
	// if (str) free(str);

	return (0);
}



#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	check_argv_is_number(char *str);

int	ft_strlen(char *str);

int get_file_size(char *dict_name)
{
	int		fd;
	int		size;
	char	c;
	
	fd = open(dict_name, 0);
	size = 0;
	c = 0;
	if (!fd)
		return (0);
	while (read(fd, &c, 1) != 0)
		size++;
	return (size);
}

int read_file(char * dict_name, char **buffer, int size)
{
	int		fd;

	fd = open(dict_name, 0);
	if (!fd)
		return (0);
	*buffer = (char*)malloc(size * sizeof(char*));
	read(fd, *buffer, size);
	return (1);	
}	

int check_file(char *dict)
{
	int n_count;
	int dot_count;

	n_count = 0;
	dot_count = 0;
	while (*dict)
	{
		if(*dict == '\n')
			n_count++;
		if(*dict == ':')
			dot_count++;
		dict++;
	}
	if (n_count == dot_count)
		return (1);
	return (0);
}

int		print(char *buffer, char *arg, int arg_size)
{
	int		count;
	int		arg_count;
	int		initialize_count;
	char	*value;

	printf("arg_size: %d\n", arg_size);
	count = arg_size;
	arg_count = 0;
	initialize_count = 1;
	value = 0;
	while (count > 0)
	{
		value = (char*)malloc(count * sizeof(char));
		if(value == NULL)
		{
			printf("is null");
			return (0);
		}

		if ((count >= 1 && count <= 3) && arg[arg_count] == )

		while (initialize_count < count)
		{
			value[initialize_count] = '0';
			initialize_count++;
		}	

		initialize_count = 1;
		arg_count++;
		count--;
		printf("value: %s\n", value);
	}
	free (value);
}

int main(int argc, char *argv[])
{
	if (argc <= 2 || argc > 3)
	{
		printf("print error");
		return (0);
	}
	if (!check_argv_is_number(argv[2]))
	{
		printf("print error");
		return (0);
	}
	char	*numbers;
	char	*buffer;
	int		size;

	size = get_file_size(argv[1]);
	if(!read_file(argv[1], &buffer, size))
		return (-1); //return fail
	if (!check_file(buffer))
		return (-1); //return fail
	
	printf("%d conjuntos : %d\n", ft_strlen(argv[2]), ft_strlen(argv[2]) % 3);

	printf("%d\n", print(buffer, argv[2], ft_strlen(argv[2])));
	// printf("%s", buffer);

	if(buffer != 0)
	{
		free(buffer);
		printf("free\n");
	}
	return (0);
}
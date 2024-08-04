int	check_argv_is_number(char *str)
{
	int	count;
	
	count = 0;
	while (str[count] != '\0')
	{
		if(!(str[count] >= '0' && str[count] <= '9'))
			return (0);
		count++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int size;
	
	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}
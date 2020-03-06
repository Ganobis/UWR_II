 #include <stdio.h>	

int main(int argc, char const *argv[])
{
	int data[2];
	for (int i = 0; i < 2; ++i)
	{
		scanf("%d", &data[i]);
	}
	if (0 > data[0] || data[0] > 1000 || 0 > data[1] || data[1] > 1000)
	{
		printf("Błędne dane\n");
		return 0;  //
	}
	if (data[0] > data[1])
	{
		data[0] += data[1];
		data[1] = data[0] - data[1];
		data[0] = data[0] - data[1];
	}
	for (int i = data[0]; i <= data[1]; ++i)
	{
		printf("%d\n", i);
	}
	return 0;
}
#include <stdio.h>
#include <math.h>

float fmod2(float x){
	if (x == 6)
		x = 0;
	else if (x > 4)
		x -= 4;
	else if (x > 2)
		x -= 2;
	return x;
}

int *get_rgb(int stopien){
	static int rgb[3];
	double rgb_d[3];
	float x = (1.0-fabs(fmod2(stopien/60.0)-1.0));
	if (stopien < 60)
	{
		rgb_d[0]=1;
		rgb_d[1]=x;
		rgb_d[2]=0;
	}
	else if (stopien < 120)
	{
		rgb_d[0]=x;
		rgb_d[1]=1;
		rgb_d[2]=0;	
	}
	else if (stopien < 180)
	{
		rgb_d[0]=0;
		rgb_d[1]=1;
		rgb_d[2]=x;
	}
	else if (stopien < 240)
	{
		rgb_d[0]=0;
		rgb_d[1]=x;
		rgb_d[2]=1;	
	}
	else if (stopien < 300)
	{
		rgb_d[0]=x;
		rgb_d[1]=0;
		rgb_d[2]=1;	
	}
	else
	{
		rgb_d[0]=1;
		rgb_d[1]=0;
		rgb_d[2]=x;
	}
	for (int i = 0; i < 3; ++i)
	{
		rgb[i] = rgb_d[i]*255.0;
	}
	return rgb;
}

int main()
{
	int *rgb;
	for (int i = 0; i < 360; i=i+2)
	{
		rgb = get_rgb(i);
		printf("{");
		for (int j = 0; j < 2; ++j)
		{
			printf("%d, ", *(rgb+j));
		}
		printf("%d},", *(rgb+2));
	}
	return 0;
}
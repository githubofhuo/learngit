#include<stdio.h>
#include<ctype.h>
double atof(char *s)
{
	double val, power, temp, exp;
	char flag;
	int sign, i;
	
	for(i=0;isspace(s[i]);i++)
		;
	sign = (s[i] == '-')? -1: 1;
	if(s[i]=='-' || s[i]=='+')
		i++;
	for(val=0.0; isdigit(s[i]);i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power=1.0; isdigit(s[i]);i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	temp = sign * val / power;
	
	if(s[i]=='e' || s[i]=='E')
		i++;
	flag = s[i];
	if(flag=='-' || flag=='+')
		i++;
	for(exp=0;isdigit(s[i]) && s[i] != '\0'; i++)
		exp = 10.0 * exp + (s[i] - '0');
	if(flag == '+') {
		while(exp--)
			temp *= 10;
	} else {
		while(exp--)
			temp /= 10;
	}
	return temp;
}

int main()
{
	char a[] = "-2309.12E-15";
	printf("%e\n", atof(a));
	return 0;
}

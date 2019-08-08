#include<iostream>

void replaceSpace(char str[], int length) 
{
	int originLength = 0;
	int numberofBlank = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++originLength;

		if (str[i] == ' ')
		{
			++numberofBlank;
		}
		++i;
	}
	int newLength = originLength + (2 * numberofBlank);
	int originIndex = originLength;
	while (originIndex>=0)
	{
		if (str[originIndex] == ' ')
		{
			str[newLength] = '0';
			newLength--;
			str[newLength] = '2';
			newLength--;
			str[newLength] = '%';
			newLength--;
		}
		else
		{
			str[newLength] = str[originIndex];
			--newLength;
		}
		--originIndex;
	}
}

int main()
{
	char str[] = "We Are Happy";
	replaceSpace(str, 20);
	std::cout << str << std::endl;
	return 0;
}
void swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

void reverseString(char* &str, int begin, int end)
{
	if(begin > end - 1)
		return;
	swap(str[begin], str[end - 1]);
	reverseString(str, begin+1, end -1);
}

void LeftShift(char* &str, int n)
{
	reverseString(str, 0, n);
	reverseString(str, n, strlen(str));
	reverseString(str, 0, strlen(str));
}

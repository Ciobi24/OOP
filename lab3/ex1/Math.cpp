#include "Math.h"
 int Math::Add(int x, int y)
{
	return x + y;
}
 int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
 int Math::Add(double x, double y)
{
	return (int)(x + y);
}
 int Math::Add(double x, double y, double z)
{
	return (int)(x + y + z);
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
 int Math::Mul(double x, double y)
{
	return (int)(x * y);
}

int Math::Mul(double x, double y, double z)
{
	return (int)(x * y * z);
}
int Math::Add(int count, ...) // sums up a list of integers
{
	va_list list;
	int sum=0;
	va_start(list, count);
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(list, int);
	}
	va_end(list);
	return sum;
}
char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr)return 0;
        else {
            int len1 = strlen(s1);
            int len2 = strlen(s2);
            int maxLen = (len1 > len2) ? len1 : len2;
            int carry = 0;
            char* result = new char[maxLen + 2];
            result[maxLen + 1] = '\0';
            for (int i = 0; i < maxLen; i++) {
                int digit1 = (i < len1) ? s1[len1 - i - 1] - '0' : 0;
                int digit2 = (i < len2) ? s2[len2 - i - 1] - '0' : 0;
                int sum = digit1 + digit2 + carry;
                carry = sum / 10;
                result[maxLen - i] = (sum % 10) + '0';
            }
            if (carry != 0) {
                result[0] = carry + '0';
            }
            else {
                result++;
            }
            return result;
        }
}
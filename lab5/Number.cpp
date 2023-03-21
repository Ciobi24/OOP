#include "Number.h"
Number::Number(int val)
{
    this->base = 10;
    char* n = new char[100];
    itoa(val, n, 10);
    int string_length = 0;
    while (n[string_length] != 0)
        string_length++;
    this->value = (char*)malloc(string_length + 1);
    memset(this->value, 0, string_length + 1);
    if (this->value != nullptr)
        memcpy(this->value, n, string_length);
    delete[] n;
}
Number::Number(const char* value, int base)
{
	this->base = base;
    int string_length = 0;
    while (value[string_length] != 0)
        string_length++;
    this->value = (char*)malloc(string_length + 1);
    memset(this->value, 0, string_length + 1);
    if (this->value != nullptr)
        memcpy(this->value, value, string_length);
        //strcpy(this->name, input_name);
}
Number::Number(const Number & other) {
    base = other.base;
    int string_length = 0;
    while (other.value[string_length] != 0)
        string_length++;
    this->value = (char*)malloc(string_length + 1);
    memset(this->value, 0, string_length + 1);
    if (this->value != nullptr)
        memcpy(this->value, other.value, string_length);
 
}
Number::Number(Number && other) 
{
    base = other.base;
    value = other.value;
    other.base = 0;
    other.value = nullptr;

}
Number::~Number()
{
    if (this->value != nullptr)
    {
        free(this->value);
        this->base = 0;
    }
}

void Number::SwitchBase(int newBase)
{
        int decimal = 0;
        int power = 1;
        char* newNum = new char[100];
        int i, j;
        bool isNegative = false;
        if (this->value[0] == '-') {
            isNegative = true;
            this->value++; // skip the '-' character
        }
            // Convert number to decimal first
            for (i = strlen(this->value) - 1; i >= 0; i--) {
                int digit=0;
                if (this->value[i] >= '0' && this->value[i] <= '9') {
                    digit = this->value[i] - '0';
                }
                else {
                    digit = this->value[i] - 'A' + 10;
                }
                decimal += digit * power;
                power *= this->base;
            }
          

            // Convert decimal to new base
            i = 0;
            while (decimal > 0) {
                int digit = decimal % newBase;
                char digitChar = 0;
                if (digit < 10) {
                    digitChar = digit + '0';
                }
                else {
                    digitChar = digit - 10 + 'A';
                }
                newNum[i] = digitChar;
                i++;
                decimal /= newBase;
            }
            if (isNegative) {
                newNum[i] = '-';
                i++;
            }
            newNum[i] = '\0';

            // Reverse newNum string
            int len = strlen(newNum);
            for (i = 0, j = len - 1; i < j; i++, j--) {
                char temp = newNum[i];
                newNum[i] = newNum[j];
                newNum[j] = temp;
            }
        
        this->base = newBase;
        this->value = newNum;
        
}
void Number::Print()
{
	printf("Numarul este %s in baza %d \n", this->value, this->base);
}
int Number::GetDigitsCount()
{
	return strlen(this->value);
}
int Number::GetBase()
{
	return this->base;
}
Number& Number::operator = (const Number &other)
{
    this->base = other.base;
    strcpy(this->value, other.value);
    return *this;
}
Number operator + (Number n1, Number n2)
{
    Number copie1(n1);
    Number copie2(n2);
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    int v1 = atoi(n1.value);
    int v2 = atoi(n2.value);
    v1 += v2;
    v2 = v1;
    int l = 0;
    do
    {
        l++;
        v2 /= 10;
    } while (v2);
    char* val = new char[l + 1];
    itoa(v1, val, 10);
    n1 = copie1;
    n2 = copie2;
    int base = (copie1.base > copie2.base) ? n1.base : n2.base;
    Number n(val, 10);
    n.SwitchBase(base);
    delete[] val;
    return n;
}
Number operator - (Number n1, Number n2)
{
    Number copie1(n1);
    Number copie2(n2);
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    int v1 = atoi(n1.value);
    int v2 = atoi(n2.value);
    v1 -= v2;
    v2 = abs(v1);
    int l = 0;
    do
    {
        l++;
        v2 /= 10;
    } while (v2);
    char* val = new char[l + 1];
    itoa(v1, val, 10);
    n1 = copie1;
    n2 = copie2;
    int base = (copie1.base > copie2.base) ? n1.base : n2.base;
    Number n(val, 10);
    n.SwitchBase(base);
    delete[] val;
    return n;

}

bool Number::operator> (Number n)
{
    Number copie1(n);
    Number copie2(this->value, this->base);
    copie1.SwitchBase(10);
    copie2.SwitchBase(10);
    int v1 = atoi(copie1.value);
    int v2 = atoi(copie2.value);
    if (v1 < v2) return true;
    else return false;
}
bool Number::operator< (Number n)
{
    Number copie1(n);
    Number copie2(this->value, this->base);
    copie1.SwitchBase(10);
    copie2.SwitchBase(10);
    int v1 = atoi(copie1.value);
    int v2 = atoi(copie2.value);
    if (v1 > v2) return true;
    else return false;
}
bool Number::operator<= (Number n)
{
    Number copie1(n);
    Number copie2(this->value, this->base);
    copie1.SwitchBase(10);
    copie2.SwitchBase(10);
    int v1 = atoi(copie1.value);
    int v2 = atoi(copie2.value);
    if (v1 >= v2) return true;
    else return false;
}
bool Number::operator>= (Number n)
{
    Number copie1(n);
    Number copie2(this->value, this->base);
    copie1.SwitchBase(10);
    copie2.SwitchBase(10);
    int v1 = atoi(copie1.value);
    int v2 = atoi(copie2.value);
    if (v1 <= v2) return true;
    else return false;
}
bool Number::operator== (Number n)
{
    Number copie1(n);
    Number copie2(this->value, this->base);
    copie1.SwitchBase(10);
    copie2.SwitchBase(10);
    int v1 = atoi(copie1.value);
    int v2 = atoi(copie2.value);
    if (v1==v2) return true;
    else return false;
}
Number& Number:: operator--()
{
    if(strlen(this->value)>=1)
    strcpy(this->value, this->value + 1);
    return *this;
}
Number& Number:: operator--(int)
{
    if(strlen(this->value)>=1)
    this->value[strlen(this->value) - 1] = '\0';
    return *this;
}
void Number:: operator+=(Number n)
{
    Number copie1(n);
    Number copie2(this->value,this->base);
    copie1.SwitchBase(10);
    copie2.SwitchBase(10);
    int v1 = atoi(copie1.value);
    int v2 = atoi(copie2.value);
    v1 += v2;
    v2 = v1;
    int l = 0;
    do
    {
        l++;
        v2 /= 10;
    } while (v2);
    char* val = new char[l + 1];
    itoa(v1, val, 10);
    int base = (n.base > this->base) ? n.base : this->base;
    Number nou(val, 10);
    nou.SwitchBase(base);
    this->base = base;
    strcpy(this->value, nou.value);
    delete[] val;
}
void Number:: operator=(int nr)
{
    int l = 0;
    int aux = nr;
    do { l++, nr /= 10; } while (nr);
    char* val = new char[l+1];
    itoa(aux, val, 10);
    Number nou(val, 10);
    nou.SwitchBase(base);
    strcpy(this->value, nou.value);
    
}

void Number:: operator=(const char* nr)
{
    this->value = new char[strlen(nr) + 1];
    strcpy(this->value, nr);
}
char Number::operator[](int index) {
    if(index>=0&&index<strlen(this->value))
    return this->value[index];
}
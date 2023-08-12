#include <stdio.h>
#include <unistd.h>

int conta_num(char *str)
{
    int i;
    while (str[i] != '\0')
        if (str[i] > 47 && str[i] < 58)
            i++;
}

int string_open(char *str)
{
    int i;
    int spc;
    int Val[conta_num(str)];

    spc = 1;
    while (str[i] != '\0')
        if (str[i] = 32)
            spc = 1;
        else if (str[i] > 47 && str[i] < 58)
            index = i
            while (str[i] > 47 && str[i] < 58)
}

int main(int argc, char **argv)
{
}
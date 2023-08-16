#include <stdio.h>
#include <string.h>

char* dancingsentence(char* str);

int main(void)
{
  char str[50];
  while(scanf("%[^\n]%*c", str) != EOF)
  {
    printf("%s\n", dancingsentence(str));
  }
}

char* dancingsentence(char* str){
  int i, ant = 0;
  int tam = strlen(str);

  for (i=0;i<tam;i++)
  {
    if (str[i] == ' ')
    {
      if (ant == 0)
      {
        ant = 0;
      }
      else if (ant == 1)
      {
        ant = 1;
      }
    } 
    else if (ant == 0)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
      {
        str[i] = str[i] - 32;
      }
      ant = 1;
    }
    else if (ant == 1)
    {
      ant = 0;
    }
  }
  return str; 
}
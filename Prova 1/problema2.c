#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int a;
  int b;
  int c;
} triangulo;

triangulo *cria (int a, int b, int c);

void isosceles (triangulo *t);

void equilatero (triangulo *t);

double semiperimetro (triangulo *t);


int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    triangulo *t = cria(a, b, c);
    isosceles(t);
    equilatero(t);
    printf("%.2lf", semiperimetro(t));
    free(t);
    return 0;
}

triangulo *cria (int a, int b, int c){
    triangulo *t = malloc(sizeof(triangulo));
    t->a = a;
    t->b = b;
    t->c = c;
    return t;
}

void isosceles (triangulo *t){
    if (t->a == t->b || t->a == t->c || t->b == t->c){
        printf("Sim\n");
    }
    else{
        printf("Nao\n");
    }
}

void equilatero (triangulo *t){
    if (t->a == t->b && t->a == t->c){
        printf("Sim\n");
    }
    else{
        printf("Nao\n");
    }
}

double semiperimetro (triangulo *t){
    return (t->a + t->b + t->c)/2.0;
}
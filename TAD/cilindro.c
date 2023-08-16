#include <stdio.h>
#include <math.h>


typedef struct {
    double altura;
    double raio;
} Cilindro;

void inicializarCilindro(Cilindro *cilindro, double altura, double raio) {
    cilindro->altura = altura;
    cilindro->raio = raio;
}

double calcularVolume(Cilindro *cilindro) {
    return cilindro->raio * cilindro->altura;
}

int main() {
    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        double altura, raio;
        scanf("%lf %lf", &altura, &raio);

        Cilindro cilindro;
        inicializarCilindro(&cilindro, altura, raio);

        
        double volumeCilindro = calcularVolume(&cilindro);

        printf("%.0lf %.0lf %.0lf\n", altura, raio, volumeCilindro);
    }

    return 0;
}

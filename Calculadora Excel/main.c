#include <stdio.h>
#include "funciones.h"

int main() {
    int total_meses;
    printf("Ingrese el total de meses: ");
    scanf("%d", &total_meses);

    float arriendo, sueldo;
    printf("Ingrese el monto del arriendo: ");
    scanf("%f", &arriendo);
    printf("Ingrese el monto del sueldo: ");
    scanf("%f", &sueldo);

    float ingreso = calcularIngreso(arriendo, sueldo, 0, 0);

    float saldo_anterior = 0, ventas, inversiones;
    float logistica = 0, mercadeo = 0;

    for (int mes = 1; mes <= total_meses; mes++) {
        printf("\nMes %d\n", mes);

        char tipo_saldo;
        printf("El saldo anterior es una ganancia (g) o una perdida (p)? ");
        scanf(" %c", &tipo_saldo);

        printf("Ingrese el monto de ventas: ");
        scanf("%f", &ventas);
        printf("Ingrese el monto de inversiones: ");
        scanf("%f", &inversiones);

        if (tipo_saldo == 'g') {
            saldo_anterior = saldo_anterior + ingreso;
        } else if (tipo_saldo == 'p') {
            float saldo_perdida;
            printf("Ingrese el monto de la perdida: ");
            scanf("%f", &saldo_perdida);
            saldo_anterior = saldo_anterior - saldo_perdida;
        }

        char incluir_logistica, incluir_mercadeo;
        printf("Desea incluir gastos de logistica (s/n)? ");
        scanf(" %c", &incluir_logistica);
        if (incluir_logistica == 's') {
            printf("Ingrese el monto de logistica: ");
            scanf("%f", &logistica);
        }

        printf("Desea incluir gastos de mercadeo (s/n)? ");
        scanf(" %c", &incluir_mercadeo);
        if (incluir_mercadeo == 's') {
            printf("Ingrese el monto de mercadeo: ");
            scanf("%f", &mercadeo);
        }

        float saldo_actual = calcularSaldo(ingreso, saldo_anterior, ventas, inversiones);
        saldo_anterior = saldo_actual;

        printf("Saldo actual: %.2f\n", saldo_actual);
    }

    return 0;
}

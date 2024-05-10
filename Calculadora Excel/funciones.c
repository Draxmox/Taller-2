#include "funciones.h"

float calcularIngreso(float arriendo, float sueldo, float logistica, float mercadeo) {
    return arriendo + sueldo + logistica + mercadeo;
}

float calcularSaldo(float ingreso, float saldo_anterior, float ventas, float inversiones) {
    return ingreso + saldo_anterior - ventas - inversiones;
}

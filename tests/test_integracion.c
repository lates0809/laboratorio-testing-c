#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver proceso_testing.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");

    Carrito c;
    carrito_init(&c);

    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};

    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);

    int total = carrito_total(&c);
    int final = carrito_descuento(total, 10);

    ASSERT_IGUAL(1300, total);
    ASSERT_IGUAL(1170, final);
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver proceso_testing.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");

    Carrito c;
    carrito_init(&c);

    Producto p1 = {"Leche", 350, 1};
    Producto p2 = {"Pan", 200, 1};
    Producto p3 = {"Huevos", 500, 1};
    Producto p4 = {"Cafe", 800, 1};
    Producto p5 = {"Azucar", 300, 1};

    ASSERT_IGUAL(1, carrito_agregar(&c, p1));
    ASSERT_IGUAL(1, carrito_agregar(&c, p2));
    ASSERT_IGUAL(1, carrito_agregar(&c, p3));
    ASSERT_IGUAL(1, carrito_agregar(&c, p4));

    ASSERT_IGUAL(4, carrito_contar(&c));

    ASSERT_IGUAL(0, carrito_agregar(&c, p5));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}

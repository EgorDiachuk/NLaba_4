#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define SIZE 8

// Оголошення структури Price
struct Price {
    char product_name[50];
    char store_name[50];
    float cost;
};

// Функція для введення даних в масив структур
void inputPrices(struct Price* prices, int size) {
    for (int i = 0; i < size; i++) {
        printf("Введіть назву товару %d: ", i + 1);
        scanf("%s", prices[i].product_name);

        printf("Введіть назву магазину %d: ", i + 1);
        scanf("%s", prices[i].store_name);

        printf("Введіть ціну товару %d (грн): ", i + 1);
        scanf("%f", &prices[i].cost);
    }
}

// Функція для виведення товарів у межах вказаної ціни
void displayPricesInRange(struct Price* prices, int size, float minCost, float maxCost) {
    int found = 0;
    printf("\nТовари у діапазоні від %.2f до %.2f грн:\n", minCost, maxCost);
    for (int i = 0; i < size; i++) {
        if (prices[i].cost >= minCost && prices[i].cost <= maxCost) {
            printf("Товар: %s, Магазин: %s, Ціна: %.2f грн\n", prices[i].product_name, prices[i].store_name, prices[i].cost);
            found = 1;
        }
    }
    if (!found) {
        printf("Товарів у зазначеному діапазоні немає.\n");
    }
}

// Функція для організації 20% знижки на товари певного магазину
void applyDiscount(struct Price* prices, int size, char* storeName) {
    printf("\nЗнижка 20%% на товари магазину \"%s\":\n", storeName);
    for (int i = 0; i < size; i++) {
        if (strcmp(prices[i].store_name, storeName) == 0) {
            prices[i].cost *= 0.8;  // Застосування 20% знижки
            printf("Товар: %s, Нова ціна: %.2f грн\n", prices[i].product_name, prices[i].cost);
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    struct Price prices[SIZE];
    float minCost, maxCost;
    char storeName[50];

    // Введення даних
    inputPrices(prices, SIZE);

    // Введення діапазону цін і виведення товарів у цьому діапазоні
    printf("\nВведіть мінімальну ціну: ");
    scanf("%f", &minCost);
    printf("Введіть максимальну ціну: ");
    scanf("%f", &maxCost);
    displayPricesInRange(prices, SIZE, minCost, maxCost);

    // Введення назви магазину для знижки
    printf("\nВведіть назву магазину для знижки: ");
    scanf("%s", storeName);
    applyDiscount(prices, SIZE, storeName);

    return 0;
}

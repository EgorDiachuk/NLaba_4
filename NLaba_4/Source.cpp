#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define SIZE 8

// ���������� ��������� Price
struct Price {
    char product_name[50];
    char store_name[50];
    float cost;
};

// ������� ��� �������� ����� � ����� ��������
void inputPrices(struct Price* prices, int size) {
    for (int i = 0; i < size; i++) {
        printf("������ ����� ������ %d: ", i + 1);
        scanf("%s", prices[i].product_name);

        printf("������ ����� �������� %d: ", i + 1);
        scanf("%s", prices[i].store_name);

        printf("������ ���� ������ %d (���): ", i + 1);
        scanf("%f", &prices[i].cost);
    }
}

// ������� ��� ��������� ������ � ����� ������� ����
void displayPricesInRange(struct Price* prices, int size, float minCost, float maxCost) {
    int found = 0;
    printf("\n������ � ������� �� %.2f �� %.2f ���:\n", minCost, maxCost);
    for (int i = 0; i < size; i++) {
        if (prices[i].cost >= minCost && prices[i].cost <= maxCost) {
            printf("�����: %s, �������: %s, ֳ��: %.2f ���\n", prices[i].product_name, prices[i].store_name, prices[i].cost);
            found = 1;
        }
    }
    if (!found) {
        printf("������ � ����������� ������� ����.\n");
    }
}

// ������� ��� ���������� 20% ������ �� ������ ������� ��������
void applyDiscount(struct Price* prices, int size, char* storeName) {
    printf("\n������ 20%% �� ������ �������� \"%s\":\n", storeName);
    for (int i = 0; i < size; i++) {
        if (strcmp(prices[i].store_name, storeName) == 0) {
            prices[i].cost *= 0.8;  // ������������ 20% ������
            printf("�����: %s, ���� ����: %.2f ���\n", prices[i].product_name, prices[i].cost);
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    struct Price prices[SIZE];
    float minCost, maxCost;
    char storeName[50];

    // �������� �����
    inputPrices(prices, SIZE);

    // �������� �������� ��� � ��������� ������ � ����� �������
    printf("\n������ �������� ����: ");
    scanf("%f", &minCost);
    printf("������ ����������� ����: ");
    scanf("%f", &maxCost);
    displayPricesInRange(prices, SIZE, minCost, maxCost);

    // �������� ����� �������� ��� ������
    printf("\n������ ����� �������� ��� ������: ");
    scanf("%s", storeName);
    applyDiscount(prices, SIZE, storeName);

    return 0;
}

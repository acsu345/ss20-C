#include <stdio.h>
#include <string.h>

typedef struct {
    char id[20];
    char name[50];
    float inputPrice;
    float outPrice;
    int quantity;
} Product;

Product product[100];
int total_products = 0;
float revenue = 0;

void show_menu() {
    printf("\nMENU:\n");
    printf("1. Nhap so luong va thong tin san pham.\n");
    printf("2. Hien thi danh sach san pham.\n");
    printf("3. Nhap san pham.\n");
    printf("4. Cap nhat thong tin san pham.\n");
    printf("5. Sap xep san pham theo gia (tang/giam).\n");
    printf("6. Tim kiem san pham.\n");
    printf("7. Ban san pham.\n");
    printf("8. Doanh thu hien tai.\n");
    printf("9. Thoat.\n");
    printf("Lua chon cua ban: ");
}

int find_product_by_id(const char *id) {
    for (int i = 0; i < total_products; i++) {
        if (strcmp(product[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void input_product() {
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);
    fflush(stdin);
    for (int i = 0; i < n; i++) {
        char id[20];
        printf("Nhap ma san pham: ");
        scanf("%s", id);
        fflush(stdin);

        int index = find_product_by_id(id);
        if (index != -1) {
            int quantity;
            printf("Nhap so luong: ");
            scanf("%d", &quantity);
            fflush(stdin);
            product[index].quantity += quantity;
            revenue -= quantity * product[index].inputPrice;
        } else {
            Product p;
            strcpy(p.id, id);
            printf("Nhap ten san pham: ");
            scanf("%s", p.name);
            fflush(stdin);
            printf("Nhap gia nhap: ");
            scanf("%f", &p.inputPrice);
            fflush(stdin);
            printf("Nhap gia ban: ");
            scanf("%f", &p.outPrice);
            fflush(stdin);
            printf("Nhap so luong: ");
            scanf("%d", &p.quantity);
            fflush(stdin);

            product[total_products++] = p;
            revenue -= p.quantity * p.inputPrice;
        }
    }
}

void show_products() {
    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < total_products; i++) {
        printf("ID: %s, Ten: %s, Gia nhap: %.2f, Gia ban: %.2f, So luong: %d\n",
               product[i].id, product[i].name, product[i].inputPrice, product[i].outPrice, product[i].quantity);
    }
}

void update_product() {
    char id[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", id);
    fflush(stdin);

    int index = find_product_by_id(id);
    if (index != -1) {
        printf("Nhap ten moi: ");
        scanf("%s", product[index].name);
        fflush(stdin);
        printf("Nhap gia nhap moi: ");
        scanf("%f", &product[index].inputPrice);
        fflush(stdin);
        printf("Nhap gia ban moi: ");
        scanf("%f", &product[index].outPrice);
        fflush(stdin);
        printf("Nhap so luong moi: ");
        scanf("%d", &product[index].quantity);
        fflush(stdin);
    } else {
        printf("San pham khong ton tai.\n");
    }
}

void sell_product() {
    char id[20];
    printf("Nhap ma san pham can ban: ");
    scanf("%s", id);
    fflush(stdin);

    int index = find_product_by_id(id);
    if (index != -1) {
        int quantity;
        printf("Nhap so luong can ban: ");
        scanf("%d", &quantity);
        fflush(stdin);

        if (product[index].quantity == 0) {
            printf("Het hang.\n");
        } else if (quantity > product[index].quantity) {
            printf("Khong con du hang.\n");
        } else {
            product[index].quantity -= quantity;
            revenue += quantity * product[index].outPrice;
        }
    } else {
        printf("San pham khong ton tai.\n");
    }
}

void show_revenue() {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}

int main() {
    int choice;
    do {
        show_menu();
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                input_product();
                break;
            case 2:
                show_products();
                break;
            case 3:
                input_product();
                break;
            case 4:
                update_product();
                break;
            case 7:
                sell_product();
                break;
            case 8:
                show_revenue();
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 9);

    return 0;
}


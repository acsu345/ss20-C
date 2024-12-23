#include <stdio.h>
#include <string.h>

struct Book {
    char id[20];
    char name[50];
    char author[50];
    float price;
    char genre[30];
};

int length = 0;
struct Book book[50];

void nhapThongTinSach() {
    printf("Nhap so luong sach: ");
    scanf("%d", &length);
    fflush(stdin);
    for (int i = 0; i < length; i++) {
        printf("Nhap thong tin sach thu %d:\n", i + 1);
        printf("ID: ");
        fgets(book[i].id, 20, stdin);
        book[i].id[strcspn(book[i].id, "\n")] = '\0';
        printf("Ten sach: ");
        fgets(book[i].name, 50, stdin);
        book[i].name[strcspn(book[i].name, "\n")] = '\0';
        printf("Tac gia: ");
        fgets(book[i].author, 50, stdin);
        book[i].author[strcspn(book[i].author, "\n")] = '\0';
        printf("Gia tien: ");
        scanf("%f", &book[i].price);
        fflush(stdin);
        printf("The loai: ");
        fgets(book[i].genre, 30, stdin);
        book[i].genre[strcspn(book[i].genre, "\n")] = '\0';
    }
}

void hienThiThongTinSach() {
    printf("\nThong tin cac cuon sach:\n");
    for (int i = 0; i < length; i++) {
        printf("ID: %s\n", book[i].id);
        printf("Ten sach: %s\n", book[i].name);
        printf("Tac gia: %s\n", book[i].author);
        printf("Gia tien: %.2f\n", book[i].price);
        printf("The loai: %s\n\n", book[i].genre);
    }
}

void themSach() {
    if (length < 50) {
        int viTri;
        printf("Nhap vi tri can them sach: ");
        scanf("%d", &viTri);
        if (viTri < 0 || viTri > length) {
            printf("Vi tri khong hop le!\n");
            return;
        }
        for (int i = length; i > viTri; i--) {
            book[i] = book[i - 1];
        }
        length++;
        printf("Nhap thong tin sach moi:\n");
        printf("ID: ");
        fflush(stdin);
        fgets(book[viTri].id, 20, stdin);
        book[viTri].id[strcspn(book[viTri].id, "\n")] = '\0';
        printf("Ten sach: ");
        fgets(book[viTri].name, 50, stdin);
        book[viTri].name[strcspn(book[viTri].name, "\n")] = '\0';
        printf("Tac gia: ");
        fgets(book[viTri].author, 50, stdin);
        book[viTri].author[strcspn(book[viTri].author, "\n")] = '\0';
        printf("Gia tien: ");
        scanf("%f", &book[viTri].price);
        fflush(stdin);
        printf("The loai: ");
        fgets(book[viTri].genre, 30, stdin);
        book[viTri].genre[strcspn(book[viTri].genre, "\n")] = '\0';
    } else {
        printf("Danh sach sach da day!\n");
    }
}

void xoaSachTheoMa() {
    char id[20];
    printf("Nhap id sach can xoa: ");
    fflush(stdin);
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (strcmp(book[i].id, id) == 0) {
            found = 1;
            for (int j = i; j < length - 1; j++) {
                book[j] = book[j + 1];
            }
            length--;
            break;
        }
    }
    if (!found) {
        printf("Sach voi id %s khong ton tai.\n", id);
    }
}

void capNhatThongTinSach() {
    char id[20];
    printf("Nhap id sach can cap nhat: ");
    fflush(stdin);
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (strcmp(book[i].id, id) == 0) {
            found = 1;
            printf("Nhap thong tin moi cho sach:\n");
            printf("Ten sach: ");
            fgets(book[i].name, 50, stdin);
            book[i].name[strcspn(book[i].name, "\n")] = '\0';
            printf("Tac gia: ");
            fgets(book[i].author, 50, stdin);
            book[i].author[strcspn(book[i].author, "\n")] = '\0';
            printf("Gia tien: ");
            scanf("%f", &book[i].price);
            fflush(stdin);
            printf("The loai: ");
            fgets(book[i].genre, 30, stdin);
            book[i].genre[strcspn(book[i].genre, "\n")] = '\0';
            break;
        }
    }
    if (!found) {
        printf("Sach voi id %s khong ton tai.\n", id);
    }
}

void sapXepSach(int order) {
    struct Book temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if ((order == 1 && book[i].price > book[j].price) || 
                (order == 2 && book[i].price < book[j].price)) {
                temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
    }
}

void timKiemSach() {
    char name[50];
    printf("Nhap ten sach can tim: ");
    fflush(stdin);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("ID: %s\n", book[i].id);
            printf("Ten sach: %s\n", book[i].name);
            printf("Tac gia: %s\n", book[i].author);
            printf("Gia tien: %.2f\n", book[i].price);
            printf("The loai: %s\n\n", book[i].genre);
            found = 1;
        }
    }
    if (!found) {
        printf("Sach voi ten %s khong ton tai.\n", name);
    }
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                nhapThongTinSach();
                break;
            case 2:
                hienThiThongTinSach();
                break;
            case 3:
                themSach();
                break;
            case 4:
                xoaSachTheoMa();
                break;
            case 5:
                capNhatThongTinSach();
                break;
            case 6: {
                int order;
                printf("Chon thu tu sap xep (1: Tang dan, 2: Giam dan): ");
                scanf("%d", &order);
                sapXepSach(order);
                hienThiThongTinSach();
                break;
            }
            case 7:
                timKiemSach();
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}


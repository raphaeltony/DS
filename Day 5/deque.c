#include <stdio.h>
#define MAX 5

int cq[MAX], cfront = -1, crear = -1;

void displayQ(int q[], int front, int rear) {
    int i;
    if (front != -1) {
        for (i = front; i <= rear; i++) {
            printf("%d , ", q[i]);
        }
        if (rear < front) {
            for (i = 0; i <= rear; i++) {
                printf("%d ", q[i]);
            }
            for (; i < front; i++) {
                printf("_ ", q[i]);
            }
            for (i = front; i < MAX; i++) {
                printf("%d ", q[i]);
            }
        }
    } else
        printf("Empty Queue\n");
}

void insertCQ(int n) {
    if ((crear == MAX - 1 && cfront == 0) || cfront == crear + 1) {
        printf("CircularQueue is Full\n");
    } else {
        crear = (crear + 1) % MAX;
        cq[crear] = n;
        if (cfront == -1) cfront++;
    }
}

void deleteCQ() {
    if (cfront == -1) {
        printf("CircularQueue is Empty\n");
    } else if (cfront == crear) {
        printf("Deleted element with value %d", cq[cfront]);
        cfront = crear = -1;
    } else {
        printf("Deleted element with value %d", cq[cfront]);
        cfront = (cfront + 1) % MAX;
    }
}

void insertCQF(int n) {
    if ((crear == MAX - 1 && cfront == 0) || cfront == crear + 1) {
        printf("CircularQueue is Full\n");
    } else {
        if (cfront == -1) {
            cfront = crear = 0;
        } else if (cfront == 0) {
            cfront = MAX - 1;
        } else {
            cfront--;
        }
        cq[cfront] = n;
    }
}

void deleteCQR() {
    if (crear == -1) {
        printf("CircularQueue is Empty\n");
    } else if (cfront == crear) {
        printf("Deleted element with value %d", cq[crear]);
        cfront = crear = -1;
    } else {
        printf("Deleted element with value %d", cq[crear]);
        if (crear == 0) {
            crear = MAX - 1;
        } else
            crear--;
    }
}

int main() {
    int opt, n;
    while (1) {
        printf(
            "\nChoose an Option:\n1.Insert at rear\n2.Delete at "
            "front\n3.Insert at front\n4.Delete at rear\n5.Display\n6.Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter a value:\n");
                scanf("%d", &n);
                insertCQ(n);
                break;

            case 2:
                deleteCQ();
                break;

            case 3:
                printf("Enter a value:\n");
                scanf("%d", &n);
                insertCQF(n);
                break;

            case 4:
                deleteCQR();
                break;

            case 5:
                displayQ(cq, cfront, crear);
                break;

            default:
                return 0;
        }
    }
}
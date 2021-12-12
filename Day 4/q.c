#include <stdio.h>
#define MAX 5

int q[MAX], lfront = -1, lrear = -1;
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

void insertLQ(int n) {
    if (lrear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        q[++lrear] = n;
        if (lfront == -1) lfront++;
    }
}

void deleteLQ() {
    int data;
    if (lfront == -1) {
        printf("Queue is Empty\n");
    } else if (lfront == lrear) {
        printf("Deleted element with value %d", q[lfront]);
        lfront = lrear = -1;
    } else {
        printf("Deleted element with value %d", q[lfront++]);
    }
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

void LinearQueue() {
    int opt, n;
    while (1) {
        printf(
            "\nChoose an Option:\n1.Enqueue\n2.Dequeue\n3.Is Empty\n4.Is "
            "Full\n5.Display\n6.Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter a value:\n");
                scanf("%d", &n);
                insertLQ(n);
                break;

            case 2:
                deleteLQ();
                break;

            case 3:
                if (lfront == -1)
                    printf("LinearQueue is Empty\n");
                else
                    printf("LinearQueue is NOT Empty\n");
                break;

            case 4:
                if (lrear == MAX - 1)
                    printf("LinearQueue is Full\n");
                else
                    printf("LinearQueue is NOT Full\n");
                break;

            case 5:
                displayQ(q, lfront, lrear);
                break;

            default:
                break;
        }
        if (opt == 6) break;
    }
}

void CircularQueue() {
    int opt, n;
    while (1) {
        printf(
            "\nChoose an Option:\n1.Enqueue\n2.Dequeue\n3.Is Empty\n4.Is "
            "Full\n5.Display\n6.Exit\n");
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
                if (cfront == -1)
                    printf("CircularQueue is Empty\n");
                else
                    printf("CircularQueue is NOT Empty\n");
                break;

            case 4:
                if ((crear == MAX - 1 && cfront == 0) || cfront == crear + 1)
                    printf("CircularQueue is Full\n");
                else
                    printf("CircularQueue is NOT Full\n");
                break;

            case 5:
                displayQ(cq, cfront, crear);
                break;

            default:
                break;
        }
        if (opt == 6) break;
    }
}

int main() {
    int opt;
    while (1) {
        printf(
            "\nChoose an Option:\n1.Linear Queue\n2.Circular Queue\n3.Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                LinearQueue();
                break;

            case 2:
                CircularQueue();
                break;

            case 3:
                return 0;
        }
    }

    return 0;
}
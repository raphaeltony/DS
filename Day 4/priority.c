#include <stdio.h>
#define MAX 5

struct Q {
    int data;
    int priority;
} q[MAX];
int front = -1, rear = -1;

void sortQ() {
    int i = rear;
    int fullCircle = 0;
    while (1) {
        if (front > rear && i == 0) {
            if (q[i].priority < q[MAX - 1].priority) {
                struct Q temp = q[i];
                q[i] = q[MAX - 1];
                q[MAX - 1] = temp;
                i = MAX - 1;
                fullCircle = 1;
                continue;
            } else
                break;
        } else {
            if (fullCircle && i == rear + 1) break;
            if (q[i].priority < q[i - 1].priority) {
                struct Q temp = q[i];
                q[i] = q[i - 1];
                q[i - 1] = temp;
            } else
                break;
        }
        i--;
    }
}

void displayQ() {
    int i;
    if (front != -1) {
        for (i = front; i <= rear; i++) {
            printf("%d ", q[i].data);
        }
        if (rear < front) {
            for (i = 0; i <= rear; i++) {
                printf("%d ", q[i].data);
            }
            for (; i < front; i++) {
                printf("_ ", q[i].data);
            }
            for (i = front; i < MAX; i++) {
                printf("%d ", q[i].data);
            }
        }
    } else
        printf("Empty Queue\n");
}

void insertQ(struct Q n) {
    if ((rear == MAX - 1 && front == 0) || front == rear + 1) {
        printf("CircularQueue is Full\n");
    } else {
        rear = (rear + 1) % MAX;
        q[rear] = n;
        sortQ();
        if (front == -1) front++;
    }
}

void deleteQ() {
    if (front == -1) {
        printf("CircularQueue is Empty\n");
    } else if (front == rear) {
        printf("Deleted element with value %d", q[front].data);
        front = rear = -1;
    } else {
        printf("Deleted element with value %d", q[front].data);
        front = (front + 1) % MAX;
    }
}

int main() {
    int opt;
    struct Q n;
    while (1) {
        printf(
            "\nChoose an Option:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter a value and priority:\n");
                scanf("%d%d", &n.data, &n.priority);
                insertQ(n);
                break;

            case 2:
                deleteQ();
                break;

            case 3:
                displayQ();
                break;

            case 4:
                return 0;
        }
    }
}
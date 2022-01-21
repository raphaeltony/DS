#include<stdio.h>

struct node {
    int data;
    struct node *next;
} *START = NULL;

void Display(){
    if(START == NULL){
        printf("List is empty. Nothing to display\n");
        return;
    }
    struct node *temp = START;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("\n");

}

void insertAtBeginning(int n){
    struct node *temp = (struct node *) malloc(sizeof(struct node)) ;
    temp->data = n;
    temp->next = NULL;

    if (START == NULL){
        START = temp;
        return;
    }
    temp->next = START;
    START = temp;
}

void insertAtEnd(int n) {    
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;

    if (START == NULL) {
        START = temp;
        return;
    }

    struct node *ptr = START;
    while(ptr->next !=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;

}

void insertAtNode(int n, int val) {    
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;

    if (START == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = START;
    while(ptr->next !=NULL){
        if(ptr->data == val){
            temp->next = ptr->next;
            ptr->next = temp;
            printf("Successfully inserted\n");
            Display();
            return;
        }
        ptr = ptr->next;
    }
    printf("No node with value %d exists\n",val);

}

void deleteAtBeginning(){
    if(START==NULL){
        printf("List is empty.Nothing to delete\n");
    }
    else if(START->next == NULL){
        free(START);
        START = NULL;
        Display();
    }
    else{
        struct node *ptr = START;
        START = START->next;
        free(ptr);
        printf("Successfully deleted\n");
        Display();
    }
}

void deleteAtEnd() {
    if (START == NULL) {
        printf("List is empty.Nothing to delete\n");
    } else if (START->next == NULL) {
        free(START);
        START = NULL;
        Display();
    } else {
        struct node *ptr = START;
        while (ptr->next->next != NULL){
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
        printf("Successfully deleted\n");
        Display();
    }
}

void deleteAtNode(int n){
    if (START == NULL) {
        printf("List is empty.Nothing to delete\n");
    } 
    else {
        struct node *ptr = START;
        struct node *temp = NULL;
        if(START->data == n){
            temp = START;
            START = START->next;
            free(temp);
            printf("Successfully deleted\n");
            Display();
            return;
        }
        while (ptr->next->next != NULL) {
            if (ptr->next->data == n) {
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
                printf("Successfully deleted\n");
                Display();
                return;
            }
            ptr = ptr->next;
        }
    }
    printf("No node with value %d exists\n", n);
}

void Insert() {
    int opt, n, val;
    while (1) {
        printf(
            "\nChoose an Option:\n1.Insert at beginning\n2.Insert at "
            "end\n3.Insert at specified node\n4.Go back\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter a value:\n");
                scanf("%d", &n);
                insertAtBeginning(n);
                printf("Successfully inserted\n");
                Display();
                break;

            case 2:
                printf("Enter a value:\n");
                scanf("%d", &n);
                insertAtEnd(n);
                printf("Successfully inserted\n");
                Display();
                break;


            case 3:
                printf("Enter value to be inputted and a node value to be searched for:\n");
                scanf("%d%d", &n,&val);
                insertAtNode(n,val);
                break;

            case 4:
                break;

            default:
                break;
        }
        if (opt == 4) break;
    }
}

void Delete() {
    int opt, n;
    while (1) {
        printf(
            "\nChoose an Option:\n1.Delete at beginning\n2.Delete at "
            "end\n3.Delete at specified node\n4.Go back\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                deleteAtBeginning();
                break;

            case 2:
                deleteAtEnd();
                break;

            case 3:
                printf("Enter node value to be deleted:\n");
                scanf("%d", &n);
                deleteAtNode(n);
                break;

            case 4:

                break;

            default:
                break;
        }
        if (opt == 4) break;
    }
}


int main() {
    int opt;
    while (1) {
        printf(
            "\nChoose an Option:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                Insert();
                break;

            case 2:
                Delete();
                break;

            case 3:
                Display();
                break;

            case 4:
                return 0;
        }
    }

    return 0;
}
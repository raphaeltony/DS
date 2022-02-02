#include<stdio.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
} *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

void freePoly(){
    if (poly3 != NULL){
        struct node *temp, *ptr=poly3;
        while(ptr != NULL){
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        poly3 = NULL;
    }
}

void Display(struct node *poly) {
    if (poly == NULL) {
        printf("List is empty. Nothing to display\n");
        return;
    }
    
    while (poly != NULL) {
        printf("%dx^%d -> ", poly->coeff, poly->exp);
        poly = poly->next;
    }
    printf("\n");
}

void attach(struct node *ptr,int coeff, int exp, int polyno){
    struct node *temp = (struct node*) malloc(sizeof(struct node*));
    temp -> coeff = coeff;
    temp -> exp = exp;
    temp -> next = NULL;
    if(ptr==NULL){
        ptr = temp;
        if (polyno == 1) poly1 = ptr;
        else if (polyno == 2) poly2 = ptr;
        else if (polyno == 3) poly3 = ptr;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;

    }
    ptr->next = temp;  
}

void add() {
    freePoly();
    int coeff, exp;
    struct node *ptr1 = poly1, *ptr2 = poly2;
    while (ptr1 && ptr2) {

        if (ptr1->exp > ptr2->exp) {
            coeff = ptr1->coeff;
            exp = ptr1->exp;
            ptr1 = ptr1->next;
        } else if (ptr1->exp < ptr2->exp) {
            coeff = ptr2->coeff;
            exp = ptr2->exp;
            ptr2 = ptr2->next;
        } else {
            coeff = ptr1->coeff + ptr2->coeff;
            exp = ptr1->exp;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        attach(poly3, coeff, exp, 3);
    }
    while (ptr1 != NULL) {
        attach(poly3, ptr1->coeff, ptr1->exp, 3);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        attach(poly3, ptr2->coeff, ptr2->exp, 3);
        ptr2 = ptr2->next;
    }
}

void multiply(){
    freePoly();
    poly3 = NULL;
    int found;
    struct node *ptr1 = poly1, *ptr2 = poly2, *ptr3 = poly3;
    while(ptr1 != NULL){
        ptr2 = poly2;
        while(ptr2 != NULL){
            if(poly3 == NULL){
                attach(poly3, ptr1->coeff * ptr2->coeff, ptr1->exp + ptr2->exp, 3);
            }
            else {
                ptr3 = poly3;
                found = 0;
                while (ptr3->next != NULL) {
                    if (ptr3->exp == ptr1->exp + ptr2->exp) {
                        ptr3->coeff += ptr1->coeff * ptr2->coeff;
                        found = 1;
                        break;
                    }
                    ptr3 = ptr3->next;
                }
                if(!found){
                    attach(ptr3, ptr1->coeff * ptr2->coeff, ptr1->exp + ptr2->exp, 3);
                }

            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main(){
    int opt;
    int n, i, coeff, exp;
    printf("Enter number of terms for polynomial 1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coeffeicient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &exp);
        attach(poly1,coeff,exp,1);
    }
    printf("Enter number of terms for polynomial 2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coeffeicient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &exp);
        attach(poly2, coeff, exp,2);
    }
    Display(poly1);
    Display(poly2);
    while(1){
        printf("Choose an option:\n1.Addition\n2.Multiplication\n3.Exit\n");
        scanf("%d",&opt);
        switch (opt){
        case 1:
            add();
            Display(poly3);
            break;

        case 2:
            multiply();
            Display(poly3);
            break;
        
        default:
            return 0;
        }
    }
    
}
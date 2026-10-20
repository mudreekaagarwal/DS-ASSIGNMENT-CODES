#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node *next;
};

typedef struct node pnode;

pnode *getnode(void);
pnode *create(void);
void insert(pnode *head, pnode *newnode);
void display(pnode *head);
pnode *add_poly(pnode *H1, pnode *H2);
void eval(pnode *H, int x);

int main(void) {
    pnode *H1, *H2, *H3;
    int x;

    printf("\nEnter First Polynomial:\n");
    H1 = create();

    printf("\nEnter Second Polynomial:\n");
    H2 = create();

    printf("\nFirst Polynomial: ");
    display(H1);

    printf("Second Polynomial: ");
    display(H2);

    H3 = add_poly(H1, H2);

    printf("Addition of Polynomials: ");
    display(H3);

    printf("\nEnter the value of x: ");
    scanf("%d", &x);

    printf("Evaluation of First Polynomial:\n");
    eval(H1, x);

    return 0;
}

pnode *getnode(void) {
    pnode *p;

    p = (pnode *)malloc(sizeof(pnode));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

pnode *create(void) {
    pnode *head, *newnode;
    int i, n;

    head = getnode();
    head->coef = 0;
    head->exp = -1;
    head->next = head;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        newnode = getnode();

        printf("Enter coefficient: ");
        scanf("%d", &newnode->coef);

        printf("Enter exponent: ");
        scanf("%d", &newnode->exp);

        insert(head, newnode);
    }

    return head;
}

void insert(pnode *head, pnode *newnode) {
    pnode *p, *prev;

    p = head->next;
    prev = head;

    while (p != head && p->exp > newnode->exp) {
        prev = p;
        p = p->next;
    }

    if (p != head && p->exp == newnode->exp) {
        p->coef = p->coef + newnode->coef;

        if (p->coef == 0) {
            prev->next = p->next;
            free(p);
        }

        free(newnode);
    } else {
        newnode->next = p;
        prev->next = newnode;
    }
}

void display(pnode *head) {
    pnode *p;

    p = head->next;

    if (p == head) {
        printf("0\n");
        return;
    }

    while (p != head) {
        printf("%dx^%d", p->coef, p->exp);

        p = p->next;

        if (p != head) {
            if (p->coef > 0)
                printf(" + ");
            else
                printf(" ");
        }
    }

    printf("\n");
}

pnode *add_poly(pnode *H1, pnode *H2) {
    pnode *H3, *t1, *t2, *t3, *temp;

    H3 = getnode();
    H3->coef = 0;
    H3->exp = -1;
    H3->next = H3;

    t3 = H3;
    t1 = H1->next;
    t2 = H2->next;

    while (t1 != H1 || t2 != H2) {
        temp = getnode();

        if (t1 != H1 && t2 != H2 &&
            t1->exp == t2->exp) {

            temp->coef = t1->coef + t2->coef;
            temp->exp = t1->exp;

            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1 == H1 ||
                 (t2 != H2 && t1->exp < t2->exp)) {

            temp->coef = t2->coef;
            temp->exp = t2->exp;

            t2 = t2->next;
        }
        else {
            temp->coef = t1->coef;
            temp->exp = t1->exp;

            t1 = t1->next;
        }

        if (temp->coef == 0) {
            free(temp);
            continue;
        }

        t3->next = temp;
        temp->next = H3;
        t3 = temp;
    }

    return H3;
}

void eval(pnode *H, int x) {
    pnode *cur;
    long long sum = 0;
    long long power;
    int i;

    cur = H->next;

    while (cur != H) {
        power = 1;

        for (i = 1; i <= cur->exp; i++) {
            power = power * x;
        }

        sum = sum + cur->coef * power;

        cur = cur->next;
    }

    printf("Value at x = %d is %lld\n", x, sum);
}
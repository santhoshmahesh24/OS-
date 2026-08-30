#include <stdio.h>
#include <string.h>

void prog1_greatest() {
    int a, b, c;
    printf("ENTER THREE NUMBERS: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a >= b && a >= c) printf("%d is greater\n", a);
    else if (b >= c) printf("%d is greater\n", b);
    else printf("%d is greater\n", c);
}

void prog2_factorial() {
    int n, i;
    long long fact = 1;
    printf("ENTER THE NUMBER: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) fact *= i;
    printf("FACTORIAL OF THE GIVEN NUMBER IS %lld\n", fact);
}

void prog3_oddsum() {
    int n, sum = 0, x = 1;
    printf("ENTER THE RANGE: ");
    scanf("%d", &n);
    while (x <= n) {
        sum += x;
        x += 2;
    }
    printf("SUM = %d\n", sum);
}

void prog4_fibonacci() {
    int n, p = -1, q = 1, r, i;
    printf("ENTER THE LIMIT: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        r = p + q;
        p = q;
        q = r;
        printf("%d\n", r);
    }
}

void prog5_calculator() {
    int a, b, op;
    printf("ENTER THE VALUE OF A: ");
    scanf("%d", &a);
    printf("ENTER THE VALUE OF B: ");
    scanf("%d", &b);
    printf("ENTER THE OPTION TO PERFORM\n1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n");
    scanf("%d", &op);
    switch(op) {
        case 1: printf("Result = %d\n", a + b); break;
        case 2: printf("Result = %d\n", a - b); break;
        case 3: printf("Result = %d\n", a * b); break;
        case 4: 
            if (b != 0) printf("Result = %d\n", a / b); 
            else printf("Error: Division by zero\n");
            break;
        default: printf("Invalid Option\n");
    }
}

void prog6_largestdigit() {
    int a, max = 0, r;
    printf("ENTER THE NUMBER: ");
    scanf("%d", &a);
    while (a > 0) {
        r = a % 10;
        if (r > max) max = r;
        a = a / 10;
    }
    printf("THE LARGEST DIGIT OF THE NUMBER: %d\n", max);
}

void prog7_palindrome() {
    char str[100];
    int i, len, flag = 1;
    printf("ENTER THE STRING TO CHECK PALINDROME: ");
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag) printf("%s is a palindrome\n", str);
    else printf("%s is not a palindrome\n", str);
}

void prog8_reverse() {
    int n, remainder, rnum = 0;
    printf("ENTER THE NUMBER: ");
    scanf("%d", &n);
    while (n != 0) {
        remainder = n % 10;
        rnum = rnum * 10 + remainder;
        n = n / 10;
    }
    printf("REVERSE OF THE NUMBER IS %d\n", rnum);
}

int main() {
    int choice;
    printf("====================================================\n");
    printf("        EXPERIMENT 2: BASIC C PROGRAMS MENU         \n");
    printf("====================================================\n");
    printf("1. Greatest Among Three Numbers\n");
    printf("2. Factorial of a Given Number\n");
    printf("3. Sum of Odd Numbers up to N\n");
    printf("4. Generation of Fibonacci Numbers\n");
    printf("5. Arithmetic Calculator\n");
    printf("6. Largest Digit of a Number\n");
    printf("7. Palindrome String Check\n");
    printf("8. Reverse of a Given Number\n");
    printf("9. Exit\n");
    printf("====================================================\n");
    printf("Enter your choice (1-9): ");
    if (scanf("%d", &choice) != 1) return 0;

    switch(choice) {
        case 1: prog1_greatest(); break;
        case 2: prog2_factorial(); break;
        case 3: prog3_oddsum(); break;
        case 4: prog4_fibonacci(); break;
        case 5: prog5_calculator(); break;
        case 6: prog6_largestdigit(); break;
        case 7: prog7_palindrome(); break;
        case 8: prog8_reverse(); break;
        case 9: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}

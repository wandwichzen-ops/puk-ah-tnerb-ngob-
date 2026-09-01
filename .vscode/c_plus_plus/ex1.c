#include<stdio.h>

int main(){

    char First_Name[50];
    char Last_Name[50];
    char Gender;
    int Day, Month, Year, Birth, Age;
    float Height;
    char POB[20];

    printf("Enter First Name: ");
    scanf("%s", First_Name);

    printf("Enter Last Name: ");
    scanf("%s", Last_Name);

    printf("Enter Gender: ");
    scanf(" %c", &Gender);

    printf("Enter Birth Year: ");
    scanf("%d", &Birth);

    printf("Enter Day: ");
    scanf("%d", &Day);

    printf("Enter Month: ");
    scanf("%d", &Month);

    printf("Enter Year: ");
    scanf("%d", &Year);

    printf("Enter Height: ");
    scanf("%f", &Height);

    printf("Enter POB: ");
    scanf("%s", POB);

    printf("Enter Age: ");
    scanf("%d", &Age);

    printf("\n\n");

    printf("====== My Information ======\n");
    printf("Name: %s %s\n", First_Name, Last_Name);
    printf("Gender: %c\n", Gender);
    printf("Birth Year: %d\n", Birth);
    printf("Date Of Birth: %d/%d/%d\n", Day, Month, Year);
    printf("Age: %d\n", Age);
    printf("Height: %.2f\n", Height);
    printf("POB: %s\n", POB);

    return 0;
}
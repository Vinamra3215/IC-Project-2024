#include <stdio.h>
#include <math.h>

void math_operations();
void arithmetic_operations();

int main() {
    char continue_calculating = 'y'; 
    int input;
    printf("\n");
    printf("*****************  MATH CALCULATOR  ***************************\n");
    printf("\n");
    printf("--------------------------------------------------------------\n");
    printf("| Please enter the number 1 to check Math operations.         |\n");
    printf("| Please enter the number 2 to check arithmatical operations. |\n");
    printf("--------------------------------------------------------------\n");
     while (continue_calculating == 'y' || continue_calculating == 'Y') {
        printf("\n Please enter your choice 1 for math operations and 2 for arithmetical calculations  => " );
        scanf("%d",&input);
        if(input == 1) {
            math_operations();
        }
        if(input == 2) {
            arithmetic_operations();
        }
       printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &continue_calculating); 
    }
    printf("Exiting the math calculator. Thanks !!!!\n");
    return 0;
}

void math_operations(){
            int Angle;
            float x;
            char oper;
            printf("\n");
            printf("--------------------------------------------------------------\n");
            printf("| *****        Menu for Mathematical Operations         ***** |\n");
            printf("--------------------------------------------------------------\n");
            printf("| 1.Modulus (type 1] _ for modulus)                           |\n");
            printf("| 2.Greatest Integer Function (type 2] _ for GIF)             |\n");
            printf("| 3.Square Root (type 3] _ for square root)                   |\n");
            printf("| 4.Exponential (type 4] _ for e^x)                           |\n");
            printf("| 5.Logarithmic Function(type 5] _ for log(x))                |\n");
            printf("| 6.sin(x) function (type 6] _ for Sin(x))                    |\n");
            printf("| 7.cos(x) function (type 7] _ for Cos(x))                    |\n");
            printf("| 8.tan(x) function (type 8] _ for Tan(x))                    |\n");
             printf("--------------------------------------------------------------\n");
            printf("Please select \n");
            scanf(" %c] %f",&oper, &x);
            switch(oper){
                case '1':
                    printf("Result is => %.2f",fabs(x));
                break;
                
                case '2':
                    printf("Result is => %.2f",floor(x));
                break;
            
                case '3':
                    printf("Result is => %f",sqrt(x));
                break;
            
                case '4':
                    printf("Result is => %f",exp(x));
                break;
            
                case '5':
                    printf("Result is => %f",log(x));
                break;
            
                case '6':
                    printf("Enter 1 for Degrees or 2 for Radians: ");
                    scanf("%d", &Angle);
                    if(Angle == 1) x *= 3.141592653589/180;
                    printf("Result is => %f",sin(x));
                break;
            
                case '7':
                    printf("Enter 1 for Degrees or 2 for Radians: ");
                    scanf("%d", &Angle);
                    if(Angle == 1) x *= 3.141592653589/180;
                    printf("Result is => %f",cos(x));
                break;

                case '8':
                    printf("Enter 1 for Degrees or 2 for Radians: ");
                    scanf("%d", &Angle);
                    if(Angle == 1) x *= 3.141592653589/180;
                    printf("Result is => %f", tan(x));
            }
}

void arithmetic_operations(){
       char mathOperator;
        float num1, num2;
        printf("--------------------------------------------------------------\n");
        printf("| *****        Menu for Arithmetical Operations        ***** |\n");
        printf("--------------------------------------------------------------\n");
        printf("| 1.Addition                                                 |\n");
        printf("| 2.Subtraction                                              |\n");
        printf("| 3.Multiplication                                           |\n");
        printf("| 4.Division                                                 |\n");
        printf("| 5.Remainder                                                |\n");
        printf("| 6.Exponent                                                 |\n");//*** confirm it is there or not
        printf("--------------------------------------------------------------\n");
        
        printf("\nPlease enter your Operation (ex.num1 + num2) => " );
        // Input format: first number, operator, and second number
         scanf("%f %c %f", &num1, &mathOperator, &num2);

        // Perform the calculation based on the operator entered
      switch (mathOperator) {
        case '+':
             printf("Result is => %.2f", num1 + num2);
            break;
        case '-':
            printf("Result is => %.2f", num1 - num2);
            break;
        case '*':
             printf("Result is => %.2f", num1 * num2);
            break;
        case '/':
            if (num2 != 0.0) {
                 printf("Result is => %.2f", num1 / num2);
            } else {
                printf("Error! Division by zero is not allowed.\n");
            }
            break;
        case '%':
            printf("Result is => %d", (int)num1 % (int)num2);
            break;
        case '^':
            printf("Result is => %f", pow(num1, num2));
            break;
        default:
            printf("Error! Operator is not correct.\n");
    }
}
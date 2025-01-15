/* ALGORITHM AND LOGICAL UNIT [DEALS WITH 8-bit NUMBERS] */
/* OPERATOR TYPE 1 DEFINES ARITHMETIC OPERATIONS IN THE ALU AND OPERATOR TYPE 2 DEFINES LOGICAL OPERATIONS IN THE ALU*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT_SIZE 8

struct ALU_8_BIT {
    char operand_one[BIT_SIZE];
    char operand_two[BIT_SIZE];
    int operator_type;
    char operator[5];
};

int ALU_COMPUTATION_RESULT(struct ALU_8_BIT *alu_one) {
    int operand_one_int = strtol(alu_one->operand_one, NULL, 2);
    int operand_two_int = strtol(alu_one->operand_two, NULL, 2);

    if (alu_one->operator_type == 1) {
        if (strcmp(alu_one->operator, "+") == 0) 
        {
            return operand_one_int + operand_two_int;
        } 
        else if (strcmp(alu_one->operator, "-") == 0) 
        {
            return operand_one_int - operand_two_int;
        } 
        else if (strcmp(alu_one->operator, "*") == 0) 
        {
            return operand_one_int * operand_two_int;
        } 
        else if (strcmp(alu_one->operator, "/") == 0) {
            if (operand_two_int != 0) 
            {
                return operand_one_int / operand_two_int;
            } 
            else 
            {
                printf("Error: Division by zero!\n");
                return -1;
            }
        } 
        else 
        {
            printf("Error: Invalid arithmetic operator!\n");
            return -1;
        }
    } else if (alu_one->operator_type == 0) {
        if (strcmp(alu_one->operator, "OR") == 0) 
        {
            return operand_one_int || operand_two_int;
        } 
        else if (strcmp(alu_one->operator, "AND") == 0)
        {
            return operand_one_int && operand_two_int;
        } 
        else if (strcmp(alu_one->operator, "XOR") == 0)
        {
            return operand_one_int ^ operand_two_int;
        } 
        else if (strcmp(alu_one->operator, "XNOR") == 0) 
        {
            return ~(operand_one_int ^ operand_two_int);
        } 
        else if (strcmp(alu_one->operator, "NOR") == 0) 
        {
            return !(operand_one_int || operand_two_int);
        } 
        else if (strcmp(alu_one->operator, "NAND") == 0)
        {
            return !(operand_one_int && operand_two_int);
        } 
        else 
        {
            printf("Error: Invalid logical operator!\n");
            return -1;
        }
    } 
    else
    {
        printf("Error: Invalid operator type!\n");
        return -1;
    }
}
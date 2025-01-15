#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ALGORITHM AND LOGICAL UNIT [DEALS WITH 8-bit NUMBERS] */
/* OPERATOR TYPE 1 DEFINES ARITHMETIC OPERATIONS IN THE ALU AND OPERATOR TYPE 2 DEFINES LOGICAL OPERATIONS IN THE ALU*/

struct ALU_8_BIT {
    int operand_one;
    int operand_two;
    int operator_type;
    char operator[5];
};

/* INSTRUCTION REGISTER FOR AN 8-bit CPU*/

/* FOR DIRECT ADDRESSING MODE */
struct INSTRUCTION_REGISTER_DAM{
    char alu_opcode[5];
    int operand_one;
    int operand_two;
};

/* FOR REGISTER ADDRESSING MODE */
struct INSTRUCTION_REGISTER_RAM{
    char alu_opcode[5];
    char operand_one[5];
    char operand_two[5];
};


/* CHARACTER REGISTERS */

char Rc_0, Rc_1, Rc_2;

/* NUMERIC REGISTERS */

int Ri_0, Ri_1, Ri_2;

int ALU_COMPUTATION_RESULT(struct ALU_8_BIT *alu_one) {
    if (alu_one->operator_type == 1) {
        if (strcmp(alu_one->operator, "ADD") == 0) 
        {
            return alu_one->operand_one + alu_one->operand_two;
        } 
        else if (strcmp(alu_one->operator, "SUB") == 0) 
        {
            return alu_one->operand_one - alu_one->operand_two;
        } 
        else if (strcmp(alu_one->operator, "MUL") == 0) 
        {
            return alu_one->operand_one * alu_one->operand_two;
        } 
        else if (strcmp(alu_one->operator, "DIV") == 0) {
            if (alu_one->operand_two != 0) 
            {
                return alu_one->operand_one / alu_one->operand_two;
            } 
            else 
            {
                return -1;
            }
        } 
        else 
        {
            return -1;
        }
    } else if (alu_one->operator_type == 0) {
        if (strcmp(alu_one->operator, "OR") == 0) 
        {
            return alu_one->operand_one || alu_one->operand_two;
        } 
        else if (strcmp(alu_one->operator, "AND") == 0)
        {
            return alu_one->operand_one && alu_one->operand_two;
        } 
        else if (strcmp(alu_one->operator, "XOR") == 0)
        {
            return alu_one->operand_one ^ alu_one->operand_two;
        } 
        else if (strcmp(alu_one->operator, "XNOR") == 0) 
        {
            return ~(alu_one->operand_one ^ alu_one->operand_two);
        } 
        else if (strcmp(alu_one->operator, "NOR") == 0) 
        {
            return !(alu_one->operand_one || alu_one->operand_two);
        } 
        else if (strcmp(alu_one->operator, "NAND") == 0)
        {
            return !(alu_one->operand_one && alu_one->operand_two);
        } 
        else 
        {
            printf("Error: Invalid logical operator!\n");
            return -1;
        }
    } 
    else
    {
        return -1;
    }
}

/* STORE OPERATIONS FOR INTEGER OPERANDS */

void STORE_INTEGER(char INT_REG[5], int operand) {
    if (strcmp(INT_REG, "Ri_0") == 0) {
        Ri_0 = operand;
    }
    else if (strcmp(INT_REG, "Ri_1") == 0) {
        Ri_1 = operand;
    }
    else if (strcmp(INT_REG, "Ri_2") == 0) {
        Ri_2 = operand;
    }
    else {
        return -1;
    }
}

/* STORE OPERATIONS FOR CHARACTER VALUES */

void STORE_CHARACTER(char CHAR_REG[5], int operand) {
    if (strcmp(CHAR_REG, "Rc_0") == 0) {
        Rc_0 = operand;
    }
    else if (strcmp(CHAR_REG, "Rc_1") == 0) {
        Rc_1 = operand;
    }
    else if (strcmp(CHAR_REG, "Rc_2") == 0) {
        Rc_2 = operand;
    }
    else {
        return -1;
    }
}

/* LOAD INTEGER VALUES FROM INTEGER REGISTER */

int LOAD_INTEGER(char INT_REG[5]) {
    if (strcmp(INT_REG, "Ri_0") == 0) {
        return Ri_0;
    }
    else if (strcmp(INT_REG, "Ri_1") == 0) {
        return Ri_1;
    }
    else if (strcmp(INT_REG, "Ri_2") == 0) {
        return Ri_2;
    }
    else {
        return -1;
    }
}

/* LOAD CHARACTER VALUES FROM CHARACTER REGISTER */

int LOAD_CHARACTER(char CHAR_REG[5]) {
    if (strcmp(CHAR_REG, "Rc_0") == 0) {
        return Ri_0;
    }
    else if (strcmp(CHAR_REG, "Rc_1") == 0) {
        return Ri_1;
    }
    else if (strcmp(CHAR_REG, "Rc_2") == 0) {
        return Ri_2;
    }
    else {
        return -1;
    }
}

/* INSTRUCTION DECODDING FOR REGISTER ADDRESSING MODE */

int INSTRUCTION_DECODER_RAM(struct INSTRUCTION_REGISTER_RAM IDR){
    struct ALU_8_BIT *alu_one = malloc(sizeof(struct ALU_8_BIT));
    if(strcmp(IDR.alu_opcode, "ADD") == 0){
        if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_0")){
            alu_one->operand_one=Ri_0;
            alu_one->operand_two=Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "ADD");
            ALU_COMPUTATION_RESULT(alu_one);
        }
    }
    else if(strcmp(IDR.alu_opcode, "ADD") == 0){
        if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_1")){
            alu_one->operand_one=Ri_0;
            alu_one->operand_two=Ri_1;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "ADD");
            ALU_COMPUTATION_RESULT(alu_one);
        }
    }
    else if(strcmp(IDR.alu_opcode, "ADD") == 0){
        if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_2")){
            alu_one->operand_one=Ri_0;
            alu_one->operand_two=Ri_2;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "ADD");
            ALU_COMPUTATION_RESULT(alu_one);
        }
    }
    if(strcmp(IDR.alu_opcode, "ADD") == 0){
        if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0){
            alu_one->operand_one = Ri_1;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "ADD");
            ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "ADD") == 0){
            if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0){
                alu_one->operand_one = Ri_1;
                alu_one->operand_two = Ri_1;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "ADD");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "ADD") == 0){
            if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0){
                alu_one->operand_one = Ri_1;
                alu_one->operand_two = Ri_2;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "ADD");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
    if(strcmp(IDR.alu_opcode, "ADD") == 0){
        if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0){
            alu_one->operand_one = Ri_2;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "ADD");
            ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "ADD") == 0){
            if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0){
                alu_one->operand_one = Ri_2;
                alu_one->operand_two = Ri_1;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "ADD");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "ADD") == 0){
            if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0){
                alu_one->operand_one = Ri_2;
                alu_one->operand_two = Ri_2;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "ADD");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
    if(strcmp(IDR.alu_opcode, "SUB") == 0){
        if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0){
            alu_one->operand_one = Ri_2;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "SUB");
            ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "SUB") == 0){
            if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0){
                alu_one->operand_one = Ri_2;
                alu_one->operand_two = Ri_1;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "SUB");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "SUB") == 0){
            if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0){
                alu_one->operand_one = Ri_2;
                alu_one->operand_two = Ri_2;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "SUB");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        if(strcmp(IDR.alu_opcode, "SUB") == 0){
        if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0){
            alu_one->operand_one = Ri_0;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "SUB");
            ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "SUB") == 0){
            if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0){
                alu_one->operand_one = Ri_0;
                alu_one->operand_two = Ri_1;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "SUB");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "SUB") == 0){
            if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0){
                alu_one->operand_one = Ri_0;
                alu_one->operand_two = Ri_2;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "SUB");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
    if(strcmp(IDR.alu_opcode, "SUB") == 0){
        if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0){
            alu_one->operand_one = Ri_1;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "SUB");
            ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "SUB") == 0){
            if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0){
                alu_one->operand_one = Ri_1;
                alu_one->operand_two = Ri_1;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "SUB");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "SUB") == 0){
            if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0){
                alu_one->operand_one = Ri_1;
                alu_one->operand_two = Ri_2;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "SUB");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
    if(strcmp(IDR.alu_opcode, "MUL") == 0){
        if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0){
            alu_one->operand_one = Ri_2;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "MUL");
            ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "MUL") == 0){
            if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0){
                alu_one->operand_one = Ri_2;
                alu_one->operand_two = Ri_1;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "MUL");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "MUL") == 0){
            if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0){
                alu_one->operand_one = Ri_2;
                alu_one->operand_two = Ri_2;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "MUL");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
    if(strcmp(IDR.alu_opcode, "MUL") == 0){
        if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0){
            alu_one->operand_one = Ri_1;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "MUL");
            ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "MUL") == 0){
            if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0){
                alu_one->operand_one = Ri_1;
                alu_one->operand_two = Ri_1;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "MUL");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "MUL") == 0){
            if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0){
                alu_one->operand_one = Ri_1;
                alu_one->operand_two = Ri_2;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "MUL");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
    if(strcmp(IDR.alu_opcode, "MUL") == 0){
        if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0){
            alu_one->operand_one = Ri_0;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "MUL");
            ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "MUL") == 0){
            if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0){
                alu_one->operand_one = Ri_0;
                alu_one->operand_two = Ri_1;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "MUL");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        else if(strcmp(IDR.alu_opcode, "MUL") == 0){
            if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0){
                alu_one->operand_one = Ri_0;
                alu_one->operand_two = Ri_2;
                alu_one->operator_type = 1;
                strcpy(alu_one->operator, "MUL");
                ALU_COMPUTATION_RESULT(alu_one);
            }
        }
        if(strcmp(IDR.alu_opcode, "DIV") == 0) {
        if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0) {
            alu_one->operand_one = Ri_0;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "DIV");
            ALU_COMPUTATION_RESULT(alu_one);
        } 
        else if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0) {
            alu_one->operand_one = Ri_0;
            alu_one->operand_two = Ri_1;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "DIV");
            ALU_COMPUTATION_RESULT(alu_one);
        } 
        else if(strcmp(IDR.operand_one, "Ri_0") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0) {
            alu_one->operand_one = Ri_0;
            alu_one->operand_two = Ri_2;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "DIV");
            ALU_COMPUTATION_RESULT(alu_one);
        } 
        else if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0) {
            alu_one->operand_one = Ri_1;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "DIV");
            ALU_COMPUTATION_RESULT(alu_one);
        } 
        else if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0) {
            alu_one->operand_one = Ri_1;
            alu_one->operand_two = Ri_1;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "DIV");
            ALU_COMPUTATION_RESULT(alu_one);
        } 
        else if(strcmp(IDR.operand_one, "Ri_1") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0) {
            alu_one->operand_one = Ri_1;
            alu_one->operand_two = Ri_2;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "DIV");
            ALU_COMPUTATION_RESULT(alu_one);
        } 
        else if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_0") == 0) {
            alu_one->operand_one = Ri_2;
            alu_one->operand_two = Ri_0;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "DIV");
            ALU_COMPUTATION_RESULT(alu_one);
        } 
        else if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_1") == 0) {
            alu_one->operand_one = Ri_2;
            alu_one->operand_two = Ri_1;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "DIV");
            ALU_COMPUTATION_RESULT(alu_one);
        } 
        else if(strcmp(IDR.operand_one, "Ri_2") == 0 && strcmp(IDR.operand_two, "Ri_2") == 0) {
            alu_one->operand_one = Ri_2;
            alu_one->operand_two = Ri_2;
            alu_one->operator_type = 1;
            strcpy(alu_one->operator, "DIV");
            ALU_COMPUTATION_RESULT(alu_one);
        }
    }
}

/* INSTRUCTION DECODER FOR DIRECT ADDRESSING MODE */

int INSTRUCTION_DECODER_DAA(struct INSTRUCTION_REGISTER_DAM IDD){
    struct ALU_8_BIT *alu_one = malloc(sizeof(struct ALU_8_BIT));
    if(strcmp(IDD.alu_opcode, "ADD") == 0){
        alu_one->operand_one = IDD.operand_one;
        alu_one->operand_two = IDD.operand_two;
        alu_one->operator_type = 1;
        strcpy(alu_one->operator, "ADD");
        ALU_COMPUTATION_RESULT(alu_one);
    }
    else if(strcmp(IDD.alu_opcode, "SUB") == 0){
        alu_one->operand_one = IDD.operand_one;
        alu_one->operand_two = IDD.operand_two;
        alu_one->operator_type = 1;
        strcpy(alu_one->operator, "SUB");
        ALU_COMPUTATION_RESULT(alu_one);
    }
    else if(strcmp(IDD.alu_opcode, "MUL") == 0){
        alu_one->operand_one = IDD.operand_one;
        alu_one->operand_two = IDD.operand_two;
        alu_one->operator_type = 1;
        strcpy(alu_one->operator, "MUL");
        ALU_COMPUTATION_RESULT(alu_one);
    }
    else if(strcmp(IDD.alu_opcode, "DIV") == 0){
        alu_one->operand_one = IDD.operand_one;
        alu_one->operand_two = IDD.operand_two;
        alu_one->operator_type = 1;
        strcpy(alu_one->operator, "DIV");
        ALU_COMPUTATION_RESULT(alu_one);
    }
}
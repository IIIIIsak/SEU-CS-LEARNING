.286
.MODEL SMALL
.DATA
    TABLE DB 0,1,4,9,16,25,36,49,64,81
    X DB ?
    Y DB ?
.STACK
.CODE
START: MOV AX,@DATA
       MOV DS,AX
       LEA BX,TABLE  ;  ��TABLE�Ļ���ַ������
       MOV AL,X
       XLAT
       MOV Y,AL
END START
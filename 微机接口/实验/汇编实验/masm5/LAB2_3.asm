.286
.MODEL SMALL
.DATA
.STACK
.CODE
START: MOV BL,6
       MOV BH,8
       MOV CL,3
       MOV CH,4
       MOV DI,0
       MOV AL,1   ; �������һλ
       MUL BL
       ADD DI,AX
       MOV AL,10
       MUL BH     ; ���㵹���ڶ�λ
       ADD DI,AX
       MOV AL,100 ; ���㵹������λ
       MUL CL
       ADD DI,AX
       MOV CL,CH
       MOV CH,0    ;�������λ        
       MOV AX,1000
       MUL CX;
       ADD DI,AX
END START
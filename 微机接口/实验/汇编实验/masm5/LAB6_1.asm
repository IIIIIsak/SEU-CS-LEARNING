.286
.MODEL SMALL
.DATA
STRING DB 'ABCDEFGHHGFEDCBA$' ; 16���ֽڵ��ַ�����������$)
YESSTRING DB 'yes$'
NOSTRING DB 'no$'
.STACK
.CODE
MAIN PROC FAR
    MOV AX,@DATA
    MOV DS,AX
    MOV CX,8  
AGAIN:  MOV BX,8  ; ��ָ��
        MOV DI,7;  βָ��
        SUB BX,CX
        ADD DI,CX
        MOV DL,STRING[BX]  ;���ַ�
        CMP DL,STRING[DI]  ;
        LOOPZ AGAIN        ; ��ȵ�ʱ��ż���
        JNZ NO             ;  ���һ���ַ��������
        CMP CX, 0          ; CX��ֵ����Ϊ0
        JZ YES             ; ���CXΪ0��ǰ��û����ת֤���жϵ����һ���ַ��ˣ��ǻ����ַ���
NO: MOV AH,09H
    LEA DX,NOSTRING 
    JMP DONE
YES: MOV AH,09H
    LEA DX,YESSTRING
DONE: INT 21H
      MOV AH,4CH ;����Dos
      INT 21H
MAIN ENDP
END MAIN
        
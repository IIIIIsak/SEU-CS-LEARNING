.286
.MODEL SMALL
.DATA
    STRING DB 5 DUP(20H),'$'
.STACK ; Ĭ�϶�ջ�εĳ���Ϊ 1024
.CODE
FAC PROC NEAR ; ��ײ㺯������ڲ���AL(���N),���ڲ���DX(��Ž����
    MOV AH,0   ;��ʼ������
    MOV DX,0
    CMP AL,1 ; 1�ǳ�������,�����������
    JZ OUTP
    PUSH AX  ; �� N��ֵ�����ڶ�ջ�� DX��ֵӦ�ò���Ҫ����
    DEC AL; AL��1
    CALL NEAR PTR FAC ; �ݹ���� ���� (N-1)! ��������DX��
    POP AX;    ��ȡ֮ǰ�����AX
    MUL DX;       ������������ DX:AX��
    MOV DX,AX ;   �Ѽ�����������DX��
    RET
OUTP: MOV DX,1
    RET
FAC ENDP
PRINT PROC NEAR ; ��ڲ���DX����DX�е�ֵתΪΪʮ��������ӡ����Ļ��
    MOV AX,@DATA
    MOV DS,AX
    MOV DI,4
    MOV CX,10; ÿ�γ���10
    MOV AX,DX ;  ��DX�е�ֵ�Ƶ�AX���Ϊ֮��Ҫ��������DX����ڲ���
    AGAIN: MOV DX,0   ;װ�뱻����NUM
           DIV CX ; ȡ���λ
           ADD DL,30H;  ����Ϊ���λ������һ��С��10ȡDL����ת��ΪASSIC��
           MOV STRING[DI],DL ; ��������������
           DEC DI;  DI -- 
           CMP AX,0 ; �ж����Ƿ�Ϊ0
          JNZ AGAIN ;  ��Ϊ0���ؿ�ͷ����ִ��      
    MOV AH,09H   ;��ӡSTRING������
	ADD DI,1
    LEA DX,STRING
	ADD DX,DI
    INT 21H
    RET
PRINT ENDP
MAIN PROC NEAR;   ������
    MOV AH,01H
    INT 21H
    MOV BL,AL
    MOV AH,2  ;����
    MOV DL,0AH
    INT 21H 
    MOV DL,0DH
    INT 21H 
    MOV AL,BL
    AND AL, 0FH;  ��ASCII��ת��Ϊ����,���θ���λ
    CALL NEAR PTR FAC ; ������ײ㣬�������DX��
    MOV AX,DX
    CALL NEAR PTR PRINT ; ��ӡ����Ļ��
    RET
MAIN ENDP
START:CALL NEAR PTR MAIN  ;���������
      MOV AH,4CH
      INT 21H
END START

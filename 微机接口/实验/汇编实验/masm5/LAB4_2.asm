.286
.MODEL SMALL
.DATA
    STRING DB 'stringstrin$'
	OUTPUT DB 5 DUP(20H),'$'
.STACK
.CODE
START: MOV AX,@DATA
       MOV DS,AX
       MOV BX,-1
AGAIN: INC BX
       MOV CX ,65535; �ַ�������󳤶ȣ���ֹԽ�����
       CMP STRING[BX],'$'
       LOOPNZ AGAIN;  ��'$'�Ų�ͬ����
	
DONE:  MOV DX,BX
	   CALL PRINT
       MOV AH,4CH ;��ɵ�ʱ�� BX���±��� '$'���±꣬����BX�����ַ����ĳ���(�ų�$)
       INT 21H
PRINT PROC NEAR ; ��ڲ���DX����DX�е�ֵתΪΪʮ��������ӡ����Ļ��
    MOV AX,@DATA
    MOV DS,AX
    MOV DI,4
    MOV CX,10; ÿ�γ���10
    MOV AX,DX ;  ��DX�е�ֵ�Ƶ�AX���Ϊ֮��Ҫ��������DX����ڲ���
    PRINTAGAIN: MOV DX,0   ;װ�뱻����NUM
           DIV CX ; ȡ���λ
           ADD DL,30H;  ����Ϊ���λ������һ��С��10ȡDL����ת��ΪASSIC��
           MOV OUTPUT[DI],DL ; ��������������
           DEC DI;  DI -- 
           CMP AX,0 ; �ж����Ƿ�Ϊ0
          JNZ PRINTAGAIN ;  ��Ϊ0���ؿ�ͷ����ִ��      
    MOV AH,09H   ;��ӡSTRING������
	ADD DI,1
    LEA DX,OUTPUT
	ADD DX,DI
    INT 21H
    RET
PRINT ENDP	   
END START
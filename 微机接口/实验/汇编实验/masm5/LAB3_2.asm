.286
.MODEL SMALL
.DATA
    NUM DW 6553
    STRING DB 5 DUP(20H),'$'
.STACK
.CODE
START: MOV AX,@DATA
       MOV DS,AX
       MOV DI,4
       MOV AX,NUM 
       MOV CX,10; ÿ�γ���10
AGAIN: MOV DX,0   ;װ�뱻����NUM
       DIV CX ; ȡ���λ
       ADD DL,30H;  ����Ϊ���λ������һ��С��10ȡDL����ת��ΪASSIC��
       MOV STRING[DI],DL ; ��������������
       DEC DI;  DI -- 
       CMP AX,0 ; �ж����Ƿ�Ϊ0
       JNZ AGAIN ;  ��Ϊ0���ؿ�ͷ����ִ��      
PRINT: MOV AH,09H   ;��ӡSTRING������
	   ADD DI ,1 ;
       LEA DX,STRING
	   ADD DX,DI 
       INT 21H
       MOV AH,4CH
       INT 21H  ;   ����DOS
END START
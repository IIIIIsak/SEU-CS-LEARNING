.286
.MODEL SMALL
.DATA
    ARRAY DB 1,2,3,4,5,6,7,8,9,10,11,12    ;���������Ϊ�޷�����������
.STACK
.CODE
SEARCH PROC NEAR
    MOV AX,@DATA 
    MOV DS,AX             
    PUSH AX           ; ��ڲ��� SI(���A_HEAD),DI(���A_END)��DL���N ,  ���ڲ����� SI��DI����µ������ ͷβ�� CF, ���ö��ֲ��ҷ�  �õ��� AX,DS,ES DX,BX,CX
    PUSH DS
    PUSH ES
    PUSH DX
    PUSH BX
    PUSH CX
    PUSH SI
    PUSH DI       ;DI���PUSH
AGAIN : CMP SI,DI ; �Ƚ���βָ��
        JG FAIL;  �����ƫ�ƴ���βƫ��ʧ���� �������������з�����
        MOV AX,DI     ;��������ĳ���
        SUB AX,SI   
        MOV DH , AL ; DH�������ĳ���
        SHR DH,1; 
        MOV BX,SI;   BX����м���λ��
        ADD BL,DH   ;����BX��ֵ
        ADC BL,0;
        MOV AL, [BX] ; �м����
        CMP DL, AL
        JZ SUS       ;�����ɹ� 
        JA GREAT      ; ���С��
        JB LESS       ; ���С��
GREAT: MOV SI,BX ;    �������Ϊ�м�ֵ
       INC SI
       JMP AGAIN
LESS:  MOV DI,BX ;    ���յ���Ϊ�м�ֵ
       DEC DI;
       JMP AGAIN
SUS:   CLD        ; BX��ŵ��ǵ�ǰԪ�ص�ƫ����
       MOV AX,DS;
       MOV ES,AX
       POP CX;
       PUSH CX;
       SUB CX,BX;   ����ѭ������        
       MOV SI,BX
       MOV DI,BX
       INC SI 
       REP MOVSB
       POP DI
       POP SI
       MOV AH ,0FFH
       ADD AH, 1 ; ��CFΪ1
       JMP DONE
FAIL:
       MOV AH,0H
       ADD AH,1;  ��CFΪ0
       POP DI
       POP SI
DONE:
       POP CX
       POP BX
       POP DX
       POP ES
       POP DX
       POP AX
       RET
SEARCH ENDP
MAIN PROC FAR
    LEA SI,ARRAY
    MOV DI,SI 
    ADD DI, 11
    MOV DL,4
    CALL SEARCH
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
    
    
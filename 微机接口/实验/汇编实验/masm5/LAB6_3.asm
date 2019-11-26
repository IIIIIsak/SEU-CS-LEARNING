.286
.MODEL SMALL 
.DATA
ATTENTION DB 'You must input 0~129$'
TABLE DB '0000000100100011010001010110011110001001101010111100110111101111$'
OUTPUT DB '00000000$'        ;�����8λ
INPUT DB 6     ; �����Ǵ� 0-129����Ԥ��4λ�ڴ棨����$)
      DB ?
      DB 6 DUP(?)
.STACK
.CODE
LINE PROC NEAR          ; ������������ӳ���, ʹ���� AX �� DX�Ĵ���
    PUSH AX
    PUSH DX
    MOV AH,02H
    MOV DL,0AH
    INT 21H
    MOV DL, 0DH 
    INT 21H
    POP DX
    POP AX
    RET
LINE ENDP
GETINPUT PROC NEAR ;  �Ӽ��̻�ȡʮ�����������ҽ��䴢����BL�� ���ڲ���BL�� ʹ�õļĴ��� AX,DS ,DX ,DI ,CX
    PUSH AX
    PUSH DS
    PUSH DX
    PUSH DI
    PUSH CX
    MOV AX,@DATA
    MOV DS,AX 
    MOV AH,0AH  ;   �Ӽ��̻�ȡ����
    LEA DX,INPUT
    INT 21H  
    LEA DI ,INPUT
    ADD DI ,2;  
    MOV CX ,0;   ��������λ��
    MOV BL ,0             
GETINPUTAGAIN:  CMP BL,129
        JA GETINPUTERROR      ;�������129��ô����
        MOV DL, [DI]  ; ��ȡ��ǰ�ַ�
        CMP DL,0DH
        JZ GETINPUTNEXT       ;�ж��Ƿ��ǻس�������ǵĻ���ת
        SUB DL,30H    ; ��ASCII ��ת��Ϊ����
        CMP DL,0      ;�������0
        JL GETINPUTERROR      ; С��0 ERROR
        CMP DL,9      ;����С��9
        JG GETINPUTERROR      ;����9 ����  �����޷��������ж� ��Ϊ�ַ�����С�� 30H
        MOV AL,10     ;���ַ�ת��Ϊ��ֵ 
        MUL BL  
        MOV BL,AL     ;����˷����
        CMP AH,0      ; ��Ϊ�������BL�У����� AHһ����Ϊ0�ģ���ֹ��������ֽڳ˷�����AX�У��޷���OF���ж�
        JNZ GETINPUTERROR     
        ADD BL,DL     ; ��ֹ�ӷ����
        JC GETINPUTERROR    ;�޷����������CF�ж�
        INC CX        ;������
        INC DI
        JMP GETINPUTAGAIN
GETINPUTERROR: MOV AH,09H   ;��������ӡ������Ϣ
       LEA DX, ATTENTION 
       INT 21H
       CALL LINE
       CALL GETINPUT     ;�ٴ�����         
       JMP  GETINPUTDONE                           
GETINPUTNEXT:  CMP CX ,0           ;���BL��ֵΪ129�Ļ��Ȳ���
       JZ GETINPUTERROR ;  ��ֹ������
GETINPUTDONE:  POP CX         ;�����ֳ�
       POP DI
       POP DX
       POP DS
       POP AX
       RET
GETINPUT ENDP     

PRINTBINARY PROC NEAR ;  ��BL�е�ֵ�Զ����Ƶ���ʽ��ӡ��ȥ,��ڲ���BL, ����ַ����� STRING ҪԤ�����ú�DS , ����BL�е�����16�������� 16����ת������1Ϊ����2����4Ϊ�����ò�����ÿռ任ʱ��ʮ�����ף�������10����ת�����Ƶķ���
        PUSHA         ;û�г��ڲ��� ����ֱ��ȫ����ջ
        LEA DI, OUTPUT 
        LEA SI,TABLE     ;ת�����ַ
        MOV AL,BL             ; �Ȳ����λ
        MOV AH,0
        MOV CL,4
        SHR AL,CL             ; ����4λ
        MOV CL,2
        SHL AL,CL             ;������λ
        ADD SI,AX         
        MOV CX,4    ;���͸�4���ֽڵ��ַ�
        REP MOVSB
        MOV AL,BL
        AND AL,0FH        ; ���θ���λ
        MOV CL,2
        SHL AL,CL          ; ������λ����Ϊ�ֽڵ�λ��4 
        LEA SI,TABLE
        ADD SI,AX       
        MOV CX,4
        REP MOVSB             ;���͵��ĸ��ֽڵ��ַ�
        JMP PRINTBINARYDONE
PRINTBINARYDONE:   LEA DX, OUTPUT
                   MOV AH ,09H
                   INT 21H      ;���ַ������
                   POPA
                   RET
PRINTBINARY ENDP
MAIN PROC FAR       ;������
AGAIN:    MOV AX,@DATA
          MOV DS,AX
          MOV ES,AX
          CALL GETINPUT   ;�������
          CMP BL,129      ;�����129 ����DOS
          JZ EXIT
          CALL LINE      ;����
          CALL PRINTBINARY ;���
          CALL LINE      ;����
          JMP AGAIN
EXIT:  MOV AH,4CH      ; ����DOS
       INT 21H
       RET
MAIN ENDP
END MAIN
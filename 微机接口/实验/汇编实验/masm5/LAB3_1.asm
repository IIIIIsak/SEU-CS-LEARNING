.286
.MODEL SMALL
.DATA
MON DB 'Monday$'
TUE DB 'Tuesday$'
WED DB 'Wednesday$'
THU DB 'Thursday$'
FRI DB 'Friday$'
SAT DB 'Saturday$'
SUN DB 'Sunday$'
LINE DB 0AH,0DH,'$'  ; ���з������һ���ַ���
TABLE DW MONDAY  ; ��ת��
      DW TUESDAY
      DW WEDNESDAY
      DW THURSDAY
      DW FRIDAY
      DW SATURDAY
      DW SUNDAY
.STACK
.CODE
START:MOV AX,@DATA
      MOV DS,AX ; �ε�ַ
      MOV AH,01H ; �Ӽ����������ַ�
      INT 21H
      AND AL,0FH; ���ε�����λ��ȡ����
      LEA DX,LINE ;����
      MOV AH,09H
      INT 21H
      SUB AL,1;    �±��0��ʼ���Լ�1  1-7�ֱ������һ-����
      SHL AL,1 ;   ���������λ������1λ
      MOV BL,AL   ; ���� BX��ֵ�����ñ�ַѰַ��ʽ
      MOV BH,0
      JMP WORD PTR TABLE[BX] ; 
MONDAY: LEA DX,MON   ;��һ��AHǰ���Ѿ�ָ������
        JMP DONE
TUESDAY: LEA DX,TUE   ;�ܶ�
        JMP DONE
WEDNESDAY: LEA DX,WED  ;����
        JMP DONE
THURSDAY: LEA DX,THU   ;����
        JMP DONE
FRIDAY: LEA DX,FRI   ;����
        JMP DONE
SATURDAY: LEA DX,SAT    ;����
        JMP DONE
SUNDAY: LEA DX,SUN   ;���գ����һ������JMP
DONE: INT 21H
MOV AH,4CH
      INT 21H
      END START
package Template_Pattern;

public abstract class Account {
	
     // �������� ���巽���� �����û���Ϣ�������û�����
     final public  double  getCapital(String username) {
    	 //�������ݿ⣬���������� username ���� uuid ���ݾ������������������username
    	 
    	 //����Ĭ�Ϸ��� 100
    	 return 100.0;
     }
     
     // �������� ���󷽷��� �ɱ��������Ϣ ������ʵ��
     abstract public double calInterest(double capital);
     
     //�������� ���巽������ӡ��Ϣ
     final public void printInterest(double interest) {
    	 System.out.println("��ϢΪ:"+interest);
     }
     
     //ģ�巽���� ����������
     public void  process(String username) {

    	 // ��ȡ����
    	 Double capital =  getCapital(username);
    	 
    	 //������Ϣ
    	 Double interest = calInterest(capital);
    	 
    	 //��ӡ��Ϣ
    	 printInterest(interest);
     }
}


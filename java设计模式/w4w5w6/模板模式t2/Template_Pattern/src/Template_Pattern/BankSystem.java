package Template_Pattern;

public class BankSystem {
    //����ϵͳ �ͻ�����
	// accountType Ϊ�˲��Է���...  0 �� �����˻��� 1 �������˻�
    public void inquireInterest(String username,String password, int accountType) {
    	// ��֤�û�������
    	// ֱ�Ӳ�ѯ�û����˻����ͣ������ݿ�, ��������ͨ�����ݿ��ȡ���û�����
    	 if (accountType==0) {
    		 CurrentAccount a = new CurrentAccount();
    		 a.process(username);
    	 }else if(accountType==1) {
    		 SavingAccount a = new  SavingAccount();
    		 a.process(username);
    	 }
    
    }
    

}

package StatePattern;

public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		// �ͻ�����
		
		Account myAccount = new Account("chonepieceyb",1000);
		myAccount.withdraw(500);
		myAccount.withdraw(1000);
		myAccount.withdraw(1000);
		myAccount.withdraw(1000);
		myAccount.deposit(5000);
		myAccount.withdraw(2000);
	}

}



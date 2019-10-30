package StatePattern;

public abstract class AccountState {
	Account account;
	double balance;
	public AccountState(double balance, Account a ) {
		// TODO �Զ����ɵĹ��캯�����
		this.account = a;
		this.balance= balance;
	}
	public abstract void  changeState();
	public void withdraw(double amount) {
		//ȡ���
		this.balance -= amount;
		System.out.println("�ɹ�ȡ�� "+amount+" Ԫ");
		System.out.println("���Ϊ "+this.balance+" Ԫ");
		changeState();
	}
	public void deposit(double amount) {
		this.balance += amount;
		System.out.println("�ɹ���� "+amount+" Ԫ");
		System.out.println("���Ϊ "+this.balance+" Ԫ");
		changeState();
	}
}



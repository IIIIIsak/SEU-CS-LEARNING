package StatePattern;

public class Account {
	AccountState  accountState;
	public void setAccountState(AccountState accountState) {
		this.accountState = accountState;
	}
	String username;
	Account(String user, double balance ){
		this.username = user;
		this.accountState = new GreenState(balance,this);
	}
	public void withdraw(double amount) {
		//ȡ���
		System.out.println(this.username+" ��ӭ������");
		this.accountState.withdraw(amount);
	}
	public void deposit(double amount) {
		//����
		System.out.println(this.username+" ��ӭ������");
		this.accountState.deposit(amount);
	}
}

package StatePattern;

public class RedState extends AccountState {

	public RedState(double balance, Account a) {
		super(balance, a);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void changeState() {
		// TODO �Զ����ɵķ������
		if (this.balance>=0) {
			this.account.setAccountState(new GreenState(this.balance,this.account));
		}else if (this.balance>=-1000 && this.balance<0) {
			this.account.setAccountState(new YellowState(this.balance,this.account));
		}
	}
	public void withdraw(double amount) {
		System.out.println("��ǰ�˻�Ϊ͸֧״̬���޷�ȡ��ֻ�ܴ�");
	}

}



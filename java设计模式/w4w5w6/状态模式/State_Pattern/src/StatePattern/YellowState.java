package StatePattern;

public class YellowState extends AccountState {

	public YellowState(double balance, Account a) {
		super(balance, a);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void changeState() {
		// TODO �Զ����ɵķ������
		if (this.balance>=0) {
			this.account.setAccountState(new GreenState(this.balance,this.account));
		}else if (this.balance<-1000) {
			this.account.setAccountState(new RedState(this.balance,this.account));
		}
	}

}



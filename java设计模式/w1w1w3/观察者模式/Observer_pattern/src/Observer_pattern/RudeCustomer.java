package Observer_pattern;

public class RudeCustomer extends Customer {


	@Override
	public void catchAttention() {
		// TODO �Զ����ɵķ������
		for ( CustomerListener l: this.listener) {
			l.response();
		}
	}
	public void shout() {
		System.out.println("�˿ʹ���˵��");
		catchAttention();
	}
}

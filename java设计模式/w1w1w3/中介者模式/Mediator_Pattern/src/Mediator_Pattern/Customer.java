package Mediator_Pattern;

public class Customer extends Comunicator {
	public Customer(Server s){
		super(s);
	}
	@Override
	public void getMessage(String message) {
		// TODO �Զ����ɵķ������
		System.out.println("�ͻ��յ�����Ϣ��"+message);
	}
	public void ask(String message) {
		this.server.communicate(message, this);
	}
}

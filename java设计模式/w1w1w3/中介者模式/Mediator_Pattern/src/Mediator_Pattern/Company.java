package Mediator_Pattern;

public class Company extends Comunicator {

	public Company(Server s) {
		super(s);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void getMessage(String message) {
		// TODO �Զ����ɵķ������
		System.out.println("���Թ�˾�յ�����Ϣ:"+message);
	}
	public void answer(String message) {
		this.server.communicate(message, this);
	}

}


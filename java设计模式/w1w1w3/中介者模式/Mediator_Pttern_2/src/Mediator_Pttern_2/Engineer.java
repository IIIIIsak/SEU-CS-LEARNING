package Mediator_Pttern_2;

public class Engineer extends Comunicator {

	public Engineer(String key) {
		super(key);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void getMessage(String message,String from) {
		// TODO �Զ����ɵķ������
		System.out.println("����ʦ�յ� "+from +"����Ϣ�� "+message);
	}
	public void replay(String message,String to) {
		this.server.communicate(message, this.getKey(), to);
	}
}

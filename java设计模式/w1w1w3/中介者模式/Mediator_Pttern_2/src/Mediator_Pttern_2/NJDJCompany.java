package Mediator_Pttern_2;

public class NJDJCompany extends Comunicator {

	public NJDJCompany(String key) {
		super(key);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void getMessage(String message, String from) {
		// TODO �Զ����ɵķ������
		System.out.println("�Ͼ����˾�յ� "+from +"����Ϣ�� "+message);
	}
	public void replay(String message,String to) {
		this.server.communicate(message, this.getKey(), to);
	}
}

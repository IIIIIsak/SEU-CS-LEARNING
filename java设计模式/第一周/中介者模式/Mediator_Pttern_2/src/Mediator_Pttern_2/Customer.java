package Mediator_Pttern_2;

public class Customer extends Comunicator {
	public Customer (String key){
		super(key);
	}
	@Override
	public void getMessage(String message,String from) {
		// TODO �Զ����ɵķ������
		System.out.println("�������յ� "+from +"�Ļظ��� "+message);
	}
	public void ask(String message,String to) {
		this.server.communicate(message, this.getKey(), to);
	}

}

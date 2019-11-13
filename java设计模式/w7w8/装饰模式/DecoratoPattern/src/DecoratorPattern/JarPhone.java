package DecoratorPattern;

public class JarPhone extends PhoneDecorator {
	
	public JarPhone(Phone p ) {
		super(p);
	}
	@Override
	public void getCall() {
		// TODO �Զ����ɵķ������
		this.phone.getCall();
		this.jar();
	}
	public void jar() {
		System.out.println("�ֻ�����");
	}
}


package DecoratorPattern;

public class ComplexPhone extends PhoneDecorator {

	public ComplexPhone(Phone p) {
		super(p);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void getCall() {
		// TODO �Զ����ɵķ������
		this.phone.getCall();
		this.light();
	}
	public void light() {
		System.out.println("�ֻ����緢����");
	}
}



package DecoratorPattern;

public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		//������
		SimplePhone sp = new SimplePhone();
		sp.getCall();
		System.out.println("-----------------------------------");
		JarPhone jp= new JarPhone(sp);  //��һ������
		jp.getCall();
		System.out.println("-----------------------------------");
		ComplexPhone cp = new ComplexPhone(jp); //�ڶ�������
		cp.getCall();
	}

}


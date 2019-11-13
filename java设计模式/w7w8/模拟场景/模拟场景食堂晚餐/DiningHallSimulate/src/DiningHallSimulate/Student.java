package DiningHallSimulate;

public class Student implements Visitor {
	private String name;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public PayMethod getPayMethod() {
		return payMethod;
	}
	public void setPayMethod(PayMethod payMethod) {
		this.payMethod = payMethod;
	}

	private PayMethod payMethod;
	public String wishFood=null;
	
	public Student(String name) {
		this.name=name;
	}
	@Override
	public void visit(HangMenJi f) {
		// TODO �Զ����ɵķ������
		System.out.println("ѧ������"+f.getName());
		this.pay(f.price);
	}

	@Override
	public void visit(DiaoZhaBing f) {
		// TODO �Զ����ɵķ������
		System.out.println("ѧ������"+f.getName());
		this.pay(f.price);
	}

	@Override
	public void visit(NiuRouMian f) {
		// TODO �Զ����ɵķ������
		System.out.println("ѧ������"+f.getName());
		this.pay(f.price);
	}
	
	//��ͺ���
	public String takeOrder() {
		//���������ѧ���������Ҫ�Ե�ʳ�������...�������������һ��������ã���������������ָ��
		return this.wishFood;
	}
	//��Ǯ
	public void pay(Double d) {
		this.payMethod.pay(d);
	}
}

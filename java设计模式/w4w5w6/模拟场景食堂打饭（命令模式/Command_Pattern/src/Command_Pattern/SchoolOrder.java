package Command_Pattern;

public class SchoolOrder extends Order {
	protected SchoolDiningHall dininghall;
	public void setDininghall(SchoolDiningHall dininghall) {
		this.dininghall = dininghall;
	}

	public SchoolOrder() {
		// TODO �Զ����ɵĹ��캯�����
		
	}
	public SchoolOrder(SchoolDiningHall dininghall) {
		// TODO �Զ����ɵĹ��캯�����
		this.setDininghall(dininghall);
	}

	@Override
	public void takeOutOrder() {
		// TODO �Զ����ɵķ������
		System.out.println("ѧУʳ���յ�����");
		this.dininghall.cook(this.orderName);
		System.out.println("ѧУʳ�ÿ�ʼ������");
	}

}


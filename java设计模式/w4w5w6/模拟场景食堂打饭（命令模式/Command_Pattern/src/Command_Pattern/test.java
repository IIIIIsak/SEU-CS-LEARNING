package Command_Pattern;

public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		//�ͻ��˴������
		//�½�ѧ��
		Student me = new Student();
		SchoolDiningHall dininghall = new SchoolDiningHall();
		SchoolOrder order = new SchoolOrder(dininghall);
		me.setOrder(order);
		me.makeOrder("����ţ����");
	}

}

	
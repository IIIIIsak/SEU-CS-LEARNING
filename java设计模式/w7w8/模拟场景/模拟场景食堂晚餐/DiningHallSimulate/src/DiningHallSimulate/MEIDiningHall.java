package DiningHallSimulate;

public class MEIDiningHall extends DiningHallDecorator {

	public MEIDiningHall(DiningHall dininghall) {
		super(dininghall);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public Seat findSeat() {
		// TODO �Զ����ɵķ������
		System.out.println("÷԰�����Ӹ�������");
		return this.dininghall.findSeat();
	}

	@Override
	public void lineup(int windownumber, Student s) {
		// TODO �Զ����ɵķ������
		this.dininghall.lineup(windownumber, s);
	}

	@Override
	public void process() {
		// TODO �Զ����ɵķ������
		System.out.println("÷԰�ķ��˸��ӿɿڣ�������ã���Ĳ˸���");
		this.dininghall.process();
	}

}

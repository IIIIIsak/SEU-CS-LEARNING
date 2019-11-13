package DiningHallSimulate;

public class TAODiningHall extends DiningHall {

	@Override
	public Seat findSeat() {
		// TODO �Զ����ɵķ������
		Seat s = this.seats.getEmptySeat();
		if(s == null ) {
			System.out.println("û��λ��");
			return null;
		}
		return s;
	}

	@Override
	public void lineup(int windownumber,Student s) {
		// TODO �Զ����ɵķ������
		if(windownumber>= this.windows.size()) {
			System.out.println("û���������");
			return;
		}
		this.windows.get(windownumber).addStudent(s);
	}

	@Override
	public void process() {
		// TODO �Զ����ɵķ������
		// ����ÿ�����ڵ�process����
		int i =0;
		for(Window w:this.windows) {
			System.out.println("����"+i+"������");
			w.process();
			i++;
		}
	}

}

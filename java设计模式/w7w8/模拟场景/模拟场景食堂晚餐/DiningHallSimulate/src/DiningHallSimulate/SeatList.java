package DiningHallSimulate;

import java.util.ArrayList;

public class SeatList {
	protected ArrayList<Seat> seats = new ArrayList<Seat>();
	public SeatList() {
		int i=0;
		for(i=0;i<3;i++) {
			seats.add(new Seat());   //Ĭ����3������
		}
	}
	public SeatIterator createSeatIterator() {
		return new  SeatIterator();
	}
	class SeatIterator{      //������ģʽ
		public Seat getEmptySeat() {
			Seat currentSeat = null;
			for(Seat s :seats) {
				if(s.getState()) { //����ǿյ�
					currentSeat =s;
				}
			}
			return currentSeat;
		}
		public void addSeat(Seat s) {
			seats.add(s);
		}
	}
}

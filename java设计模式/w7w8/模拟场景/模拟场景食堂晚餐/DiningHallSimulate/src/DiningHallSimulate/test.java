package DiningHallSimulate;

public class test {



	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		//������
		//��Ʒ ������ ���˼� ��������ţ����
		HangMenJi food1 = new HangMenJi(13.0, "���˼�");
		DiaoZhaBing food2 = new DiaoZhaBing(11.5, "������");
		NiuRouMian food3 = new NiuRouMian(10.0,"ţ����");
		//ʳ��
		//��԰ʳ��
		TAODiningHall taoyuan = new TAODiningHall();
		//������2������
		BaseWindow w1 = new BaseWindow();
		BaseWindow tempW = new BaseWindow();
		BaseWindow w2 = new  BaseWindow();  //����2 �ȴ���1���Ӹ߼� װ��ģʽ
		//һ��������һ����ʦ
		Server s1 = new Server();
		Server s2 = new Server();
		//���ô��ڷ���Ա�Ͳ�Ʒ
		w1.setServer(s1);
		w2.setServer(s2);
		w1.addFood(food1); //����1 �����˼�
		w2.addFood(food2); //���� 2��3���������ţ����
		w2.addFood(food3);
        //��������
  		SeatList seats1 = new SeatList();
		SeatList seats2 = new SeatList();
		seats2.createSeatIterator().addSeat(new Seat()); //�������
		//��װ��԰ʳ��
		taoyuan.setSeats(seats1.createSeatIterator());
		//taoyuan.addWindow(w1);
		taoyuan.addWindow(w2);
		// ÷԰ʳ�����ú���԰ʳ�û�������ֻ��������һЩ�µĹ���
		MEIDiningHall meiyuan = new MEIDiningHall(taoyuan);
		
		//ѧ��
		//���ʽ
		Cash cash = new Cash();
		Card card = new Card();
		Student student1 = new Student("С��");
		student1.setPayMethod(card);
		student1.wishFood="���˼�";
		Student  student2 = new Student("С��");
		student2.setPayMethod(card);
		student2.wishFood="ţ����";
		Student student3 = new Student("С��");
		student3.setPayMethod(cash);
		student3.wishFood="������";
		//ѧ��ȥʳ�óԷ��� 
		taoyuan.lineup(0, student1);
		taoyuan.lineup(0, student2);
		taoyuan.lineup(0, student3);
		//��ʼ��� һ����˳����У�û���ö��߳�
		System.out.println("-----------------------��԰----------------------------");
		taoyuan.process();
		
 	}

}

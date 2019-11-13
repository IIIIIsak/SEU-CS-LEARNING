package DiningHallSimulate;

public class BaseWindow extends Window {

	@Override
	public void process() {
		// TODO �Զ����ɵķ������
		do{
			Student currentStudent = this.queue.currentStudent();
			if (currentStudent==null) {
				return;
			}
			String foodName = currentStudent.takeOrder();      //����hash��� student��� wishFood����Ϊ������
			Food f = this.foodList.get(foodName);
			if(f==null) {
				System.out.println("û��ѧ����Ҫ�ԵĲ�");
			}else {
				f.accept(currentStudent);             //������ģʽ
				f.accept(this.server);
			}
			System.out.println("����һλѧ��ȡ��");
		}while(this.queue.next());
	}

}

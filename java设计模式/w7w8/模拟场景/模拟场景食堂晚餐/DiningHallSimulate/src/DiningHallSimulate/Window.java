package DiningHallSimulate;

import java.util.HashMap;

import DiningHallSimulate.StudentQueue.QueueIterator;

public abstract class Window {
	protected Visitor server;
	public void setServer(Visitor server) {
		this.server = server;
	}
	private StudentQueue sq = new StudentQueue();
	protected QueueIterator queue = this.sq.createQueueIterator();
	public void setQueue(QueueIterator queue) {
		this.queue = queue;
	}
	protected HashMap<String,Food> foodList = new HashMap<String,Food>() ;   //���ù�ϣ��Food����� Food���ƣ��ַ�������ƥ�䣬Ϊ�˷���ģ�ⳡ�����������process������student���takeorder������
	public void addFood(Food f) {
		this.foodList.put(f.getName(), f);
	}
	public void addStudent(Student s) {
		this.queue.addStudent(s);
	}
	public int getNum() {
		return this.queue.getNum();
	}
	abstract public void process();      //��˳���Ŷӵ�ͺ�����������ʵ��
}

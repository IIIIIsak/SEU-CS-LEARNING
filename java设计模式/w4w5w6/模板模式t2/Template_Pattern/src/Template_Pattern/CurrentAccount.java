package Template_Pattern;

public class CurrentAccount extends Account {

	@Override
	public double calInterest(double capital) {
		// TODO �Զ����ɵķ������
		// ��Ϣ���㲻ͬ
		System.out.println("���˻��ǻ����˻������û����˻���Ϣ���㷽��");
		return capital*0.01;
				
	}

}

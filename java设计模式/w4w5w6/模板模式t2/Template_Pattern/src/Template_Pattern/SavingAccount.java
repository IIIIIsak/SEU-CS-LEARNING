package Template_Pattern;

public class SavingAccount extends Account {

	@Override
	public double calInterest(double capital) {
		// TODO �Զ����ɵķ������
		System.out.println("���˻��Ƕ����˻������ö����˻���Ϣ���㷽��");
		return capital*0.03;
	}

}

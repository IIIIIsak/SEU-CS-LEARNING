package HWCompany_simulate;

public class HWRecruitAdapter implements SocialRecruit {
	//���ڽӿڲ�ͬ������ʹ���� ������ģʽ ���仪Ϊ��˾�����еĽӿ�
	private HWCompany HUAWEI;
	public void setHUAWEI(HWCompany hw) {
		this.HUAWEI= hw;
	}
	@Override
	public boolean recruit(PersonalProfile file) {
		// TODO �Զ����ɵķ������
		Interviewee i = file.getInterviewee();
		if( i instanceof SeniorTalents) {
			System.out.println("-------------------���ڸ߼��˲Ž��ɻ�Ϊ��˾�ܲ�ֱ�ӽ��е���Ƹ-------------------------------");
			return this.HUAWEI.hwRecruit((SeniorTalents)i);
		}else {
			System.out.println("---------�Բ���Ϊ��˾Ŀǰ��Ҫ�����������϶࣬ȡ��һ��ѧ���ɹ��ĸ߼��˲�,����������������ͨ�������ķ�ʽ���뻪Ϊ��˾----------------------------------------------");
			return false;
		}
	}
}

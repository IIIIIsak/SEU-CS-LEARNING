package HWCompany_simulate;

public class HWCompany {
	//���ڻ�Ϊ��˾ֻ��һ�� ���Բ����� ����ģʽ
	static private HWCompany instance;
	private HWRecruit hwRecruit;
	
	public void setHwRecruit(HWRecruit hwRecruit) {
		this.hwRecruit = hwRecruit;
	}
	private HWCompany() {
		
	}
	static public HWCompany getInstance() {
		if(instance ==null) {
			return new HWCompany();
		}else {
			return instance;
		}
	}
	public boolean hwRecruit(SeniorTalents st) {
		System.out.println("-------------------�ɻ�Ϊ��˾�ܲ�ֱ�ӽ��е���Ƹ-------------------------------");
		return this.hwRecruit.recruit(st);
	}
}

package HWCompany_simulate;

public class ProxyCompany implements SocialRecruit {
	//����˾�� ʹ���˴���ģʽ
	private RealSocialRecruit  realSocialRecruit;
	public void setRealSocialRecruit(RealSocialRecruit realSocialRecruit) {
		this.realSocialRecruit = realSocialRecruit;
	}
	public String getCompanyname() {
		return companyname;
	}
	public void setCompanyname(String companyname) {
		this.companyname = companyname;
	}
	public String companyname;
	public ProxyCompany (String companyname) {
		this.companyname = companyname;
	}
	@Override
	public boolean recruit(PersonalProfile file) {
		// TODO �Զ����ɵķ������
		System.out.println("------------------��Ϊ��˾ί�� "+ this.companyname +" ���������Ƹ----------------------------------");
		return this.realSocialRecruit.recruit(file);
	}
}

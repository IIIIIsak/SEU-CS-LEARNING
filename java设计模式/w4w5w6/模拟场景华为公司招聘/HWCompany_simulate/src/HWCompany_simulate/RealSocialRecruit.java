package HWCompany_simulate;

import java.util.Scanner;

public class RealSocialRecruit implements SocialRecruit {
	// ��ʵ��Ƹ��
	@Override
	public boolean recruit(PersonalProfile file) {
		// TODO �Զ����ɵķ������
		System.out.println("----------------���������Ƹ------------------------");
		file.printfile();
		System.out.println("������Ƿ�ͨ��");
	    boolean issucess = test.sc.nextBoolean();
	    
		if (! issucess) {
			System.out.println("---------------���ź���û��ͨ�������Ƹ--------------------------");
			return issucess;
		}else {
			System.out.println("---------------��ϲ�㱻��Ϊ��˾¼����!--------------------------");
			return  issucess;
		}
	}
}

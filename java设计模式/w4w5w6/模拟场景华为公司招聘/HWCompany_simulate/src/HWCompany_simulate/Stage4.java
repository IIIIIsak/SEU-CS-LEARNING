package HWCompany_simulate;

import java.util.Scanner;

public class Stage4 extends CampusRecruit {
	//��ΪУ��������
	@Override
	public boolean recruit(PersonalProfile file) {
		// TODO �Զ����ɵķ������
		System.out.println("----------------���뻪Ϊ��ѡ------------------------");
		file.printfile();
		System.out.println("������Ƿ�ͨ��");
	    boolean issucess = test.sc.nextBoolean();
		if (! issucess) {
			System.out.println("---------------���ź���û�б���Ϊ��˾¼��--------------------------");
			return issucess;
		}else {
			System.out.println("---------------��ϲ�㱻��Ϊ��˾¼���ˣ�--------------------------");
			return true;
		}
	}
}

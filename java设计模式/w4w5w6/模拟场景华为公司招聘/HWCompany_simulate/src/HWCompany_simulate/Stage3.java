package HWCompany_simulate;

import java.util.Scanner;

public class Stage3 extends CampusRecruit {
	// ��ΪУ��������
	@Override
	public boolean recruit(PersonalProfile file) {
		// TODO �Զ����ɵķ������
		System.out.println("----------------���뻪Ϊ���Խ׶�------------------------");
		file.printfile();
		System.out.println("������Ƿ�ͨ��");
	    boolean issucess = test.sc.nextBoolean();
		if (! issucess) {
			System.out.println("---------------���ź���û��ͨ����Ϊ������--------------------------");
			return issucess;
		}else {
			System.out.println("---------------��ϲ��ͨ���˻�Ϊ������,������һ���׶εĿ���--------------------------");
			return this.getNextRecruit().recruit(file);
		}	
	}
}

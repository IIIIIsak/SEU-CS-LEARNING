package HWCompany_simulate;

import java.util.Scanner;

public class Stage2 extends CampusRecruit {
	// ��ΪУ�м���������
	@Override
	public boolean recruit(PersonalProfile file) {
		// TODO �Զ����ɵķ������
		System.out.println("----------------���뻪Ϊ�������˽׶�------------------------");
		file.printfile();
		System.out.println("������Ƿ�ͨ��");
	    boolean issucess = test.sc.nextBoolean();
		if (! issucess) {
			System.out.println("---------------���ź���û��ͨ����Ϊ�ļ�������--------------------------");
			return issucess;
		}else {
			System.out.println("---------------��ϲ��ͨ���˻�Ϊ�ļ�������,������һ���׶εĿ���--------------------------");
			return this.getNextRecruit().recruit(file);
		}	
	}
}

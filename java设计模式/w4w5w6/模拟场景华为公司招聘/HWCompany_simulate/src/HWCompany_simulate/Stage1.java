package HWCompany_simulate;

import java.util.Scanner;

public class Stage1 extends CampusRecruit {
	@Override
	public boolean recruit(PersonalProfile file) {
		// TODO �Զ����ɵķ������
		// ��ΪHR��ѡ��
		System.out.println("----------------���뻪ΪHR��ѡ�׶�------------------------");
		file.printfile();
		System.out.println("������Ƿ�ͨ��");
		boolean issucess = test.sc.nextBoolean();
		if (! issucess) {
			System.out.println("---------------���ź���û��ͨ����Ϊ��HR��ѡ--------------------------");
			return issucess;
		}else {
			System.out.println("---------------��ϲ��ͨ���˻�Ϊ��HR��ѡ,������һ���׶εĿ���--------------------------");
			return this.getNextRecruit().recruit(file);
		}
	}
}

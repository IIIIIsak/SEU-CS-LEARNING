package HWCompany_simulate;

import java.util.Scanner;

public class test {
	static Scanner sc = new Scanner(System.in); 

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		// �ͻ�����
		//���� ������
		CommonInterviewee student = new CommonInterviewee();
		PersonalProfile studentFile = new PersonalProfile("����", "���˱�ҵ�붫�ϴ�ѧ�����ѧԺ�������꼶��һ��", student);
		student.setFile(studentFile);
		
		CommonInterviewee nostudent = new CommonInterviewee();
		PersonalProfile nostudentFile = new PersonalProfile("����", "����������Ѷ��˾������", nostudent);
		nostudent.setFile(nostudentFile);
		
		SeniorTalents professor  = new SeniorTalents();
		PersonalProfile professorFile = new PersonalProfile("�Ž���", "�ڼ����һ������з�������20��ƪ", professor);
		professor.setFile(professorFile);
		
		SeniorTalents professor2  = new SeniorTalents();
		PersonalProfile professorFile2 = new PersonalProfile("������", "�ڼ����һ������з�������10��ƪ", professor2);
		professor2.setFile(professorFile2);
		
		//������Ϊ��˾
		HWCompany HUAWEI = HWCompany.getInstance();
		
		//����У԰��Ƹ�ƶ�
		Stage1 campusRecruit1 = new Stage1();     //HR ����
		Stage2 campusRecruit2 = new Stage2();    //��������
		Stage3 campusRecruit3 = new Stage3();   // ����
		Stage4 campusRecruit4 = new Stage4() ;  //����
		//����У԰��Ƹ������
		campusRecruit1.setNextRecruit(campusRecruit2);
		campusRecruit2.setNextRecruit(campusRecruit3);
		campusRecruit3.setNextRecruit(campusRecruit4);
		campusRecruit4.setNextRecruit(null);
		
		//���������Ƹ
		RealSocialRecruit realSocalRecruit = new RealSocialRecruit();   //��ʵ����
		ProxyCompany recruitCompany = new ProxyCompany("�Ͼ������Ƹ���޹�˾"); //����˾
		recruitCompany.setRealSocialRecruit(realSocalRecruit);
		
		//���û�Ϊ�ܲ���ֱ����Ƹ
		HWRecruit  hwRecruit = new HWRecruit();
		HUAWEI.setHwRecruit(hwRecruit);
		//����������
		HWRecruitAdapter hwRecruitAdapter = new HWRecruitAdapter();
		hwRecruitAdapter.setHUAWEI(HUAWEI);
		 
		 //��ʼ��Ƹ����
		 //У԰��Ƹ
		 System.out.println("У�н����"+ campusRecruit1.recruit(studentFile)+'\n');
		 //����
		 System.out.println("���н����"+ recruitCompany.recruit(nostudentFile)+'\n');
		//�ߵ��˲����У�ֱ�ӱ����뻪Ϊ��˾������������
		 System.out.println("�߼��˲����н����"+ hwRecruitAdapter.recruit(professorFile)+'\n');
		//��Ϊ��˾ֱ������
		 System.out.println("��Ϊ��˾ֱ�����˽����"+ HUAWEI.hwRecruit(professor2)+'\n');
		 
		 //���� ��ͨ�˲��߻�Ϊ��˾�ĸ߼��˲�ͨ��
		 System.out.println("��Ϊ��˾ֱ�����˽����"+ hwRecruitAdapter.recruit(studentFile)+'\n');
		 sc.close();
	}

}

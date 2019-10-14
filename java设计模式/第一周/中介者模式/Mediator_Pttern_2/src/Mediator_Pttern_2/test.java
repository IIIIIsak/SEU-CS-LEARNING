package Mediator_Pttern_2;

public class test {

	public test() {
		// TODO �Զ����ɵĹ��캯�����
	}

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		Customer customer = new Customer("�û�");
		SNCompany snCompany = new SNCompany("������˾");
		SHDJCompany shdjCompany = new SHDJCompany("�Ϻ����˾");
		NJDJCompany njdjCompany = new NJDJCompany("�Ͼ����˾");
		Engineer engineer = new Engineer("����ʦ");
		
		SNServer snServer = new SNServer();    //�����ͷ�
		SHDJServer shdjServer = new SHDJServer();   //�Ϻ����˾�ͷ�
		NJDJServer njdjServer = new NJDJServer();  //�Ͼ����˾�ͷ�
		
		//�����н���
		snCompany.setServer(snServer);
		shdjCompany.setServer(shdjServer);
		njdjCompany.setServer(njdjServer);
		engineer.setServer(njdjServer);
		System.out.println("1");
		//���ý����� 
		snServer.addComunicator(customer);
		snServer.addComunicator(snCompany);
		shdjServer.addComunicator(customer);
		shdjServer.addComunicator(shdjCompany);
		njdjServer.addComunicator(customer);
		njdjServer.addComunicator(njdjCompany);
		njdjServer.addComunicator(engineer);
		
		//����
		customer.setServer(snServer);
		customer.ask("���ϴ���������Ĵ��˾�Ŀյ���װ��������ô��", "������˾");
		snCompany.replay("����������˾�������ۺ�����ϵ�Ϻ����˾�ͷ�", "�û�");
		
		customer.setServer(shdjServer);
		customer.ask("���ϴ���������Ĺ�˾�Ŀյ���װ��������ô��,����ƽ̨���������Ϻ����˾�Ŀͷ�", "�Ϻ����˾");
		shdjCompany.replay("����������ز��ţ�����Ŀյ������ݴ�𹤳������ģ�����ϵ�Ͼ����˾�ͷ�", "�û�");
		
		customer.setServer(njdjServer);
		customer.ask("���ϴ���������Ĺ�˾�Ŀյ���װ�����⣬�������Ϻ����˾�ͷ��������������Ͼ����˾�����Լ�����һ���û��ֲ���д����һ������������ʵ����ȷû��", "�Ͼ����˾");
		njdjCompany.replay("����ѯ������ز���,�յ�����û����������", "�û�");
		customer.ask("�����û��ֲ���˵���еģ���Ӧ�������ǵ�����", "�Ͼ����˾");
		njdjCompany.replay("����յ����������ͣ���ˣ�������һ������ʦ�����ȥ������", "�û�");
		
		njdjCompany.replay("ȥ�û�������һ�¿յ�", "����ʦ");
	}
}

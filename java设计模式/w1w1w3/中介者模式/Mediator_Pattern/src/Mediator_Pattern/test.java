package Mediator_Pattern;

public class test {


	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		CustomerServer server = new CustomerServer();

		Customer customer = new Customer(server);
		Company company = new Company(server);
		server.setCompany(company);
		server.setCustomer(customer);
		customer.ask("����ĵ����ò���");
		company.answer("�ѵ�Դ���Ͼ�������");
	}

}


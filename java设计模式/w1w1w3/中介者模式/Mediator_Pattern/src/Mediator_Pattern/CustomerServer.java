package Mediator_Pattern;

public class CustomerServer extends Server {
	private Customer customer;
	public void setCustomer(Customer customer) {
		this.customer = customer;
	}


	public void setCompany(Company company) {
		this.company = company;
	}


	private Company company;


	@Override
	public void communicate(String message, Comunicator c) {
		// TODO �Զ����ɵķ������
		if (c==this.customer) {
			company.getMessage(message);
		}else if(c ==this.company) {
			customer.getMessage(message);
		}
	}

}

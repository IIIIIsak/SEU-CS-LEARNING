package Stage_pattern;

public class OurSystem {
	//ϵͳ �ͻ�����
	Encryptor encryptor;
	public void setEncryptor(Encryptor encryptor) {
		this.encryptor = encryptor;
	}
	String target;
	public OurSystem(Encryptor e) {
		this.encryptor = e ;
	}
	public void encryptUserPW( String orignal){
		this.target = this.encryptor.encrypt(orignal);
	}
}



package Stage_pattern;

public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		//���ɼ�����
		CaesarDESEncryptor encryptor1= new CaesarDESEncryptor();
		DESEncryptor encryptor2 = new DESEncryptor();
		
		OurSystem s = new OurSystem(encryptor1);
		s.encryptUserPW("123456");
		s.setEncryptor(encryptor2);
		s.encryptUserPW("123456");
	}

}



package Composite_Pattern_2;

public class AntiVirus {
	AntiComponent anti;
	public void setAnti(AntiComponent anti) {
		this.anti = anti;
	}
	public AntiVirus(AntiComponent a){
		this.anti = a;
	}
	public void scanVirus() {
		System.out.println("��ʼ���в���ɨ�裡\n");
		this.anti.scan();
	}
}

package Composite_Pattern_2;

import java.util.ArrayList;

public class FolderScan extends AntiComponent {
	ArrayList<AntiComponent> antis = new ArrayList<AntiComponent>();
	
	public  void add(AntiComponent c) {
		antis.add(c);
	}
	public void remove(AntiComponent c) {
		antis.remove(c);
	}
	public AntiComponent findChild(int index) {
		return antis.get(index);
	}
	@Override
	public void scan() {
		// TODO �Զ����ɵķ������
		System.out.println("��ʼɨ���ļ���");
		for(AntiComponent a: antis) {
			a.scan();
		}
	}

}

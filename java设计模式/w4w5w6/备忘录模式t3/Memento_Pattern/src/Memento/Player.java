package Memento;

public class Player {
	private String gameState;
	public Player() {
		// TODO �Զ����ɵĹ��캯�����
		this.gameState="��Ϸ��ʼ";
	}
	public GameMemento saveGame() {
		return new GameMemento(this.gameState);
	}
	public void restartGame(GameMemento gm) {
		this.gameState = gm.getGameState();
	}
	
	
	public void play(String gameState) {
		//�ı���Ϸ״̬�ĺ�����play �ȽϷ��ϳ���
		this.gameState = gameState;
	}
	public void printGameState() {
		//����鿴״̬�ĺ���
		System.out.println(this.gameState);
	}
}

package Memento;

public class GameMemento {
	
	private String gameState;
	//����public ���η� Ĭ�ϰ��ڿɼ�
	String getGameState() {
		return gameState;
	}
    void setGameState(String gameState) {
		this.gameState = gameState;
	}
	GameMemento(String gs) {
		// TODO �Զ����ɵĹ��캯�����
		this.gameState = gs;
	}

}




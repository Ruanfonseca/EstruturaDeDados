package listaEncadeada;

public class Node {
	String word;
	int count;
	Node next;

	public Node(String word, int count) {
		this.word = word;
		this.count = count;
		this.next = null;
	}
}

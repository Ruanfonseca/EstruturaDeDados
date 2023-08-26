package listaEncadeada;

public class listaEncadeada {
	Node head;

	public listaEncadeada() {
		head = null;
	}

	public void insert(String word, int count) {
		Node newNode = new Node(word, count);
		newNode.next = head;
		head = newNode;
	}

	public Node search(String word) {
		Node current = head;
		int aux = 0;
		String palavra;
		while (current != null) {
			if (current.word.equals(word)) {
				aux++;
			}
			current = current.next;
		}
		if(aux!=0)
		   aux = aux - 1;
		System.out.println("A Palavra : " + word + " tem "+ aux +" ocorrencias no arquivo ");
		return null;
	}

	public void printList() {
		Node current = head;
		while (current != null) {
			System.out.println(current.word + ": " + current.count);
			current = current.next;
		}
	}

	
	 public String[] getWords() {
	        // Conta o número de palavras na lista
	        int count = 0;
	        Node current = head;
	        while (current != null) {
	            count++;
	            current = current.next;
	        }

	        // Cria um array de palavras
	        String[] words = new String[count];

	        // Preenche o array com as palavras da lista
	        current = head;
	        int i = 0;
	        while (current != null) {
	            words[i] = current.word;
	            i++;
	            current = current.next;
	        }

	        return words;
	    }
	/*****************************************************************************/
	public void quickSort() {
		head = quickSortRecursive(head, null);
	}

	private Node quickSortRecursive(Node start, Node end) {
		// caso base: lista vazia ou com um elemento
		if (start == end || start.next == end) {
			return start;
		}

		Node pivot = start;
		Node current = start.next;
		Node previous = start;

		while (current != end) {
			if (current.word.compareTo(pivot.word) < 0) {
				// move o nó atual para o início da lista
				previous.next = current.next;
				current.next = start;
				start = current;
				current = previous.next;
			} else {
				// avança para o próximo nó
				previous = current;
				current = current.next;
			}
		}

		// divide a lista em duas partes e as ordena recursivamente
		start = quickSortRecursive(start, pivot);
		pivot.next = quickSortRecursive(pivot.next, end);

		return start;
	}

	
	 /*
	 public static void quickSort(String[] words, int left, int right) {
	        if (left < right) {
	            int pivotIndex = partition(words, left, right);
	            quickSort(words, left, pivotIndex);
	            quickSort(words, pivotIndex + 1, right);
	        }
	    }

	    private static int partition(String[] words, int left, int right) {
	        String pivot = words[right];
	        int i = left - 1;
	        for (int j = left; j < right; j++) {
	            if (words[j].compareTo(pivot) < 0) {
	                i++;
	                String temp = words[i];
	                words[i] = words[j];
	                words[j] = temp;
	            }
	        }
	        String temp = words[i + 1];
	        words[i + 1] = words[right];
	        words[right] = temp;
	        return i + 1;
	    }
*/
	/*****************************************************************************/
	public void quickSort2() {
		head = quickSortRecursive2(head, null);
	}

	private Node quickSortRecursive2(Node start, Node end) {
		// caso base: lista vazia ou com um elemento
		if (start == end || start.next == end) {
			return start;
		}

		Node pivot = start;
		Node current = start.next;
		Node previous = start;

		while (current != end) {
			if (current.count < pivot.count) {
				// move o nó atual para o início da lista
				previous.next = current.next;
				current.next = start;
				start = current;
				current = previous.next;
			} else {
				// avança para o próximo nó
				previous = current;
				current = current.next;
			}
		}

		// divide a lista em duas partes e as ordena recursivamente
		start = quickSortRecursive2(start, pivot);
		pivot.next = quickSortRecursive2(pivot.next, end);

		return start;
	}

}

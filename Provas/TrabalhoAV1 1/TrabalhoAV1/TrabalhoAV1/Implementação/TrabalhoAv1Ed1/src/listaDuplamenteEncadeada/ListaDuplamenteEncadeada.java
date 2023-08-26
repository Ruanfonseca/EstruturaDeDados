package listaDuplamenteEncadeada;

public class ListaDuplamenteEncadeada {
	Node primeiro;
	Node ultimo;

	public void adicionarNoInicio(String palavra, int valor) {
		Node novoNo = new Node(palavra, valor, null, primeiro);
		if (primeiro == null) {
			ultimo = novoNo;
		} else {
			primeiro.anterior = novoNo;
		}
		primeiro = novoNo;
	}
	public int contarPalavras() {
	    int contagem = 0;
	    Node atual = primeiro;
	    while (atual != null) {
	        if (atual.palavra != null && !atual.palavra.isEmpty()) {
	            contagem++;
	        }
	        atual = atual.proximo;
	    }
	    return contagem;
	}
	
	
	public void mostrarLista() {
		Node atual = primeiro;
	    int qtd = 0;
	    while (atual != null) {
          System.out.println(atual.palavra + ": " + atual.valor);
	        atual = atual.proximo;
	    }
	}
	
	public Node pesquisarPalavra(String palavra) {
	    Node atual = primeiro;
	    int qtd = 0;
	    while (atual != null) {
	        if (atual.palavra != null && atual.palavra.equalsIgnoreCase(palavra)) {
	            qtd++;
	        }
	        atual = atual.proximo;
	    }
	      if(qtd!=0)
	         qtd = qtd - 1;
		System.out.println("A Palavra : " + palavra + " tem "+ qtd +" ocorrencias no arquivo ");
	    return null;
	}

	public void adicionarNoFinal(String palavra, int valor) {
		Node novoNo = new Node(palavra, valor, ultimo, null);
		if (ultimo == null) {
			primeiro = novoNo;
		} else {
			ultimo.proximo = novoNo;
		}
		ultimo = novoNo;
	}

	public void removerDoInicio() {
		if (primeiro != null) {
			primeiro = primeiro.proximo;
			if (primeiro == null) {
				ultimo = null;
			} else {
				primeiro.anterior = null;
			}
		}
	}

	public void removerDoFinal() {
		if (ultimo != null) {
			ultimo = ultimo.anterior;
			if (ultimo == null) {
				primeiro = null;
			} else {
				ultimo.proximo = null;
			}
		}
	}

	public void ordenarPorValor() {
		// Verifica se a lista possui pelo menos dois nós
		if (primeiro != null && primeiro.proximo != null) {
			quickSort(primeiro, ultimo);
		}
	}

	private void quickSort(Node inicio, Node fim) {
		if  (inicio != null && fim != null && inicio != fim && inicio != fim.proximo){
			Node pivo = particionar(inicio, fim);
			quickSort(inicio, pivo.anterior);
			quickSort(pivo.proximo, fim);
		}
	}

	private Node particionar(Node inicio, Node fim) {
		int valorPivo = fim.valor;
		Node i = inicio.anterior;
		for (Node j = inicio; j != fim; j = j.proximo) {
			if (j.valor < valorPivo) {
				i = (i == null) ? inicio : i.proximo;
				int valor = i.valor;
				String palavra = i.palavra;
				i.valor = j.valor;
				i.palavra = j.palavra;
				j.valor = valor;
				j.palavra = palavra;
			}
		}
		i = (i == null) ? inicio : i.proximo;
		int valor = i.valor;
		String palavra = i.palavra;
		i.valor = fim.valor;
		i.palavra = fim.palavra;
		fim.valor = valor;
		fim.palavra = palavra;
		return i;
	}

	public void ordenarPorOrdemAlfabetica() {
		// Verifica se a lista possui pelo menos dois nós
		if (primeiro != null && primeiro.proximo != null) {
			quickSort2(primeiro, ultimo);
		}
	}

	private void quickSort2(Node inicio, Node fim) {
		if (fim == null) {
			// A lista possui apenas um elemento ou está vazia, não precisa fazer nada
			return;
		}
		if (inicio != fim && inicio != fim.proximo) {
			Node pivo = particionar2(inicio, fim);
			quickSort2(inicio, pivo.anterior);
			quickSort2(pivo.proximo, fim);
		}
	}

	private Node particionar2(Node inicio, Node fim) {
		if (inicio == null) {
			// A lista possui apenas um elemento ou está vazia, não tem o que particionar
			return null;
		}
		String palavraPivo = fim.palavra;
		Node i = inicio.anterior;
		for (Node j = inicio; j != fim; j = j.proximo) {
			if (j.palavra.compareTo(palavraPivo) < 0) {
				i = (i == null) ? inicio : i.proximo;
				int valor = i.valor;
				String palavra = i.palavra;
				i.valor = j.valor;
				i.palavra = j.palavra;
				j.valor = valor;
				j.palavra = palavra;
			}
		}
		i = (i == null) ? inicio : i.proximo;
		int valor = i.valor;
		String palavra = i.palavra;
		i.valor = fim.valor;
		i.palavra = fim.palavra;
		fim.valor = valor;
		fim.palavra = palavra;
		return i;
	}
}

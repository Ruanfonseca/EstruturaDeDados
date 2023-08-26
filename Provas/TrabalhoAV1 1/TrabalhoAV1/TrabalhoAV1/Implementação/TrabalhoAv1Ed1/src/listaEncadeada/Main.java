package listaEncadeada;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		listaEncadeada list = new listaEncadeada();
		File file = new File(
				"C:\\Users\\Ruan\\eclipse-workspace\\TrabalhoAv1\\src\\listaDuplamenteEncadeada\\ListadePalavras.txt");

		BufferedReader reader = null;

		int qtd = 0;

		try {
			reader = new BufferedReader(new FileReader(file));
			String line;

			while ((line = reader.readLine()) != null) {

				list.insert(line, 0);

			}
		} catch (IOException e) {

			e.printStackTrace();
		} finally {

			try {
				if (reader != null) {
					reader.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		
		}
		countWords(
				"C:\\Users\\Ruan\\eclipse-workspace\\TrabalhoAv1\\src\\listaDuplamenteEncadeada\\ListadePalavras.txt",
				list);

		Menu(list);
	}

	public static void Menu(listaEncadeada list) {
		Double op;
		String opcao;
		Scanner input2 = new Scanner(System.in);
		String palavraEscolhida;
		Scanner input = new Scanner(System.in);

		System.out.println("Escolha uma opcao abaixo : ");
		System.out.println("Ver Lista [1] ");
		System.out.println("Pesquisar na Lista [2] ");
		System.out.println("Sair [0] : ");
		opcao = input.nextLine();

		if (opcao.equals("1")) {
			verLista(list);
		} else if (opcao.equals("2")) {
			System.out.println("Digite a palavra : ");
			palavraEscolhida = input2.nextLine();
			pesquisarPalavra(palavraEscolhida, list);
		}else if(opcao.equals("3")) {
			System.exit(0);
		}

	}

	/***********************************************************************************************************/
	public static void verLista(listaEncadeada list) {
		
		System.out.println("*****************Ordenada por Ordem Alfabetica *************************");
		list.quickSort();
		list.printList();
		System.out.println("*******************Ordenada por Ordem Quantidade Crescente ***********************");
		list.quickSort2();
		list.printList();

		System.out.println("Voltando para funcao principal\n");
		Menu(list);

	}

	public static void countWords(String filename, listaEncadeada list) {
		Map<String, Integer> wordCounts = new HashMap<>();

		// Inicializa o mapa com as palavras da lista e contagens iniciais de 0
		for (String word : list.getWords()) {
			wordCounts.put(word, 0);
		}

		File file = new File(filename);
		BufferedReader reader = null;

		try {
			reader = new BufferedReader(new FileReader(file));
			String line;

			while ((line = reader.readLine()) != null) {
				String[] words = line.split(" ");
				for (String word : words) {
					if (wordCounts.containsKey(word)) {
						int count = wordCounts.get(word);
						wordCounts.put(word, count + 1);
					}
				}
			}

			// Imprime as contagens de palavras
			for (Map.Entry<String, Integer> entry : wordCounts.entrySet()) {
				list.insert(entry.getKey(), entry.getValue());
				// System.out.println(entry.getKey() + ": " + entry.getValue());
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (reader != null) {
					reader.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	public static void pesquisarPalavra(String nome, listaEncadeada list) {

		list.search(nome);
		System.out.println("Voltando para funcao principal\n");
		Menu(list);

	}

}

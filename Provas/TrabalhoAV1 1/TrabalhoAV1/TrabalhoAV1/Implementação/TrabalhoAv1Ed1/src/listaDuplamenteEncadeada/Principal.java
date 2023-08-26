package listaDuplamenteEncadeada;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import listaEncadeada.listaEncadeada;

public class Principal {
	public static void main(String[] args) {
		ListaDuplamenteEncadeada lista = new ListaDuplamenteEncadeada();
		File file = new File(
				"C:\\Users\\Ruan\\eclipse-workspace\\TrabalhoAv1\\src\\listaDuplamenteEncadeada\\ListadePalavras.txt");

		BufferedReader reader = null;

		int qtd = 0;

		try {
			reader = new BufferedReader(new FileReader(file));
			String line;

			while ((line = reader.readLine()) != null) {

				lista.adicionarNoInicio(line, 0);

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
				lista);

		menu(lista);
		/************************************************************************************************/
	}

	public static void menu(ListaDuplamenteEncadeada lista) {
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
			verLista(lista);
		} else if (opcao.equals("2")) {
			System.out.println("Digite a palavra : ");
			palavraEscolhida = input2.nextLine();
			pesquisarPalavra(palavraEscolhida, lista);
		}else if(opcao.equals("3")) {
			System.exit(0);
		}


	
	
	}
	public static void pesquisarPalavra(String nome,ListaDuplamenteEncadeada lista) {

		lista.pesquisarPalavra(nome);
		System.out.println("Voltando para funcao principal\n");
		menu(lista);

	}

public static void verLista(ListaDuplamenteEncadeada lista) {
		
		System.out.println("*****************Ordenada por Ordem Alfabetica *************************");
		lista.ordenarPorOrdemAlfabetica();
		lista.mostrarLista();
		System.out.println("*******************Ordenada por Ordem Quantidade Crescente ***********************");
		lista.ordenarPorValor();
		lista.mostrarLista();

		System.out.println("Voltando para funcao principal\n");
		menu(lista);

	}



	public static void countWords(String filename, ListaDuplamenteEncadeada lista) {
	    Map<String, Integer> wordCounts = new HashMap<>();

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
	                } else {
	                    wordCounts.put(word, 1);
	                }
	            }
	        }

	        // Adiciona as contagens de palavras na lista duplamente encadeada
	        for (Map.Entry<String, Integer> entry : wordCounts.entrySet()) {
	            lista.adicionarNoInicio(entry.getKey(), entry.getValue());
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
}
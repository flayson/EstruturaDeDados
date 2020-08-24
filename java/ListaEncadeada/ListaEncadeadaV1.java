
public class ListaEncadeadaV1 {

	private No primeiroNo;
	// private No noAnterior;

	public boolean isEmpty() {
		return primeiroNo == null;
	}

	public void inserirInicio(Integer valor) {
		No novoNo = new No(primeiroNo, valor);
		novoNo.setProximo(primeiroNo);
		primeiroNo = novoNo;
	}

	public void inserirFim(Integer valor) {
		No novoNo = new No(primeiroNo, valor);
		novoNo.setProximo(null);
		if (isEmpty()) {
			primeiroNo = novoNo;
		} else {
			No ultimoNo = primeiroNo;
			while (ultimoNo.getProximo() != null) {
				ultimoNo = ultimoNo.getProximo();
			}
			ultimoNo.setProximo(novoNo);
		}
	}

	public void listarLista() {
		No listaTemporaria = primeiroNo;
		int i = 0;
		if(isEmpty()) {
			System.out.print("Lista Vazia!\n");
			return;
		}
		while (listaTemporaria != null) {
			System.out.print(i++ + " - " + listaTemporaria.getElemento() + "\n");
			listaTemporaria = listaTemporaria.getProximo();
		}
	}

	public int buscarPos(Object elemento) {
		No atualNo = primeiroNo;
		int i = 0;
		while (atualNo != null && atualNo.getElemento() != elemento) {
			atualNo = atualNo.getProximo();
			i++;
		}

		if (atualNo != null) {
			return i;
		}

		return -1;
	}

	public void removerNo(Object elemento) {
		No noAtual = primeiroNo;
		No noAnterior = null;
		while (noAtual != null && noAtual.getElemento() != elemento) {
			noAnterior = noAtual;
			noAtual = noAtual.getProximo();
		}

		if (noAtual == null) {
			return; // nó não encontrado.
		}

		if (noAnterior == null) { // significa que é o primeiro da lista.
			primeiroNo = noAtual.getProximo();
		} else { // caso contrário remove um elemento do meio da lista
			noAnterior.setProximo(noAtual.getProximo());
		}
	}

}

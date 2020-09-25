
public class ListaEncadeadaV2 {

	private No primeiroNo;
	private No ultimoNo;

	public boolean isEmpty() {
		return primeiroNo == null;
	}

	public void inserirInicio(Integer valor) {
		No novoNo = new No(primeiroNo, valor);
		novoNo.setProximo(primeiroNo);
		if (isEmpty()) {
			ultimoNo = primeiroNo;
		} else {
			novoNo.setProximo(primeiroNo);
		}

		primeiroNo = novoNo;

	}

	public void inserirFim(Object elemento) {
		No novoNo = new No(primeiroNo, null, elemento);
		//novoNo.setProximo(null);

		if (isEmpty()) {
			primeiroNo = novoNo;
		} else {
			No atualAnterior = primeiroNo;
			while (atualAnterior.getProximo() != null) {
				atualAnterior = atualAnterior.getProximo();
			}
			
			ultimoNo = novoNo;
			atualAnterior.setProximo(ultimoNo);
			novoNo.setAnterior(atualAnterior);
		}
	}

	public void listarLista() {
		No listaTemporaria = primeiroNo;
		int i = 0;
		if (isEmpty()) {
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
		if (!isEmpty()) {
			if (primeiroNo.getElemento() == elemento) {
				removerInico();
				return;
			}

			if (ultimoNo.getElemento() == elemento) {
				removerFim();
				return;
			}

			No noAtual = primeiroNo;
			No noAnteriorTemp = null;

			noAnteriorTemp = primeiroNo;
			noAtual = primeiroNo.getProximo();

			while (noAtual.getProximo() != null) {
				if (noAtual.getElemento() == elemento) {
					noAnteriorTemp.setProximo(noAtual.getProximo());
				}
				noAtual = noAtual.getProximo();
				noAnteriorTemp = noAnteriorTemp.getProximo();
			}
		}
	}

	public void removerFim() {
		if (!isEmpty()) {

			if (primeiroNo.getProximo() == null) {
				removerInico();
				return;
			}
			No primeiroNoTemp = primeiroNo;
			while (primeiroNoTemp.getProximo().getProximo() != null) {
				primeiroNoTemp = primeiroNoTemp.getProximo();
			}

			ultimoNo = primeiroNoTemp;
			ultimoNo.setProximo(null);

		}
	}

	public void removerInico() {
		if (!isEmpty())
			primeiroNo = primeiroNo.getProximo();
	}
}

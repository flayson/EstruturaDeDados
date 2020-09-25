
public class No {

	private No proximo;
	private No anterior;
	private Object elemento;

	public No(No proximo, No anterior, Object elemento) {
		this.proximo = proximo;
		this.anterior = anterior;
		this.elemento = elemento;
	}

	public No(Object elemento) {
		this.proximo = null;
		this.elemento = elemento;
	}

	public No getProximo() {
		return proximo;
	}

	public void setProximo(No proximo) {
		this.proximo = proximo;
	}

	public Object getElemento() {
		return elemento;
	}

	public void setElemento(Object elemento) {
		this.elemento = elemento;
	}

	@Override
	public String toString() {
		return String.format("%s", this.elemento);
	}
}


public class App {
   public static void main(String args[]) {
	   ListaEncadeadaV2 listaEncadeada = new ListaEncadeadaV2();
	   listaEncadeada.listarLista();
	   listaEncadeada.inserirFim(10);
	   listaEncadeada.inserirFim(5);
	   listaEncadeada.listarLista();
	   System.out.println("");
	   listaEncadeada.inserirInicio(7);
	   listaEncadeada.listarLista();
	   System.out.println("\n" +listaEncadeada.buscarPos(10));
	   
	   System.out.println("");
	   listaEncadeada.removerNo(5);
	   listaEncadeada.listarLista();
	   System.out.println("");
	   listaEncadeada.removerNo(7);
	   listaEncadeada.listarLista();
	   System.out.println("");
	   listaEncadeada.removerNo(10);
	   listaEncadeada.listarLista();
   }
}

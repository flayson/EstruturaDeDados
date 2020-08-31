public class BuscaOrdena {
	public static void main(String[] args) {
		int v[] = {5, 3, 1, 9, -2, 3};
		
		System.out.println("Pos: " + busca(v, 9));
		
		for(int x = 0; x<v.length; x++) {
			System.out.print(v[x] + "; ");
		}
		
		ordena(v);

		
		for(int x = 0; x<v.length; x++) {
			System.out.print(v[x] + "; ");
		}
		
		System.out.println("Pos: " + busca(v, 9));
	}
	
	public static void ordena(int v[]) {
		
		int temp;
		
		for(int x = 0; x<v.length; x++) {
			for(int y=0;y<x; y++) {
				if(v[x] < v[y]) {
					temp = v[x];
					v[x] = v[y];
					v[y] = temp;
				}
			}
		}
	}
	
	public static int busca(int v[], int valor) {
		for(int x = 0; x<v.length; x++) {
			
				if(v[x] == valor) {
					return x;
				}
		}
		return -1;
	}
}
 

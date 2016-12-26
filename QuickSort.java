import java.util.Random;

public class Quick {
	
	private static void Shuffle(int[] a){
		Random rand = new Random();
		for(int i=1;i<a.length;i++){
			int j = rand.nextInt(i);
			exchange(a, i, j);
		}
	}
	
	public static void sort(int[] a){
		Shuffle(a);
		sort(a,0,a.length - 1);
	}

	public static void sort(int[] a, int lo, int hi) {
		if(hi <= lo) return;
		int j = partition(a,lo,hi);
		sort(a,lo,j-1);
		sort(a,j+1,hi);
	}

	private static int partition(int[] a, int lo, int hi) {
		int i = lo, j = hi+1;
		while(true){
			while(less(a[++i], a[lo]))
				if(i == hi)
					break;
			while(less(a[lo], a[--j]))
				if(j == lo)
					break;
			if(i>=j)
				break;
			exchange(a, i, j);
		}
		exchange(a, lo, j);
		return j;
	}

	private static boolean less(int a, int b) {
		return (a - b < 0);
	}

	private static void exchange(int[] a, int i, int j) {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
	}
	
}

package Adapter_parttern_2;

public class AdapterDataOperation implements DataOperation {
	QuickSort quickSort;
	public void setQuickSort(QuickSort quickSort) {
		this.quickSort = quickSort;
	}
	public void setBinarySearch(BinarySearch binarySearch) {
		this.binarySearch = binarySearch;
	}

	BinarySearch binarySearch;
	AdapterDataOperation(QuickSort qs, BinarySearch bs){
		this.quickSort = qs;
		this.binarySearch = bs;
	}
	@Override
	public void sort(int[] array) {
		// TODO �Զ����ɵķ������
		this.quickSort.quickSort(array);
	}

	@Override
	public int search(int[] array, int value) {
		// TODO �Զ����ɵķ������
		return this.binarySearch.binarySearch(array, value);
	}

}

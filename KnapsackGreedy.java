public class Main {
    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        int n,C,k;
        float contains;
        C = 400;
        n  = 100;
        Goods[] list = new Goods[n];
        float[] answer = new float[n];
        for(k = 0;k < n;k++){
            list[k] = new Goods();
            float weight = (float)(Math.random()*88) + 1;
            list[k].setWeight(weight);
            float value = (float)(Math.random()*40) + 1;
            list[k].setValue(value);
            float p_value = value / weight;
            list[k].setP_value(p_value);
        }
        MergeSort mergeSort = new MergeSort();
        mergeSort.mergeSort(list,0,n - 1);
        contains = C;
        for(k = n - 1;k >= 0;k--) {
            if (contains >= list[k].getWeight()) {
                answer[k] = 1;
                contains -= list[k].getWeight();
            } else {
                break;
            }
        }
        if(contains != 0 && k >= 0){
            answer[k] = contains / list[k].getWeight();
        }
        long endTime = System.currentTimeMillis();
        long runTime = endTime - startTime;
        System.out.println("当前程序耗时："+runTime+"ms");
    }
}

class MergeSort {
    public void mergeSort(Goods[] list,int first,int last){
        int middle;
        if(first < last){ //利用递归的方式实现归并排序，该问题主要时间开销花费在子序列的合并，划分过程并未占用时间开销
            middle = (first + last)/2;
            mergeSort(list,first,middle);
            mergeSort(list,middle + 1,last);
            Merge(list,first,middle,middle + 1,last);
        }
    }
    public void Merge(Goods[] list,int start1,int end1,int start2,int end2){
        int p = start1;
        int n = start2;
        int count = 0;
        Goods[] C= new Goods[end2 - start1 + 1];
        while(p <= end1 && n <= end2){
            if(list[p].getP_value() <= list[n].getP_value()){
                C[count] = list[p];
                p++;
            }
            else{
                C[count] = list[n];
                n++;
            }
            count++;
        } //若存在一个子序列已经完全排序完另一个子序列未完全排序完成，仅需将剩余部分依次进行存储即可，无需比较
        while(p <= end1){
            C[count] = list[p];
            p++;
            count++;
        }
        while(n <= end2){
            C[count] = list[n];
            n++;
            count++;
        }
        count = 0;
        for(p = start1;p <= end2;p++){
            list[p] = C[count];
            count++;
        }
    }
}

class Goods {
    private float weight;
    private float value;
    private float p_value;
    public void setWeight(float weight){
        this.weight = weight;
    }
    public void setValue(float value){
        this.value = value;
    }
    public void setP_value(float p_value){
        this.p_value = p_value;
    }

    public float getP_value(){
        return this.p_value;
    }
    public float getWeight(){
        return this.weight;
    }
    public float getValue(){
        return this.value;
    }
}



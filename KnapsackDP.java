public class KnapsackDP {
    public static void main(String[] args) {
	// write your code here
        long startTime = System.currentTimeMillis();
        int n,C,k,answer;
        C = 2000;
        n = 100;
        int[] weight = new int[n];
        int[] value = new int[n];
        for(k = 0;k < n;k++){
            weight[k] = 1 + (int)(Math.random()*20);
            value[k] = 1 + (int)(Math.random()*50);
        }
        knpsackDP knpsackdp = new knpsackDP();
        answer = knpsackdp.KnapscakDP(weight,value,C,n);
        System.out.println(answer);
        long endTime = System.currentTimeMillis();
        long runTime = endTime - startTime;
        System.out.println("当前程序耗时："+runTime+"ms");
    }
}

class knpsackDP {
    int KnapscakDP(int[] weight,int[] value,int C,int n){
        int i,j;
        int[][] dp = new int[n + 1][C + 1];
        for(i = 0;i <= n;i++){
            dp[i][0] = 0;
        }
        for(j = 0;j <= C;j++){
            dp[0][j] = 0;
        }
        for(i = 1;i <= n;i++){
            for(j = 1;j <= C;j++){
                dp[i][j] = dp[i - 1][j];
                if(weight[i - 1] <= j){
                    if(dp[i][j] <= dp[i - 1][j - weight[i - 1]] + value[i - 1]){
                        dp[i][j] = dp[i - 1][j - weight[i - 1]] + value[i - 1];
                    }
                }
            }
        }
        return dp[n][C];
    }
}


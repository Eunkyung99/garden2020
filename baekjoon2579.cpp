/*
 ��� ������ ������ ��� �Ʒ� ���������� ��� ����⿡ ��ġ�� ���������� ���� �����̴�. <�׸� 1>�� ���� ������ ��ܿ��� ������ ������ ���� �ִµ� ����� ������ �� ��ܿ� ���� �ִ� ������ ��� �ȴ�.
 ��� ������ ���� ������ ���� ��Ģ�� �ִ�.

����� �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�. ��, �� ����� �����鼭 �̾ ���� ����̳�, ���� ���� ������� ���� �� �ִ�.
���ӵ� �� ���� ����� ��� ��Ƽ��� �� �ȴ�. ��, �������� ��ܿ� ���Ե��� �ʴ´�.
������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.
���� ù ��° ����� ��� �̾� �� ��° ����̳�, �� ��° ������� ���� �� �ִ�. ������, ù ��° ����� ��� �̾� �� ��° ������� �ö󰡰ų�, ù ��°, �� ��°, �� ��° ����� �����ؼ� ��� ���� ���� ����.

�� ��ܿ� ���� �ִ� ������ �־��� �� �� ���ӿ��� ���� �� �ִ� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
ù° �ٿ� ��� ������ ���ӿ��� ���� �� �ִ� �� ������ �ִ��� ����Ѵ�.
 */
#include <iostream>
using namespace std;
int max(int a, int b){
	return (a>b)?a:b;
}
int main(){
	int n;
	int stair[10000]={0,};
	int dp[10000][2]={0,}; //2���� �迭 ���(���� ���� ����� �� ĭ �Ʒ�(1)���� ��ĭ �Ʒ�(0)���� ����)
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>stair[i]; //��� �Է�
	}
	dp[1][1]=dp[1][0]=stair[1]; //ù��° ��ܱ����� �ִ�����=ù��° ��� ���
	dp[2][0]=stair[2]; //�ι�° ��ܱ����� �ִ�����(�� ĭ �Ʒ�(0)�� ���)
	dp[2][1]=stair[1]+stair[2]; //�ι�° ��ܱ����� �ִ� ����(�� ĭ �Ʒ�(1)�� ���)
	for(int i=3; i<=n; i++){ //n���� dp ���ϱ�
		dp[i][0]=stair[i]+max(dp[i-2][0], dp[i-2][1]); //i��° ����� ��� �� i-2��° ����� ����(i-2������ �ִ��� dp[i-2] �̿��Ͽ� �ظ� ����)
													   //�̶��� i-2�� ���� i-3�� ��Ҵ� i-4�� ��Ҵ� ��� �����Ƿ� �� �� �� ū ���� ������
		dp[i][1]=stair[i]+dp[i-1][0]; //i��° ����� ��� �� i-1��° ����� ����
								 	  //�̶��� i-1�� i�� �����Ƿ� i-2�� ���� ���� �����ؾ� �� ���� dp[i-1][0]�� i-3->i-1->i�� ��츸 ���� ������
	}
	cout<<max(dp[n][0], dp[n][1])<<endl; //dp[n]�� ����� ���� �� �ִ� ���
	return 0;
}
//����ð�:O(n)
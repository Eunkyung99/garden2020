/*
 ������ ���� ���� �ڸ��� ���������� �̷�� ���� ���Ѵ�. �̶�, ������ ���� ���Ƶ� ������������ ģ��.

���� ���, 2234�� 3678, 11119�� ������ ��������, 2232, 3676, 91111�� ������ ���� �ƴϴ�.

���� ���� N�� �־����� ��, ������ ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� 0���� ������ �� �ִ�.
ù° �ٿ� ���̰� N�� ������ ���� ������ 10,007�� ���� �������� ����Ѵ�.
 */
#include <iostream>
using namespace std;
int main(){
	int n, answer=0;
	int array[10]={1,}; //1�� �ʱ�ȭ
	cin>>n;
	for(int i=0; i<n; i++){ //n�� �ݺ�
		for(int j=1; j<10; j++){ //�����ڸ����ڰ� j�� ���� ����
			array[j]=(array[j-1]+array[j])%10007; //10007�� ���� ������
		}
	}
	for(int i=0; i<10; i++)
		answer+=array[i];
	cout<<answer%10007; //���� �䵵 10007�� ���� ������!!!!
	return 0;
}
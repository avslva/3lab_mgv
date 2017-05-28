#include "functions.h"
// ������� - ������, ������ - �������
int main()
{
	setlocale(LC_ALL, "rus");
	const int vert_num = 4;
	int** graph = new int*[vert_num];
	int* result_str = new int[vert_num];
	int* result_raw = new int[vert_num];
	int* min_fi = new int[vert_num];
	int resMass[vert_num], resMassInd = 0;

	for (int i = 0; i < vert_num; i++)
	{
		graph[i] = new int[vert_num];
		result_str[i] = UNDEF_INT_MAX;
		result_raw[i] = UNDEF_INT_MAX;
	}

	//1
	graph[0][0] = 5;
	graph[0][1] = 6;
	graph[0][2] = 7;
	graph[0][3] = 8;
	//2
	graph[1][0] = 5;
	graph[1][1] = 6;
	graph[1][2] = 7;
	graph[1][3] = 8;
	//3
	graph[2][0] = 5;
	graph[2][1] = 6;
	graph[2][2] = 7;
	graph[2][3] = 8;
	//4
	graph[3][0] = 5;
	graph[3][1] = 6;
	graph[3][2] = 7;
	graph[3][3] = 8;

	printMatrix(graph, vert_num);

	int min[vert_num];	//������, �������� ��� �� ��� ������ ���������

	for (int j = 0; j < vert_num; j++)	//���������
	{
		result_str[j] = 0;	//�������� ������
		for (int i = 0; i < vert_num; i++)	//������
		{
			if (result_raw[i] == UNDEF_INT_MAX)
			{
				result_raw[i] = graph[j][i];
				//��������� �� ������ result_raw[i], ����������� j ������ i �������
				int minS = min_str(graph, result_str, result_raw, vert_num);	// ����� min ��������� �� ���������� �������
				int minR = min_raw(graph, result_str, result_raw, vert_num);	// ����� min ��������� �� ���������� ��������
																				//�������� min �� ���� ����� � ���� ��������
				if (minS < minR)
				{
					min[i] = minS;
				}
				else
				{
					min[i] = minR;
				}
				min[i] += graph[j][i];	//���������� � min ������ �������� ������ ��� ������� ��������� (����� ��)
				result_raw[i] = UNDEF_INT_MAX;
			}
			else
			{
				min[i] = UNDEF_INT_MAX;
			}
		}
		int curr_min = UNDEF_INT_MAX;
		//���� min �� 
		for (int i = 0; i < vert_num; i++)
		{
			if (min[i] < curr_min)
			{
				curr_min = min[i];
				min_fi[j] = i;		//��������� ��� j ��������� ������ ������ i
			}
		}
		result_raw[min_fi[j]] = 0;	//����������� j �������, �� ��� ������ ��� ������
		resMass[resMassInd] = min_fi[j];	//�������� ������ �������� - ������
		resMassInd++;
	}
	printRes(resMass, graph, vert_num);
	return 0;
}
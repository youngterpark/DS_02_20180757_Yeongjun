#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
#define MAX_STD 10
typedef struct Student { //학생 정보
	int no; //학번
	char name[50]; //이름
	char tel[50]; //전화번호
}Std_Info;
int Hash_Function(int key, int Hash_Size) //해시 함수
{
	string key_str = to_string(key);
	int len = key_str.length();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += static_cast<int>(key_str[i]); // 문자의 ASCII 값을 더함
	}
	int hash_addr = sum % Hash_Size;
	return hash_addr;
}

void SInfo_Create(Std_Info* students, const char* file_name, int Hash_Size) //해시 테이블 구성
{
	FILE* file;
	fopen_s(&file, file_name, "r");
	if (file == NULL) {
		printf("파일이 없습니다. 프로그램을 종료합니다.");
		return;
	}
	int i = 0;
	while (1) {
		Std_Info student;
		int result = fscanf_s(file, "%d %49s %49s", &student.no, student.name, sizeof(student.name), student.tel, sizeof(student.tel));
		int hash_addr = Hash_Function(student.no, Hash_Size);
		int index = hash_addr;
		while (students[index].no != -1)
		{
			//if (students[index].no == student.no)
			//{
			//	printf("error: duplicated key");
			//	return;
			//}
			index = (index + 1) % Hash_Size; // 선형 탐사법
			if (index == hash_addr)
			{
				printf("error: hash full");
				return;
			}
		}

		if (students[index].no == -1) {
			students[index] = student;
		}

		if (result == EOF) break;
		i++;
	}
}
int Hash_Search(Std_Info* students, int key, int Hash_Size) //해시 탐색
{
	int hash_addr = Hash_Function(key, Hash_Size);
	int index = hash_addr;
	while (true)
	{
		if (students[index].no == key) return index;
		if (students[index].no == NULL) break;
		index = (index + 1) % Hash_Size;
		if (index == hash_addr) break;
	}
	return -1;
}
int main() {
	Std_Info students[MAX_STD];
	const char* fName = "students_info.txt";
	for (int i = 0; i < MAX_STD; i++) { //students 해시 테이블 초기화
		students[i].no = -1;
		memset(students[i].name, 0, sizeof(students[i].name));
		memset(students[i].tel, 0, sizeof(students[i].tel));
	}
	SInfo_Create(students, fName, MAX_STD);
	printf("%d 위치는 해시 테이블 %d에 존재합니다.\n\n", 218, Hash_Search(students, 218, MAX_STD));
	printf("##해시 테이블##\n");
	for (int i = 0; i < MAX_STD; i++) //students 해시 테이블 출력
		printf("[% 2d]: % d % s % s\n", i, students[i].no, students[i].name, students[i].tel);
	return 0;
}

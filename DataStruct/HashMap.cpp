//
// Created by 17694 on 2020/6/2.
//

#include<iostream>
using namespace std;

#define HASHSIZE 7 // ����ɢ�б�Ϊ����ĳ���
#define NULLKEY -32768

typedef int Status;
typedef struct{
    int *elem; // ����Ԫ�ش洢��ַ����̬��������
    int count; //  ��ǰ����Ԫ�ظ���
}HashTable;

// ɢ�б����ȫ�ֱ���
int m = 0;

void InitHashTable(HashTable *hashTable);
Status Hash(int key);
void Insert(HashTable *hashTable,int key);
Status Search(HashTable *hashTable,int key);
void DisplayHashTable(HashTable *hashTable);

int main(int argc, const char * argv[]) {

    int result;
    HashTable hashTable;
    int arr[HASHSIZE] = {13,29,27,28,26,30,38};

    //��ʼ����ϣ��
    InitHashTable(&hashTable);

    /**
     *  ���ϣ���в�������;
     Ҳ���ǰ�Ԫ��ʹ�ù�ϣ����ӳ�䵽��ϣ���У�
     */
    for (int i = 0;i < HASHSIZE;i++){
        Insert(&hashTable,arr[i]);
    }
    //�����Ѵ浽��ϣ���У���ӡ�۲��ϣ��Ԫ�ص�λ�ú�ԭ��������ȫ��һ����
    DisplayHashTable(&hashTable);
    //��������
    result = Search(&hashTable,30);
    if (result == -1){
        printf("û���ҵ���");
    }else{
        printf("�ڹ�ϣ���е�λ����:%d\n",result);
    }
    return 0;
}

//��ʼ��һ���յĹ�ϣ��
void InitHashTable(HashTable *hashTable){

    m = HASHSIZE;
    hashTable->elem = (int *)malloc(m * sizeof(int)); //�����ڴ�
    hashTable->count = m;
    for(int i = 0;i < m;i++){
        hashTable->elem[i] = NULLKEY;
    }
}

//��ϣ����(����������)
Status Hash(int key){
    return key % m;
}

//����
void Insert(HashTable *hashTable,int key){

    /**
     *  ����ÿһ���ؼ��֣������ϣ��ַhashAddress��
     */
    int hashAddress = Hash(key); //���ϣ��ַ
    /**
     *  ������ͻ����ʾ��λ���Ѿ���������
     */
    while(hashTable->elem[hashAddress] != NULLKEY){
        //���ÿ��Ŷ�ַ������̽�ⷨ�����ͻ
        hashAddress = (hashAddress + 1) % m;
    }
    //����ֵ
    hashTable->elem[hashAddress] = key;
}

//����
Status Search(HashTable *hashTable,int key){
    //���ϣ��ַ
    int hashAddress = Hash(key);
    //������ͻ
    while(hashTable->elem[hashAddress] != key){
        //���ÿ��Ŷ�ַ������̽�ⷨ�����ͻ
        hashAddress = (hashAddress + 1) % m;
        if (hashTable->elem[hashAddress] == NULLKEY || hashAddress == Hash(key)){
            return -1;
        }
    }
    //���ҳɹ�
    return hashAddress;
}

//��ӡ���
void DisplayHashTable(HashTable *hashTable){
    for (int i = 0;i < hashTable->count;i++){
        printf("%d ",hashTable->elem[i]);
    }
    printf("\n");
}

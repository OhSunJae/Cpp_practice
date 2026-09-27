/**
 * @file Day01_LinkedList.cpp
 * @brief CS 기초: C++ 포인터, 동적 할당, 그리고 단일 연결 리스트 구현
 * @note 페이스메이커와 함께한 첫 번째 아웃풋!
 */

#include <iostream>
using namespace std;

// 1. 노드 구조체 (보물상자 비유: 데이터 + 다음 노드를 가리키는 포인터)
struct Node {
    int data;       // 실제 저장할 값
    Node* next;     // 다음 노드의 주소를 가리키는 화살표 (포인터)
    
    // 생성자: 노드가 태어날 때 값을 초기화
    Node(int val) {
        data = val;
        next = nullptr; // 처음엔 다음 주소가 없으므로 nullptr
    }
};

// 2. 연결 리스트 클래스
class LinkedList {
private:
    Node* head;     // 리스트의 맨 처음을 가리키는 포인터 (대장 머리)

public:
    // 생성자: 빈 리스트로 초기화
    LinkedList() {
        head = nullptr;
    }

    // [기능 1] 맨 뒤에 데이터 추가하기 (push_back)
    void push_back(int val) {
        Node* newNode = new Node(val); // 힙(Heap) 메모리에 새 노드 동적 할당
        
        // 만약 리스트가 비어있다면, 첫 번째 노드가 head가 됨
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // 비어있지 않다면, 맨 마지막 노드를 찾아서 끝에 붙임
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // [기능 2] 맨 앞에 데이터 추가하기 (push_front)
    void push_front(int val) {
        Node* newNode = new Node(val); // 1. 새 노드 생성
        newNode->next = head;          // 2. 새 노드가 기존의 head를 가리킴
        head = newNode;                // 3. head를 새 노드로 변경 (새로운 대장 등극)
    }

    // [기능 3] 전체 리스트 출력하기
    void printList() {
        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next; // 다음 노드로 이동
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    cout << "=== CS & Robotics 페이스메이커 Day 1 아웃풋 ===" << endl;
    
    LinkedList list;

    list.push_back(20);  // 리스트 뒤에 20 추가
    list.push_back(30);  // 리스트 뒤에 30 추가
    list.push_front(10); // 리스트 맨 앞에 10 추가

    // 출력 결과: 10 -> 20 -> 30 -> nullptr
    list.printList(); 

    return 0;
}
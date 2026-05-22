/*
 Source: Kalicharan, Advanced Topics in C, p.132 no.13
 */

#include <iostream>
using namespace std;

struct Job {
  int jobnum;
  int priority;
  Job *next;
};

struct PriorityQueue {
  Job *head;
  void init() {
    head = nullptr;
  }
  void addjob(int jobnum, int prio) {
    Job *newjob = new Job;
    newjob->next = nullptr;
    newjob->jobnum = jobnum;
    newjob->priority = prio;
    if(head == nullptr || head->priority < prio) {
      newjob->next = head;
      head = newjob;
      return;
    }
    Job *curr = head;
    while(curr->next != nullptr && curr->next->priority >= prio) {
      curr = curr->next;
    }
    newjob->next = curr->next;
    curr->next = newjob;
  }
  void deletehead() {
    if(head == nullptr) {
      return;
    }
    Job *temp = head;
    head = head->next;
    delete temp;
  }
  void removejob(int jobnum) {
    if(head == nullptr) {
      return;
    }
    if(head->jobnum == jobnum) {
      Job *temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Job *curr = head;
    while(curr->next != nullptr && curr->next->jobnum != jobnum) {
      curr = curr->next;
    }
    if(curr->next != nullptr) {
      Job *temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
    }
  }
};

int main() {
  PriorityQueue pq;
  pq.init();
  pq.addjob(101, 2);   
  pq.addjob(102, 5); 
  pq.addjob(103, 1);
  pq.addjob(104, 5);
  pq.deletehead();
  return 0;
}

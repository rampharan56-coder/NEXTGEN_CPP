#include <iostream>

class Node
{
public:
  int data;
  Node *next;

  Node(int var) : data(var), next(nullptr) {}
};

class SSL
{
private:
  Node *head;

public:
  SSL() : head(nullptr) {};

  // insert at the end
  void addNode(int var)
  {
    Node *newNode = new Node(var);
    if (head == nullptr)
    {
      head = newNode;
      return;
    }
    Node *current = head;
    while (current->next != nullptr)
    {
      current = current->next;
    }
    current->next = newNode;
  }

  // search
  bool search(int var)
  {
    Node *current = head;
    while (current != nullptr)
    {
      if (current->data == var)
        return true;
      current = current->next;
    }
    return false;
  }

  int countNodes()
  {
    int count = 0;
    Node *current = head;

    while (current != nullptr)
    {
      count++;
      current = current->next;
    }
    return count;
  }

  void findMinMax()
  {
    if (head == nullptr)
    {
      std::cout << "List is emply" << std::endl;
      return;
    }
    Node *current = head;
    int min = head->data;
    int max = head->data;

    while (current != nullptr)
    {
      if (current->data < min)
      {
        min = current->data;
      }
      if (current->data > max)
      {
        max = current->data;
      }
      current = current->next;
    }

    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
  }

  int sumAll()
  {
    int sum = 0;
    Node *current = head;
    if (current == nullptr)
    {
      return 0;
    }
    while (current != nullptr)
    {
      sum += current->data;
      current = current->next;
    }
    return sum;
  }

  int countOccurrences(int var)
  {
    int count = 0;
    Node *current = head;
    if (current == nullptr)
    {
      return 1;
    }
    while (current != nullptr)
    {
      if (current->data == var)
      {
        count++;
      }
      current = current->next;
    }
    return count;
  }

  double getAverage()
  {
    int sum = 0, count = 0;
    Node *current = head;
    if (head == 0)
    {
      std::cout << "List is empty, returning 0" << std::endl;
      return 0.0;
    }
    while(current != nullptr) {
      sum += current->data;
      count++;
      current = current->next;
    }
    return static_cast<double>(sum) / count;
  }

  void printEvenOdd()
  {
    if(head == nullptr){
      std::cout << "List is empty" << std::endl;
      return;
    }
    Node *current = head;
    std::cout << "Even value: ";
    // check Even number
    bool hasEven = false;
    while (current != nullptr)
    {
      if (current->data % 2 == 0)
      {
        std::cout  << current->data << " ";
        hasEven = true;
      }
      current = current->next;
    }
    if(!hasEven) {
      std::cout << "None";
    }
    std::cout << std::endl;

    // check odd number
    bool hasOdd = false;
    while (current != nullptr)
    {
      if (current->data % 2 != 0)
      {
        std::cout << current->data << " ";
        hasOdd = true;
      }
      current = current->next;
    }
    if (!hasOdd)
    {
      std::cout << "None";
    }
    std::cout << std::endl;
  }
};

int main()
{
  SSL list;
  list.addNode(18);
  list.addNode(10);
  list.addNode(50);
  list.addNode(35);
  list.addNode(20);
  std::cout << "Node count: " << list.countNodes() << std::endl;
  list.findMinMax();
  std::cout << "Sum: " << list.sumAll() << std::endl;
  std::cout << "Occurences of 50: " <<  list.countOccurrences(50) << std::endl;
  std::cout << "Average: " << list.getAverage() << std::endl;
  list.printEvenOdd();

  return 0;
}
# CS203A – Data Structures

## Course Information
- **Course Title:** Data Structures  
- **Course Code:** CS203A  
- **Target Audience**: Undergraduate Students  
- **Duration**: 18 Weeks (including Midterm and Final exams)  
- **Semester:** 11401  
- **Credits:** 3  
- **Instructor:** Yu-Feng Huang
- **Teacher's Office hours:** 
    - Monday 14:00-16:00 (R1310)  
    - Wednesday 14:00–16:00 (R1310)  
- **Course Time(Classroom):** 
    - Monday 09:10–10:00 (R60104)
    - Tuesday 15:10–17:00 (R1102)  
- **Contact:** [Yan-Xi Lee](mailto:s1131538@mail.yzu.edu.tw)  

## Name/Student id
- **Name:** Lee Yan Xi
- **Student id:** 1131538

## Repository description
I use this repository to record the knowledge I have gained in this course, my learning journey, and even the challenges I have encountered, so that I can review everything anytime after the course ends.

## Repository content
### AssignmentIV: 
According to the assignment requirements, various hashing methods were implemented using the following two programming languages.
#### C
#### CXX

### Contents of Data Structures:
Based on teacher’s lecture notes, I used NotebookLM to help me organize the knowledge from each unit, and after making my own revisions, I completed the study notes.
Including the following contents.
#### 1.Array
#### 2.Linked list
#### 3.Stack and Queue
#### 4.Hashing
#### 5.Trees
#### 6.Heaps
#### 7.Graphs

### Practice:
Below are the programming practice tasks assigned by teacher to be completed after class.
#### Practice1
This program demonstrates dynamic memory allocation in C using malloc, realloc, and free.
First, it allocates memory for an integer array of size 10 using malloc, assigns values from 1 to 10, and prints them.
Then, it uses realloc to resize the array to double its original size (from 10 to 20). The newly allocated part of the array is filled with additional values and printed again.
Finally, the program releases the allocated memory by using free.
This practice helps me understand how to dynamically allocate, resize, and properly free memory in C.

#### Practice2
This program further demonstrates dynamic memory management in C, and it focus on memory addresses.
It first uses malloc to allocate memory for an integer array of size 10 and prints the starting and ending memory addresses. Each element’s value and its corresponding memory address are displayed to show how the array is stored in memory.
Next, the program uses realloc to resize the array to double its original size. After reallocation, it prints the new memory addresses to show that the array may move to a different location in memory. The newly added elements are then initialized and printed.
This practicee helps me understand how malloc and realloc work internally, how array elements are stored contiguously in memory, and why calling free is important to release allocated memory.

#### Practice3
This program demonstrates the implementation and basic operations of a singly linked list in C using dynamic memory allocation.
It defines a node structure containing data and a pointer to the next node. The program shows how to create nodes with malloc, and prints each node’s memory address to help visualize how linked lists are stored in non-contiguous memory.
The program includes functions to traverse the list, insert a node at a specific position, and delete a node from a specific position. During insertion and deletion, it prints detailed information about node addresses and values to clearly show how pointers are updated.
Finally, all remaining nodes are freed to prevent memory leaks. This practice helps me understand pointer manipulation, dynamic memory management, and linked list behavior in C.

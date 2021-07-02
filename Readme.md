# Laboratory #4 - Sorting and Smart Pointers

-----
**CSCI2421 - Summer 2021**

### **_Team Members Names:_**
- Student #1: `Darius Deese`
- Student #2: `Ray Khan`
- Student #3: `_____________`

### **Lab Status**
```text
Describe briefly how complete your lab is, and how did you tested it:
We completed the Merge and MergeSort implementations and they seemed to sort appropriately. We changed the raw pointers
in LinkedList.cpp to shared pointers and tested to see if it compiled properly after the changes. Our LinkedList 
bubblesort ran into a few issues that we were unable to pinpoint.

Does it work on CSEGrid?
```
 
## Guidelines:
- Complete your and your teammates' names on the top of this document.
- Open the **TODO tab** on CLION, and complete the implementation.
- **Document your code**, as described on Canvas.
- All team members should be working concurrently using **code-with-me on Clion**.
- If you have questions, use Zoom _"Ask for help button"_ on the toolbar (bottom), and the instructors will get to
   your room asap. You can also use Slack concurrently.
- **Please keep your camera turned on, so you can interact with your team.**
- Instructors will be walking through the rooms regularly.
- Push your solution to GitHub
- Pull your solution from git into CSEGrid
- Compile it and run it on CSEGrid using `make`.
- **Capture a screenshot and save it on your CLion Project folder.**
- Complete the *Lab Status* section on this document.

## TO-DO:
- Review sort definition change in `ListInterface.h`, in `ArrayList.h` and `LinkedList.h`.
1. Implement `sort` in `ArrayList` using `mergeSort` algorithm as described in the lectures and textbook. _30 marks_ 
    1. **TODO 1**: Implement `merge` private method.
    1. **TODO 2**. Implement `mergeSort` private method.
1. Change `LinkedList` implementation to use `shared_ptr` instead of `Node *`. _30 marks_
    1. **TODO 3**: change in both `LinkedList.h` and `LinkedList.cpp`
1. Implement `sort` in `LinkedList` using `bubbleSort` algorithm as described in the lectures and textbook. _30 marks_
    1. **TODO 4**: implement `LinkedList::sort()` method. 
1. **TODO 5**: Using git, pull from CSEGrid, compile, run and capture screenshot showing your code is running on CSEGrid.

## Submission
- Complete the lab.
- On CLion execute Build --> Clean from the menu (this will remove all temporary files)
- Using zip, compress the entire CLion Project and upload it to canvas before 11:59am.
    - Remember to add your CSE grid screenshot to your sources folder!
- **LATE SUBMISSIONS**
    - The assignment will be open till 3pm. 
    - Submitting after 11:59:00am will imply a 20% penalty.
    - Submit your lab to your Lab 3 assignment on Canvas. 
      
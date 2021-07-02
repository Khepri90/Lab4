#include "iostream"
#include "memory"
#include "PrecondViolatedExcep.h"
#include "ListInterface.h"
#include "LinkedList.h"
#include "ArrayList.h"

using namespace std;

/************************************************************************************************/
void displayList(const shared_ptr<ListInterface<string>>& listPtr){

    cout<< string(80,'_')<<endl;

    cout << "The list contains: | " ;
    for (int pos = 1; pos <= listPtr->getLength(); pos++)    {
        try  {
            cout << listPtr->getEntry(pos) << " | ";
        }
        catch(PrecondViolatedExcep& except)        {
            cout << "Exception thrown getting entry inserted at position " << pos << endl;
            cout << except.what() << endl;
        }
    }
    cout << endl;
    cout<< string(80,'-')<<endl;

}

/************************************************************************************************/
void listTester(const shared_ptr<ListInterface<string>>& listPtr, string data[], int dataLen){
    cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
    for (int i = 0; i < dataLen; i++)    {
        if (listPtr->insert(i + 1, data[i])) {
            try {
                cout << "Inserted " << listPtr->getEntry(i + 1) << " at position " << (i + 1) << endl;
            }
            catch (PrecondViolatedExcep& except)            {
                cout << "Exception thrown getting entry inserted at list end!" << endl;
                cout << except.what() << endl;
            }
        }
        else
            cout << "Cannot insert " << data[i] << " at position " << (i + 1) << endl;
    }
    cout << "isEmpty: returns " << boolalpha << listPtr->isEmpty() << "; (should be false)" << endl;  //boolalpha converts int to bool on output.s
    cout << "getLength returns : " << boolalpha << listPtr->getLength() << "; (should be "<<dataLen<<")" << endl;

    displayList(listPtr);
    cout << "Sorting the list... " << endl;
    listPtr->sort();
    displayList(listPtr);
}



/************************************************************************************************/
void testArrayList(){
    shared_ptr<ListInterface<string>> listPtr = nullptr;
    cout<<string(80,'*')<<endl;
    cout<< "                   Testing Array List...."<<endl;
    cout<<string(80,'*')<<endl;

    cout<<"---->>> ONE ELEMENT LIST <<<----"<<endl;
    listPtr = make_shared<ArrayList<string>>();
    string data1[] = {"alpha"};
    listTester(listPtr, data1, 1);

    cout<<"---->>> TWO ELEMENT LIST <<<----"<<endl;
    listPtr = make_shared<ArrayList<string>>();
    string data2[] = {"beta","alpha"};
    listTester(listPtr, data2, 2);

    cout<<"---->>> SIX ELEMENT LIST <<<----"<<endl;
    listPtr = make_shared<ArrayList<string>>();
    string data3[] = {"one", "two", "three", "four", "five", "six"};
    listTester(listPtr, data3, 6);
}

/************************************************************************************************/
void testLinkedList(){
    shared_ptr<ListInterface<string>> listPtr = nullptr;
    cout<<string(80,'=')<<endl;
    cout<< "                   Testing Linked-List...."<<endl;
    cout<<string(80,'=')<<endl;

    cout<<"---->>> ONE ELEMENT LIST <<<----"<<endl;
    listPtr = make_shared<LinkedList<string>>();
    string data1[] = {"alpha"};
    listTester(listPtr, data1, 1);

    cout<<"---->>> TWO ELEMENT LIST <<<----"<<endl;
    listPtr = make_shared<LinkedList<string>>();
    string data2[] = {"beta","alpha"};
    listTester(listPtr, data2, 2);

    cout<<"---->>> SIX ELEMENT LIST <<<----"<<endl;
    listPtr = make_shared<LinkedList<string>>();
    string data3[] = {"one", "two", "three", "four", "five", "six"};
    listTester(listPtr, data3, 6);
}


/************************************************************************************************/
int main(){
    testArrayList();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    testLinkedList();
    return 0;
}

/**
 * TODO 5: Sync to Git, and pull from CSEGrid, compile, run and capture screenshot. -- 10 marks
 */
#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
//#include patient.h
using namespace std;
struct Patient {
    string name;
    int id;
    int phoneNumber;
    string address;
    float invoice;
};

//Node class
class Node {
public:
    Patient patient;
    Node *next;
    //constructor
    Node(Patient p){
        patient = p;
        next = nullptr;
    }
};

//LinkedList class
class LinkedList
{
private:
    Node *head;
public:
    //constructor
    LinkedList();
    //function  checks that the Record Already Exist or not
    bool checkRecord(Patient p);
    //creating a new node in the Empty Linked list or inserting
    //a new node in a non-Empty linked list
    bool createRecord(Patient p);
    //Search a Record for a key in the linked list.
    bool searchRecord(int id);
    //delete a Record from the linked list
    void deleteRecord(int id);
    //printing all the elements of the Linked list
    void showRecords();
    //add 15% of the invoice total only for invoices more than 100SR
    void updateRecord();
};


#endif // PATIENT_H
LinkedList::LinkedList()
{
    head = nullptr;
}

//function  checks that the Record Already Exist or not
bool LinkedList::checkRecord(Patient p)
{
    Node* temp = head;
    //traverse the list to checks the id of patient
    while(temp != nullptr)
    {
        if(temp->patient.id == p.id)
            return true;
        temp = temp->next;
    }
    return false;
}

//creating a new node in the Empty Linked list or inserting
//a new node in a non-Empty linked list
bool LinkedList::createRecord(Patient p)
{
    //create a new node
    Node *newnode = new Node(p);
    //check if list is empty
    if(head == nullptr)
    {
        head = newnode;
        return true;
    }
    Node* temp = head;
    //traverse the list to reach end of list
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return true;
}


//Search a Record for a key in the linked list.
bool LinkedList::searchRecord(int id)
{
    Node* temp = head;
    //traverse the list to checks the id of patient
    while(temp != nullptr)
    {
        if(temp->patient.id == id)
            return true;
        temp = temp->next;
    }
    return false;
}


//delete a Record from the linked list
void LinkedList::deleteRecord(int id)
{
    Node* temp = head;
    //check if id found at head node
    if(temp->patient.id ==id)
    {
        head = head->next;
        delete temp;
        cout<<"Record deleted!"<<endl;
        return;
    }
    Node *prev = nullptr;
    //traverse the list to checks the id of patient
    while(temp != nullptr && temp->patient.id!=id)
    {
        prev = temp;
        temp = temp->next;
    }
    //check if id not found
    if(temp == nullptr)
    {
        cout<<"Record not found!"<<endl;
        return;
    }
    //delete record
    prev->next = temp->next;
    delete temp;
    cout<<"Record deleted!"<<endl;
}

//printing all the elements of the Linked list
void LinkedList::showRecords()
{
    Node* temp = head;
    //traverse the list to printing all the records
    cout <<"List of Records: "<< endl;
    while(temp != nullptr)
    {
        cout << "Name: " << temp->patient.name
             << " ID: " << temp->patient.id
             << " Phone number: " << temp->patient.phoneNumber
             << " Address: " << temp->patient.address
             << " Invoice: " << temp->patient.invoice << "SR"<<endl;

        temp = temp->next;
    }
}
//add 15% of the invoice total only for invoices more than 100SR
void LinkedList::updateRecord()
{
    Node* temp = head;
    //traverse the list to checks the id of patient
    while(temp != nullptr)
    {
        if(temp->patient.invoice > 100)
            temp->patient.invoice = 1.15 * temp->patient.invoice;
        temp = temp->next;
    }
    cout<<"Records updated!"<<endl;
}
int main()
{
    int choice;

    //create a LinkedList of patients
    LinkedList list;
    Patient p;
    int id;

    while(true)
    {
        //print the menu
        cout << "1. Add a record\n";
        cout << "2. Search a record\n";
        cout << "3. Delete a record\n";
        cout << "4. Show all the records\n";
        cout << "5. Update Invoice\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 0)
            break;

        switch(choice)
        {
            case 1:

                //creating a new node in the Empty Linked list or inserting
                cout<< "Please enter the ID of patient: ";
                cin >> p.id;
                cin.ignore();
                cout<< "Please enter the name of patient: ";
                getline(cin, p.name);
                cout<< "Please enter the phone number of patient: ";
                cin >> p.phoneNumber;
                cin.ignore();
                cout<< "Please enter the address of patient: ";
                getline(cin, p.address);
                cout<< "Please enter total invoice: ";
                cin >> p.invoice;

                //check if recored already exist
                if(list.checkRecord(p))
                    cout << "Record Already Exist!"<<endl;
                else
                {
                    list.createRecord(p);
                    cout << "Successfully Inserted new Record\n";
                }

                break;

            case 2:
                //Search a Record for a key in the linked list
                cout<< "Enter the ID of patient: ";
                cin >> id;
                if(list.searchRecord(id))
                    cout<< "Record found!" << endl;
                else
                    cout<< "Record not found!" << endl;
                break;

            case 3:
                //delete a Record from the linked list
                cout<< "Enter the ID of patient: ";
                cin >> id;
                list.deleteRecord(id);
                break;

            case 4:
                //printing all the elements of the Linked list
                list.showRecords();
                break;

            case 5:
                //add 15% of the invoice total only for invoices more than 100SR
                list.updateRecord();
                break;

            default:
                cout << "Invalid option!" << endl;

        }//end of switch
        cout<<endl;
    }//end of loop


    return 0;
}
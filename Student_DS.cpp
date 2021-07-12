//==========================================================================
//
// Description   :  STUDENT MANAGEMENT SYSTEM USING SINGLY LINEAR LINKEDLIST
//
// Input         :  Int,Float,Str
// Output        :  Int,Float,Str
//
// Author        :  Prasad Dangare
// Date          :  12 July 2021
//
//==========================================================================


//======================
//
// Header Files
//
//======================


#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


//======================
//
// Defining The Macros
//
//======================


typedef struct Students
{
    int Roll_no;
    char Stud_name[50];
    float Stud_marks;

    struct Students * next;

} NODE, *PNODE;


//==========================================================================================
//
// Class Name  :  Student_Info
// Description :  This Class represents Student Information Such As Name, Roll Number, Marks
//
//
//===========================================================================================


class Student_Info
{
    private : 

        PNODE Head;
        int iSize;

    public:

        //==========================================================================
        //
        //
        // Class Name       :   Student_Info
        // Function Date    :   12 July 2021
        // Function Author  :   Prasad Dangare
        // Parameters       :   NONE
        // Description      :   This Is Constructor Of Class Student_Info
        //
        // Returns          :   NONE
        //
        //
        //========================================================================== 

        Student_Info()
        {
            //cout << "Inside Constructor \n";
            Head = NULL;
            iSize = 0;
        }

        //==========================================================================
        //
        //
        // Class Name       :   Student_Info
        // Function Date    :   12 July 2021
        // Function Author  :   Prasad Dangare
        // Parameters       :   NONE
        // Description      :   This Is Distructor Of Class Student_Info
        //
        // Returns          :   NONE
        //
        //
        //==========================================================================

        ~Student_Info()
        {
            //cout << "Inside Destructor \n";
            PNODE temp = NULL;

            while (Head != NULL)
            {
                temp = Head;
                Head = Head -> next;
                delete temp;
            }
        }

        void InsertLast(int, char*, float);
        int Count();
        void Display();
        void Search(int);
        void Search(char*);
        void Delete(int);
        void Update(int);
};


//==========================================================================
//
//
// Function Name    :   InsertLast()
// Function Date    :   12 July 2021
// Function Author  :   Prasad Dangare
// Parameters       :   int , char, float
// Description      :   InsertLast Function Add Student Details In The LinkedList
//
// Returns          :   NONE
//
//
//==========================================================================


void Student_Info :: InsertLast(int iNo, char*Str, float fNo)
{
    int iCnt = 0;
    PNODE newn = NULL;
    newn = new NODE;
    PNODE temp = Head;
    PNODE rno = Head;
    
    while(rno != NULL)
    {
        if(rno -> Roll_no == iNo)
        {
            cout << "\n Roll Number Is Already Exists Give Another One Between 1 To 100 \n";
            return;
        }
        rno = rno -> next;
    }

    if((iNo < 1) || (iNo > 100))
    {
        cout << "\n Please Enter Roll Number In Between 1 To 100 \n";
        return;
    }

    else
    {
        newn -> Roll_no = iNo;
    }

    while(*Str != '\0')
    {
        newn -> Stud_name[iCnt] = *Str;
        iCnt++;
        Str++;
    }
    newn -> Stud_name[iCnt] = '\0';
    newn -> next = NULL;

    if((fNo < 1.0) || (fNo > 9.9))
    {
        cout << "\n Please Give Marks In Between 1.0 To 9.9 \n";
        return;
    }

    else
    {
        newn-> Stud_marks = fNo;
    }

    if(Head == NULL)    // Insert Last
    {
        Head = newn;
    }

    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    cout << "\n Student Added Successfully... \n";
    iSize++;
}


//==========================================================================
//
//
// Function Name    :   Display()
// Function Date    :   12 July 2021
// Function Author  :   Prasad Dangare
// Parameters       :   None
// Description      :   Display Function Display The Student Details From The LinkedList 
//
// Returns          :   NONE
//
//
//==========================================================================


void Student_Info :: Display()
{
    PNODE temp = Head;
    cout << "\n Student Records Are : \n";

    if(temp == NULL)
    {
        cout << "\n Records Are Empty \n";
        return;
    }

    while(temp != NULL)
    {
        cout << "\n Student Name Is : " << temp -> Stud_name << "\n";
        cout << "\n RollNo is : " << temp -> Roll_no << "\n";
        cout << "\n Marks is : " << temp -> Stud_marks << "\n";
        temp = temp -> next;
    }
    cout << "\n";
}


//==========================================================================
//
//
// Function Name    :   Count()
// Function Date    :   12 July 2021
// Function Author  :   Prasad Dangare
// Parameters       :   None
// Description      :   Count Function Count Number Of Students In The LinkedList 
//
// Returns          :   int
//                  :   Return Number Of Students In LinkedList
//
//
//==========================================================================


int Student_Info :: Count()
{
    return iSize;
}


//=======================================================================================================
//
//
// Function Name    :   Search()
// Function Date    :   12 July 2021
// Function Author  :   Prasad Dangare
// Parameters       :   int
// Description      :   Search Function Search A Particular Student In The LinkedList By Its Roll Number 
//
// Returns          :   NONE
//
//
//=======================================================================================================


void Student_Info :: Search(int iNo)
{
    PNODE temp = Head;
    
    while(temp != NULL)
    {
        if(temp -> Roll_no == iNo)
        {
            cout << "\n Student Found Of Roll No : " << iNo << "\n";
            cout << "\n Name is : " << temp -> Stud_name << "\n";
            cout << "\n Roll Number is : " << temp -> Roll_no << "\n";
            cout << "\n Marks is : " << temp -> Stud_marks << "\n";
            break;
        }
        temp = temp -> next;
    }

    if(temp == NULL)
    {
        cout << "\n There Is No Such Student Found \n";
    }
}


//=================================================================================================
//
//
// Function Name    :   Search()
// Function Date    :   12 July 2021
// Function Author  :   Prasad Dangare
// Parameters       :   char
// Description      :   Search Function Search A Particular Student In The LinkedList By Its Name
//
// Returns          :   NONE
//
//
//=================================================================================================


void Student_Info :: Search(char *Str)
{
    PNODE temp = Head;
    
    while(temp != NULL)
    {
        int iNo = strcmp(temp -> Stud_name, Str);

        if(iNo == 0)
        {
            cout << "\n Student Found Of Name : " << Str << "\n";
            cout << "\n Name is : " << temp -> Stud_name << "\n";
            cout << "\n Roll Number is : " << temp -> Roll_no << "\n";
            cout << "\n Marks is : " << temp -> Stud_marks << "\n";
            break;
        }
        temp = temp -> next;
    }

    if(temp == NULL)
    {
        cout << "\n There Is No Such Student Found \n";
    }
}


//==========================================================================
//
//
// Function Name    :   Delete()
// Function Date    :   12 July 2021
// Function Author  :   Prasad Dangare
// Parameters       :   int
// Description      :   Delete Function Remove The Student And Its Details From The LinkedList 
//
// Returns          :   NONE
//
//
//==========================================================================


void Student_Info :: Delete(int iNo)
{
    PNODE temp = Head;
    PNODE iNode = Head;
    PNODE target;
    int iCnt = 0, iPos = 0;

    while(iNode != NULL)
    {
        iCnt++;
        if(iNode -> Roll_no == iNo)
        {
            iPos = iCnt;
            break;
        }
        iNode = iNode -> next;
    }

    if(iPos < 1)
    {
        cout << "\n Wrong RollNo \n";
        return;
    }

    if(iPos == 1) // delete first
    {
        if(Head -> next == NULL) // ll contain 1 node
        {
            delete Head;
            Head = NULL;
        }
        else
        {
            Head = Head -> next; // delete first node
            delete temp;
        }
    }

    else if(iPos == iSize) // delete last
    {
        if(Head -> next == NULL) // ll contain 1 node
        {
            delete Head;
            Head = NULL;
        }

        else // ll contain more than 1 node
        {
            while(temp -> next -> next != NULL)
            {
                temp = temp -> next;
            }
            delete temp -> next;
            temp -> next = NULL;
        }
    }

    else // delete at position
    {
        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = temp -> next -> next;
        delete target;
    }
    iSize--;
    cout << "\n Student Record Deleted Succesfully \n";
}


//=============================================================================================
//
//
// Function Name    :   Update()
// Function Date    :   12 July 2021
// Function Author  :   Prasad Dangare
// Parameters       :   int
// Description      :   Update Function Perform Updation Of Student Details In The LinkedList 
//
// Returns          :   NONE
//
//
//==============================================================================================


void Student_Info :: Update(int iNo)
{
    PNODE temp = Head;
    float New_marks = 0.0;
    int iOption = 1, iPos = 0, New_Rollno = 0;
    char New_name[50];

    while(temp != NULL)
    {
        if(temp -> Roll_no == iNo)
        {
            iPos = 1;
            break;
        }
        temp = temp -> next;
    }

    if(iPos == 0)
    {
        cout << "\n There Is No Such Student \n";
        return;
    }

    else
    {
        cout << "\n Student Found Of Roll Number : " << iNo << "\n";
        
        while(iOption != 0)
        {
            cout << "\nEnter Your Choice : \n";
            cout << "\n*******************************\n";
            cout << "1 : Press 1 For Updation Of Name : \n";
            cout << "2 : Press 2 For Updation Of Marks : \n";
            cout << "3 : Press 3 For Updation Of Roll Number : \n";
            cout << "0 : Press 0 For Exit To Main Menu : \n";
            cout << "\n*******************************\n";
            cin >> iOption;

            switch(iOption)
            {
                case 1 :
                    cout << "\n Enter New Name : \n";
                    scanf(" %[^'\n']s", New_name);
                    strcpy(temp -> Stud_name, New_name);
                    cout << "Update Successfully \n";
                    break;

                case 2 : 
                    cout << "\n Enter New Marks : \n";
                    cin >> New_marks;

                    if((New_marks < 1.0) || (New_marks > 9.9))
                    {
                        cout << "\n Please enter Marks In Between 1.0 To 9.9 \n";
                        break;
                    }

                    else
                    {
                        temp -> Stud_marks = New_marks;
                        cout << "Update Successfully \n";
                        break;
                    }

                case 3 :
                    cout << "\n Enter New Roll Number : \n";
                    cin >> New_Rollno;

                    if((New_Rollno < 0) || (New_Rollno > 100))
                    {
                        cout << "\n Please Enter Roll Number In Between 1 To 100 \n";
                        break;
                    }

                    else
                    {
                        temp -> Roll_no = New_Rollno;
                        cout << "Update Successfully \n";
                        break;
                    }

                case 0 : 
                    break;
        
                default:
                    cout << "Please Enter Valid Input \n";
                    break;
            }
        }
    }
}


//==========================================================================
//
//
// Function Name   :   Entry Point Function
// Function Date   :   12 July 2021
// Function Author :   Prasad Dangare
// Brif Description :  Function Calls For Above Created Functions With Dynamic Input
//
//
//==========================================================================


int main()
{
    int iChoice = 1, iNo = 0; 
    int Stud_rollno = 0; 
    char Stud_name[50];
    float Stud_marks = 0.0;

    Student_Info * obj1 = new Student_Info;

    cout << "\n";
    cout << "\t\n*********************************************************\t\n";
    cout << "\t\n*****__________ STUDENT MANAGEMENT SYSTEM __________*****\t\n";
    cout << "\t\n*********************************************************\t\n";
    cout << "\n";

    while(iChoice != 0)
    {
        cout << "\nEnter Your Choice : " << "\n";
        cout << "\n_______________________________________________________________________\n";
        cout << "1 : Press 1 To Add Details Of Students : " << "\n";
        cout << "2 : Press 2 To Display Information Of All Student : " << "\n";
        cout << "3 : Press 3 To Count Total Number Of Students : " << "\n";
        cout << "4 : Press 4 To Search A Student By It's Roll Number : \n";
        cout << "5 : Press 5 To Search A Student By It's Name : " << "\n";
        cout << "6 : Press 6 To Delete The Record Of A Student By It's Roll Number : " << "\n";
        cout << "7 : Press 7 To Update The Existing Records Of Students : " << "\n";
        cout << "0 : Press 0 To Exit The Application " << "\n";
        cout << "\n_______________________________________________________________________\n";

        cin >> iChoice;

        switch (iChoice)
        {
            case 1 :

                cout << "\n Enter Student Name :  \n";
                scanf(" %[^'\n']s", Stud_name);

                cout << "\n Enter Student Roll No : \n";
                cin >> Stud_rollno;
                
                cout << "\n Enter Student Marks : \n";
                cin >> Stud_marks;
                
                obj1 -> InsertLast(Stud_rollno, Stud_name, Stud_marks);
                break;

            case 2 : 

                obj1 -> Display();
                break;

            case 3 :

                iNo = obj1 -> Count();
                cout << "\n Total Number Of Students Are : " << iNo << "\n";
                break;

            case 4 : 

                cout << "\n Enter The Roll Number Of Student To Search : \n";
                cin >> Stud_rollno;
                obj1 -> Search(Stud_rollno);
                break;

            case 5 : 

                cout << "\n Enter The Student Name To Search : \n";
                scanf(" %[^'\n']s", Stud_name);
                obj1 -> Search(Stud_name);
                break;

            case 6 : 

                cout << "\n Enter The Roll Number Of Student To Delete The Record : \n";
                cin >> Stud_rollno;
                obj1 -> Delete(Stud_rollno);
                break;

            case 7 :

                cout << "\n Enter The Student Roll Number For Updation : \n";
                cin >> Stud_rollno;
                obj1 -> Update(Stud_rollno);
                break;

            case 0 :

                cout << "\n Thankyou For Using The Application \n";
                delete obj1;
                break;
        
            default:

                cout << "\n Enter Valid Input \n";
                break;

        } // end of switch
    } // end of while

    return 0;
} // end of main

//
//  main.cpp
//  Assignment2
//
//  Created by Sasha Malik on 01/03/2022.
//
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<fstream>
#include<sstream>
#include<math.h>

using namespace std;

string type;
//stores the id of the currently logged in member
int MID;
//stores the array of members
int arraySize;

//id is generated
int generateID();


// names are converted to lower case
string Lower( string x);


class Admin
{
private:
    int AdminID;
    string First_Name;
    string Last_Name;
    string Username;
    string Password;
    
public:
    
    // an empty constructor
    Admin()
    {
        
    }

    void loadAdmin()
    {
        cout<<"Enter first name:";
        cin>>First_Name;
        cout<<"Enter last name:";
        cin>>Last_Name;
        
        // generates the adminID
        AdminID = generateID();
        
        Username = Lower(First_Name) + to_string(AdminID);
        Password = Lower(Last_Name)  + to_string(generateID());
    }
    
    // to load the data of an admin from the file
    void loadAdminFile( int ID, string fname , string lname, string username, string password)
    {
        AdminID = (ID);
        First_Name = fname;
        Last_Name = lname;
        Username = username;
        Password = password;
        
        
    }
    
    void display()
    {
        
        cout<<endl<<"\n AdminID: "<<AdminID<<"\n FirstName: "<<First_Name<<"\n Last Name: "<<Last_Name<<"\n Username: "<<Username<<"\n Password: "<<Password<<endl;
    }
    
    string getFName()
    {
        return First_Name;
    }
    
    string getLName()
    {
        return Last_Name;
    }
    
    string getUsername()
    {
        return Username;
    }
    
    string getPassword()
    {
        return Password;
    }
    
    int getID()
    {
        return AdminID;
    }
    
    
};



class Member{
    
    private:
        int MemberID;
        string First_Name;
        string Last_Name;
        string Username;
        string Password;
    
    
    public:
    
        void loadMember()
        {
            cout<<"Enter first name:";
            cin>>First_Name;
            cout<<"Enter last name:";
            cin>>Last_Name;
            //generates MemberID
            MemberID = generateID();
            //useraname and password are generated
            Username = Lower(First_Name) + to_string(MemberID);
            Password = Lower(Last_Name)  + to_string(generateID());
        }
    
    // to load a member from the file
        void loadMemberFile( int ID, string fname , string lname, string username, string password)
        {
            MemberID = (ID);
            First_Name = fname;
            Last_Name = lname;
            Username = username;
            Password = password;
            
            
        }
        void display(){
        
            cout<<endl<<"\n MemberID: "<<MemberID<<"\n FirstName: "<<First_Name<<"\n Last Name: "<<Last_Name<<"\n Username: "<<Username<<"\n Password: "<<Password<<endl;
        }
    
        string getFName()
        {
            return First_Name;
        }
    
        string getLName()
        {
            return Last_Name;
        }
    
        string getUsername()
        {
            return Username;
        }
        
        string getPassword()
        {
            return Password;
        }
    
        int getID()
        {
            return MemberID;
        }
        
        
};



// a node class for the stack
class SNode
{
    int elem;
    SNode* next;
    friend class SList;
    
    public:
        SNode()
        {
            next = NULL;
        }
       
    
};



class SList
{
    private:
        SNode* head;// pointer to the head of list
        friend class LStack;
    public:
        SList (); // empty list constructor
        ~SList (); // destructor to clean up all nodes
        bool empty() const; // is list empty?
        /*change it later*/ void addFront(int element); // add a new Node at the front of the list
        void removeFront(); // remove front Node from the list
        void display() const;
        /*change it later to const int& */ int front() const;   // returns the first element
        
        // to check if a member is in the list (booked for a class)
        bool check();
};

class LStack
{
    
    public:
    LStack();
    void push(const int &e);
    void pop();
    int top() const;
    int size() const;
    bool empty() const;
    
    // calls the check function in the Slist class
    bool Lcheck();
 
    
    private:
        SList S;// list for the stack
        int t; //number of elements in the stack
        friend class FitnessClass;
    
};

class FitnessClass
{
    
    private:
        int ClassID;
        string ClassName;
        string ClassDate;
        string ClassTime;
        int MaximumCapacity = 10;
        string RoomNumber;
        LStack stack;
        
        
    public:
    
    // it is called to cancel a booking
    void cancel();
 
        void loadClass()
    {
            
            cout<<"\nEnter class ID : ";
            cin>>ClassID;
            cout<<"\n Enter Class name : ";
            cin>>ClassName;
            cout<<"\n Enter Class date : ";
            cin>>ClassDate;
            cout<<"\n Enter Class time : ";
            cin>>ClassTime;
            cout<<"\n Enter Room number : ";
            cin>>RoomNumber;
        
    }
    
    // to load a class from the file
    void loadClass(int id , int capacity, string name, string date, string time, string room)
    {
        ClassID = id;
        ClassName = name;
        ClassTime = time;
        MaximumCapacity = capacity;
        ClassDate = date;
        RoomNumber = room;
        
    }
    
    // loads the list of members from the file
    void loadStack ( int stack_id )
    {
        stack.push( stack_id );
        
    }
    
    // loads the the new class after splitting
    void addSplitClass( string room, string time, string date, string name , int cap , int ID )
    {
        ClassID = ID;
        ClassName = name;
        ClassDate = date;
        ClassTime = time;
        MaximumCapacity = cap;
        RoomNumber = room;
           
    }
    
    // calls the check function in the list to see if a certain member has booked a class
        bool checkID()
    {
        return ( stack.Lcheck() );
    }
    
    // makes MID the memberID of the member at the top of the stack
    void getStackID()
    {
        MID = stack.top();
    }
    
    // checks if the stack is full
        bool checkVacancy()
    {
        return  (stack.size() < MaximumCapacity);
    }
    
    // returns size of the stack
        int returnSize()
    {
        return stack.size();
    }
    
    // returns the array of memberIDs of a class so they can be added to another class
        int* save()
    {
            int* array = new int [stack.size()];
            int i = 0;
            arraySize = 0;
            
            while(!stack.empty())
            {
                array[i] = stack.top();
                i++;
                arraySize = i;
               
                stack.pop();
                
            }
          
            return array;
          
    }
    
    // to book a class
        void setClass()
    {
            if (stack.size() < MaximumCapacity)
               
            {
                stack.push( MID );
                cout<<"\n Class Booked! \n";
            }
            
            else
                cout<<"\n Maximum Capacity reached!";
            
    }
    
        void display()
    {
            cout<<"\n Class ID : "<<ClassID<<"\n Class Name : "<<ClassName<<"\n Class Date : "<<ClassDate<<"\n Class Time : "<<ClassTime
            /* <<"\n Maximum Capacity : "<<MaximumCapacity*/
            <<"\n Room number : "<<RoomNumber<<endl;
            
    }
    

    // return functions
    
    int getClassID()
    {
        return ClassID;
    }
    
    string getClassName()
    {
        return ClassName;
    }
    
    string getClassDate()
    {
        return ClassDate;
    }
    
    string getClassTime()
    {
        return ClassTime;
    }
    
    int getMaximumCapacity()
    {
        return MaximumCapacity;
    }
    
    string getRoomNumber()
    {
        return RoomNumber;
    }
    
    
    //update functions
    
    void updateDate(string date)
    {
        ClassDate = date;
    }
    void updateTime(string time)
    {
        ClassTime = time;
    }
    
    void updateRoom(string room)
    {
        RoomNumber = room;
    }
    
    void updateMaximumCapacity(int new_cap)
    {
        MaximumCapacity = new_cap;
    }
    
};


template< typename a >
class Dlist;

// node for doubly linked list
template< typename a >
class Node
{
    a elem;
    Node* next;
    Node* prev;
    friend class Dlist<a>;
    
    public:
    
    Node()
    {
        next = NULL;
        prev = NULL;
    }
    
    
};


template< typename a>
class Dlist
{
    Node<a>* head;
    Node<a>* tail;
    
    public:
    
    //constructor
    Dlist()
    {
        head = new Node<a>;
        tail = new Node<a>;
        head->next = tail;
        tail->prev = head;
    }
    // if the list of classes is empty
    bool empty();
    
    // add an elemnt to the class
    void addElement( a& element );
    
    // returns the front element
    a& front();
    
    //removes previous element
    void remove(Node<a>* v);
    
    // to login
    bool login(string username, string password);
    
    // to book a class
    void bookAClass(int class_id);
    
    // display the contents of an element
    void display();
    
    // deleting a class
    void deleteClass(int class_id);
    
    // updating the class
    void updateClass(int class_id);
    
    // updating the maximum capacity
    void updateCapacity(int class_id, int new_cap);
    
    //view vacan classes
    void viewClassesWithVacancies();
    
    // to see the members booked for a class
    void viewBookingList();
    
    // to cancel a booking
    void cancelBooking(int class_id);
    
    // save admin to the file
    void saveAdmin();
    void saveMember();
    void saveClass();
    
    // load admin from the file
    void loadAdmin();
    
    // split a class
    void split(int class_id,int cap);
    
    // to sort the class before loading it
    void sort();
   
};


// obkects of the lists
Dlist< Admin > adminList;
Dlist< Member > memberList;
Dlist< FitnessClass > fitnessList;


bool login(string username , string password);
void registerAdmin( Dlist< Admin > adminList);
void registerMember( Dlist< Member > memberList);
void addFitnessClass(Dlist< FitnessClass > fitnessList );
void deleteFitnessClass(int class_id);
void viewMemberList();
void updateClassDetails(int class_id);
void changeClassCapacity(int class_id, int new_cap);
void bookAClass(int class_id);
void viewClassesWithVacancies();
void viewBookingList();
void cancelBooking(int class_id);
void logout(int& choice);
void quitProgram();
void addAdmin(int ID, string fname, string lname, string  username, string password);
void loadAdmin();
void loadMember();
void loadClassFile();
void loadFile()
{
    loadAdmin();
    loadMember();
    loadClassFile();
}

void splitClass( int class_id,int cap = 10)
{
   
    fitnessList.split(class_id, cap);
         
}



//====================================


int main()
{
    srand( time(NULL) );
    loadFile();
    
    while (true)
    {
        int choice = 0 ;
        string username, password;
        cout<<"\nEnter user type (admin / member) : ";
        cin>>type;
        cout<<"\nEnter Username : ";
        cin>>username;
        cout<<"\nEnter password : ";
        cin>>password;
        
        
            
    if(type == "admin")
    
        if ( login( username, password ) )
        
       {
        
        while(choice!= -1)
        {
            cout<<"\n\n The list of available operations for admins: ";
            cout<<"\n 1) Register a new admin \n 2) Register a new member \n 3) view the list of members \n 4) add a fitness class \n 5) delete a fitness class \n 6) update the details of a fitness class \n 7) update the capacity of the fitness class \n 8) split the fitness class into two classes \n 9) display the class with vacancies \n 10) logout \n 11) quit the program \n Enter choice: ";
            cin>>choice;
            
            
            if (choice == 1)
                registerAdmin(adminList);
            
            else if  (choice == 2)
                registerMember(memberList);
            
            else if (choice == 3)
                viewMemberList();
                
            else if (choice == 4)
                addFitnessClass(fitnessList);
            
                     
            else if (choice == 5)
            {
                int class_id;
                cout<<"\n Enter Class ID for deletion : ";
                cin>>class_id;
                deleteFitnessClass(class_id);
            }
            else if (choice == 6)
            {
                int class_id;
                cout<<"\n Enter Class ID for updating details : ";
                cin>>class_id;
                updateClassDetails(class_id);
            }
            else if (choice == 7)
            {
                int class_id, new_cap;
                cout<<"\n Enter Class ID for updating the capacity : ";
                cin>>class_id;
                cout<<"\n Enter new capacity (between 5 and 15) : ";
                cin>>new_cap;
                while( new_cap<5 || new_cap>15)
                {   cout<<"\n Invalid Capacity \n Enter new capacity (between 5 and 15) : ";
                    cin>>new_cap;
                }
                
                changeClassCapacity(class_id, new_cap);
            }
            
            else if (choice == 8 )
            {
                int class_id, cap;
                cout<<"\n Enter Class ID for splitting the class : ";
                cin>>class_id;
                
                string choice;
                cout<<"\n Do you want to enter new capacity: (yes/no) ";
                cin>>choice;
                
                cap = 10;
                
                if(choice == "yes")
                {
                    cout<<"\n Enter capacity (between 5 and 15) : ";
                    cin>>cap;
                }
                
                splitClass(class_id, cap);
                
            }
            
            else if (choice == 9)
                viewClassesWithVacancies();
                
            
            else if (choice == 10)
            {
                logout(choice);
            }
            
            
            else if (choice == 11)
            {
                quitProgram();
                exit(0);
            }
            
          
       }
        
    }
        
        
    
        if(type == "member")
    
        
         if ( login( username, password ) )
    {
    
        while(choice!= -1)
        
            {
                cout<<"\n\n The list of available operations for members: ";
                cout<<"\n 1) Book a class \n 2) Veiw class with vacancies \n 3) Cancel booking \n 4) View bookings \n 5) Logout \n 6) Quit program \n Enter choice: ";
                cin>>choice;
                
                
                if (choice == 1)
                {
                    int class_id;
                    cout<<"\n Enter Class ID for booking : ";
                    cin>>class_id;
                    bookAClass(class_id);
                    
                }
                
                else if  (choice == 2)
                    viewClassesWithVacancies();
                
                else if (choice == 3)
                {
                    int class_id;
                    cout<<"\n Enter Class ID for cancellation : ";
                    cin>>class_id;
                    cancelBooking(class_id);
                    
                }
                
                else if (choice == 4)
                    viewBookingList();
                
                else if (choice == 5)
                    logout(choice);
                
                else if (choice == 6)
                {
                    quitProgram();
                    exit(0);
                }
                
                
            }
        }
        
    }

    return 0;
    
}





//====================================

//====================================

// functions for the list and stack


SList::SList ()
{
    this->head = NULL;
}

// destructor to clean up all nodes

SList::~SList ()
{
    while( !empty() )
        removeFront();
}

// Check if the list is empty or not

bool SList::empty() const
{
    // the list is empty if head points to NULL
    
    return ( head == NULL );

}

// add a node at the front of the list

void SList::addFront(int element)
{
    //creatting a temorary node and updating head
    
    SNode * temp = new SNode;
    temp->elem = element;
    
    temp->next = head;
    head = temp;
    
}

// remove the first node from the list

void SList::removeFront()
{
    // changing head to it's next position and delering the temporary(older) node
    
        SNode* temp =  head;
        head = temp -> next;

    
}


int SList::front() const
{
    return head->elem;
}

// to ckeck if a certain element is booked for a class
bool SList::check()
{
    int ch = 0;
    SNode* temp = new SNode;
    temp->next = head ;
    
    while (temp != NULL)
    {
        if( MID == temp->elem)
        {
            ch = 1;
        }
        temp = temp -> next;
    }
    
    return ch == 1;
    
}


//====================================

//constructor
 LStack::LStack()
{
    
    t = 0;
}

 int LStack::size() const

{
    
    return  t  ;
    
}
 bool LStack::empty() const

{
    return ( t == 0 );
}

 int LStack::top() const
{
     
    return S.front();
        
}

 void LStack::push(const int &e)
{
    //address is increased
    t++;
    S.addFront(e);
}

 void LStack::pop()
{

    --t;
    S.removeFront();
    
}

bool LStack::Lcheck()
{
    return( S.check() );
}




//====================================
// global functions


int generateID()
    {
     return rand()% 9000+1000;
    }


string Lower( string x)
{
    // x.length() holds the length of the string
    for (int i = 0; i < x.length(); i++)
    {
  
        x[i] = tolower(x[i]);
        
    }
    
    return x;
}

void registerAdmin( Dlist< Admin > adminList)
{
    Admin* a = new Admin;
    a->loadAdmin();
    adminList.addElement(*a);
    
    
    Admin b;
    b = adminList.front();
    b.display();

}

void registerMember( Dlist< Member > memberList)
{
    Member* a = new Member;
    a->loadMember();
    memberList.addElement(*a);
    
    
    Member b;
    b = memberList.front();
    b.display();

}


void addFitnessClass( Dlist< FitnessClass > fitnessList )
{
    FitnessClass* a = new FitnessClass;
    a->loadClass();
    fitnessList.addElement(*a);
    
    FitnessClass b;
    b = fitnessList.front();
    b.display();
    
}

// to login
bool login(string username , string password)
{
    
    
    if (type == "admin")
    {
       
        return ( adminList.login( username ,  password) );
        
        
    }
    else if (type == "member")
    {
        
        return( memberList.login( username , password) );
        
    }
    
    else
        return false;
    
}


// wrapper functions which call the functions of the list which are the actuyal functions
void viewMemberList()
{
    memberList.display();
}

void deleteFitnessClass(int class_id)
{
    fitnessList.deleteClass( class_id);
}

void updateClassDetails(int class_id)
{
    fitnessList.updateClass(class_id);
}

void changeClassCapacity(int class_id, int new_cap)
{
    fitnessList.updateCapacity(class_id, new_cap);
}

void bookAClass(int class_id)
{
    fitnessList.bookAClass(class_id);
}

void viewClassesWithVacancies()
{
    fitnessList.viewClassesWithVacancies();
}

void viewBookingList()
{
    fitnessList.viewBookingList();
}

void cancelBooking(int class_id)
{
    fitnessList.cancelBooking(class_id);
}

void logout(int& choice)
{
    choice = -1;
    MID = 0;
    
}

// it saves the details in the files
void quitProgram()
{
    adminList.saveAdmin();
    memberList.saveMember();
    fitnessList.saveClass();
    cout<<endl<<"Data saved to the files successfully! ";
}




// i learnt the sstr for loadAdmin() and loadMember() from geeks for geeks (reference), but in the later function loadClassFile i used my own method
void loadMember()
{
    ifstream f1;
    f1.open("Members.txt",ios::in);
    
    int ID = 0;
    string fname, lname, username, password;
    string x;
    int check = 0;
    while ( getline(f1,x) )
    {
        stringstream sstr(x);
        
        while(sstr.good())
        {
            
        string substr;
        getline(sstr, substr, ',');
            
        if (check == 0)
        {
         
            ID = stoi(substr);
            check ++;
        }
            
         else if (check == 1)
         {
             
             fname = substr;
             check++;
         }
           
         else if (check == 2)
         {

             lname = substr;
             check++;
         }
         else if (check == 3)
         {
     
             username = substr;
             check++;
         }
         else if (check == 4)
         {

             password = substr;
 
            Member* a = new Member;
            a->loadMemberFile(ID, fname, lname, username, password);
            memberList.addElement(*a);
            check = 0;
                            
        }
            
        
        }
    
    }
    
    f1.close();
    
}

// loads an admin from the file
void loadAdmin()
{
    ifstream f1;
    f1.open("Admins.txt",ios::in);
    
    int ID = 0;
    string fname, lname, username, password;
    string x;
    int check = 0;
    while ( getline(f1,x) )
    {
        
        stringstream sstr(x);
        
        while(sstr.good())
        {
            
        string substr;
        getline(sstr, substr, ',');
            
        if (check == 0)
        {
         
            ID = stoi(substr);
            check ++;
        }
            
         else if (check == 1)
         {
             
             fname = substr;
             check++;
         }
           
         else if (check == 2)
         {

             lname = substr;
             check++;
         }
         else if (check == 3)
         {
     
             username = substr;
             check++;
         }
         else if (check == 4)
         {

            password = substr;
 
            Admin* a = new Admin;
            a->loadAdminFile(ID, fname, lname, username, password);
            adminList.addElement(*a);
            check = 0;
                            
        }
            
        
        }
    
    }
    
    f1.close();
}


// loads a class from the file
void loadClassFile()
{
    ifstream f1;
    f1.open("FitnessClasses.txt", ios::in);
    
    string x;
    
    while(getline(f1,x))
    {
        FitnessClass* f = new FitnessClass;
        
        int check = 0;
        string name = "" , date = "" , room = "" , time = "";
        int id = 0 , capacity = 0;
        string id_ = "" , capacity_ = "";
        
        
        for (int i = 0 ; i < x.length() ; i++)
        {
            
            if ( check == 0 && x[i] != ',' )
            {
                id_ += x[i];
                
            }
            
            else if ( check == 1 && x[i] != ',' )
            {
                
                name += x[i];
            }
            
            else if ( check == 2 && x[i] != ',' )
            {
                
                date += x[i];
            }
            
            else if ( check == 3 && x[i] != ',' )
            {
                
                time += x[i];
            }
            
            else if ( check == 4 && x[i] != ',' )
            {
                
                capacity_ += x[i];
            }
            
            else if ( check == 5 && x[i] != ',' )
            {
                
                room += x[i];
            }
            
            else if (check == 6 && x[i] == '[')
            {
                i++;
                string array[15];
                int int_array[15];
                
                int k = 0;
                
                for (int j =0 ; j<15;j++)
                {
                    array[j]="";
                    int_array[j] = 0;
                }
                
                while ( x[i] != ']' )
                {
                    if ( x[i] != ',' )
                        array[k] += x[i];
                    
                    else if ( x[i] == ',' )
                        k++;
                        
                    i++;
                }
                
                
                // converting the string digits to integer digits
                for (int count = 0; count <= k; count++)
                {
                    
                    for (int j = 0 ; j < array[count].length() ; j++)
                    {
                        int_array[count] += ( (int)array[count][j] - 48 ) * pow( 10 , array[count].length() -1 - j);
                        
                    }
                    
                    
                }
                
                // loading the integer members to the stack of the class
                for(int j = 0 ; j <= k ; j++)
                {
                    
                    f->loadStack( int_array[j] );
                
                }
            }
            
            if (x[i] == ',')
            {
                check++;
                
            }
            
        }
        
        // converting the string digits to integer digits
        for (int i = 0; i< id_.length(); i++)
        {
            
            id += ( (int)id_[i] -48 ) * pow( 10 , id_.length() -1 - i);
            
        }
        
        // converting the string digits to integer digits
        for (int i = 0; i< capacity_.length(); i++)
        {
            
            capacity += ( (int)capacity_[i] -48 ) * pow( 10 , capacity_.length() -1 - i);
            
        }
             
       
        f->loadClass( id, capacity, name, date, time, room);
        
        // adding the class to the doubly linked list
        fitnessList.addElement(*f);
        
    }
    
    f1.close();
    
}

//====================================

//functions for the doubly linked list

//====================================


template<typename a>
void Dlist<a>::addElement( a& element )
{
    Node<a>* temp = new Node<a>;
    
    temp->elem = element;
    temp -> next = head -> next;
    temp -> prev = head;
    head ->next->prev = temp;
    head ->next = temp;
    
    
}

template<typename a>
a& Dlist<a>::front()
{
    return head->next->elem;
    
}


template<typename a>
void Dlist<a>::remove( Node<a>* v )
{
   
    Node<a>* temp1 = new Node<a>;
    
    temp1 = v;
    
    temp1->next ->prev = temp1 ->prev;
    temp1-> prev->next = temp1->next;
    

}

template<typename a>
bool Dlist<a>::empty()
{
    return (head == tail);
}

// login function

template<typename a>
bool Dlist<a>::login(string username, string password)
{
  
    Node<a>* temp = new Node<a>;
    temp = head->next;
    
    int login = 0;
    while( temp != tail)
    {
        
        if(temp->elem.getUsername() == username && temp->elem.getPassword() == password )
        {
            cout<<"\nLogin successful! ";
            login = 1;
            
            //MID will store the iD of the currently logged in member
            MID = temp->elem.getID();
        }
        
        temp  = temp -> next;
    }
    
    temp = NULL;
    delete temp;

    return login == 1;
}


template< typename a>
void Dlist<a>::bookAClass(int class_id )
{
    Node<a>* temp = new Node<a>;
    temp = head->next;
    

    while( temp != tail)
    {
   
        if( temp->elem.getClassID() == class_id )
        {
            // class will be booked
            temp->elem.setClass();
        }
        
        temp  = temp -> next;
    }
    
    temp = NULL;
    delete temp;
}

template<typename a>
void Dlist<a>::display()
{
    Node<a>* temp = new Node<a>;
    temp = head->next;
    
    while( temp!= tail)
    {
        
        temp->elem.display();
        temp = temp->next;
    }
    
    temp = NULL;
    delete temp;
    
}

template<typename a>
void Dlist<a>::deleteClass(int class_id)
{
    
    Node<a>* temp = new Node<a>;
    temp = head->next;
    
    while( temp != tail)
    {
       if( temp->elem.getClassID() == class_id)
       {
           // temp (class object) will be removed from the list
           remove(temp);
       }
        
        temp = temp->next;
       
    }
    
    temp = NULL;
    delete temp;

}

template<typename a>
void Dlist<a>::updateClass(int class_id)
{
    Node<a>* temp = new Node<a>;
    temp = head->next;
    
    while( temp != tail)
    {
       if( temp->elem.getClassID() == class_id)
       {
           string choice, newValue;
           cout<<"\n What do you want to update ( room / date / time ): ";
           cin>>choice;
           cout<<"\n Enter new value: ";
           cin>>newValue;
           
           
           if ( choice == "room" )
               temp->elem.updateRoom(newValue);
           
           else if ( choice == "date" )
               temp->elem.updateDate(newValue);
           
           else if ( choice == "time" )
               temp->elem.updateTime(newValue);
               
        
       }
        
        temp = temp->next;
    }
    
    cout<<"\nClss updated! ";
    temp = NULL;
    delete temp;
    
}

template<typename a>
void Dlist<a>::updateCapacity(int class_id, int new_cap)
{
    
    Node<a>* temp = new Node<a>;
    temp = head->next;
    int capDiff;
    
    while( temp!= tail)
    {
       if( temp->elem.getClassID() == class_id)
       {
           
           // if the members booked are more than the new capacity
           if( temp->elem.returnSize() > new_cap)
           {
               // holds the difference
               capDiff = temp->elem.returnSize() - new_cap;
               cout<<"cancel";
           
               while (capDiff > 0)
               {
                   // getting the member ID to MID
                    temp->elem.getStackID();
                   // and cancelling booking for MID
                    temp->elem.cancel();
        
                    capDiff--;
                   
               }
           
           
           }
           
           // updating the capacity
               temp->elem.updateMaximumCapacity(new_cap);
       }
        
        temp = temp->next;
    }
    
    cout<<"\nClass capacity updated! ";
    temp = NULL;
    delete temp;
    
}

template<typename a>
void Dlist<a>::viewClassesWithVacancies()
{
    Node<a>* temp = new Node<a>;
    temp = head->next;
    
    while( temp!= tail)
    {
        //checks if the class if full
       if( temp->elem.checkVacancy() )
       {
           temp->elem.display();
       }
        
        temp = temp->next;
    }
    
    temp = NULL;
    delete temp;
   
}

template<typename a>
void Dlist<a>::viewBookingList()
{
    
    Node<a>* temp = new Node<a>;
    temp = head->next;
    
    while( temp!= tail)
    {
        
        if( temp->elem.checkID() )
        {
            temp->elem.display();
        }
        
        temp = temp->next;
    }
    
    temp = NULL;
    delete temp;
    

    
}

template<typename a>
void Dlist<a>::cancelBooking(int class_id)
{
    Node<a>* temp = new Node<a>;
    temp = head->next;
 
    while( temp!= tail)
    {
       if( temp->elem.getClassID() == class_id )
       {
           temp->elem.cancel();
       }
          
        temp = temp->next;
    }
    
    temp = NULL;
    delete temp;
    
    cout<<"\n Booking canceled! ";
    
}

// cancels a booking
void FitnessClass::cancel()
{
    
    int array[15];
    int i = 0;
    
    while ( stack.top() != MID )
    {
        
        array[i] = stack.top();
        i++;
        
      stack.pop();
    }
    
    if ( stack.top() == MID )
    {
        stack.pop();
    }
    
    for (int k = 0; k < i ; k++)
    {
        stack.push( array[k] );
    }
    

}

//saves to the file
template<typename a>
void Dlist<a>::saveAdmin()
{
    
    ofstream f1;
    f1.open("Admins.txt", ios::out);
    
    Node<a>* temp = new Node<a>;
    temp = head->next;

    while( temp != tail )
    {
        f1<<temp->elem.getID()<<","<<temp->elem.getFName()<<","<<temp->elem.getLName()<<","<<temp->elem.getUsername()<<","<<temp->elem.getPassword();
        f1<<endl;
        
        temp = temp -> next;
    }
    
    f1.close();
    
}

template<typename a>
void Dlist<a>::saveMember()
{
    
    ofstream f2;
    f2.open("Members.txt", ios::out);
    
    Node<a>* temp = new Node<a>;
    temp = head->next;

    while( temp != tail )
    {
        f2<<temp->elem.getID()<<","<<temp->elem.getFName()<<","<<temp->elem.getLName()<<","<<temp->elem.getUsername()<<","<<temp->elem.getPassword();
        f2<<endl;
        
        temp = temp -> next;
    }

    f2.close();

    
}

//saves the class to the file
template<typename a>
void Dlist<a>::saveClass()
{
    //sorts the classes first
    fitnessList.sort();
    
    ofstream f3;
    f3.open("FitnessClasses.txt", ios::out);
    
    Node<a>* temp = new Node<a>;
    temp = head->next;
    
    int * array1;

    while( temp != tail )
    {
        f3<<temp->elem.getClassID()<<","<<temp->elem.getClassName()<<","<<temp->elem.getClassDate()<<","<<temp->elem.getClassTime()<<","<<temp->elem.getMaximumCapacity()<<","<<temp->elem.getRoomNumber()<<",[";
       
        // array1 stores the array of members in the class
         array1 = temp->elem.save();
        
        for (int i = 0; i < arraySize - 1 ; i++)
        {
            f3<<array1[i]<<",";
            
        }
        
        f3<<array1[arraySize - 1];
        
        f3<<"]"<<endl;
        
        temp = temp -> next;
    }
    
    
    f3.close();
    
}
    
// splits the class into 2
template<typename a>
void Dlist<a>::split(int class_id, int cap)
{
    string name,date,time,room;
    
    Node<a>* temp = new Node<a>;
    temp = head->next;
    
    int capDiff = 0;
    
    while( temp!= tail)
    {
       if( temp->elem.getClassID() == class_id)
       {
           // if the number of members booked is more than the new capacity
           if( temp->elem.returnSize() > cap)
           {
               // difference
               capDiff = temp->elem.returnSize() - cap;
           }
           
       }
        
        temp = temp->next;
    }
           
    int* Array = new int[capDiff];
    temp = head->next;

    while( temp!= tail)
    {
        if( temp->elem.getClassID() == class_id)
        {
    
           
           int i = 0;
           int count = capDiff;
           
           while(count > 0)
           {
               //MID gets a value
               temp->elem.getStackID();
               
               // stores the MIDs in the array
               Array[i] = MID;
               
               i++;
               
               // MID is canceled from the class
               temp->elem.cancel();
               count--;
           }
           
           // capacity is updated
            temp->elem.updateMaximumCapacity(cap);
           
            name = temp->elem.getClassName();
            date = temp->elem.getClassDate();
            time = temp->elem.getClassTime();
            room = temp->elem.getRoomNumber();
    
       }
        
        temp = temp->next;
    }
    
    
    int ID;
    cout<<"\n Enter Class ID for the other class : ";
    cin>>ID;
    
    string choice;
    cout<<"\n Do you want to change the time and date: (yes/no)";
    cin>>choice;
    
    if(choice == "yes")
    {
        cout<<"\n Enter date: ";
        cin>>date;
        cout<<"\n Enter time: ";
        cin>>time;
        
    }
    
    // new class is added to the list
    FitnessClass* f = new FitnessClass;
    f->addSplitClass( room,  time, date, name ,  cap ,  ID);
    fitnessList.addElement(*f);
    
    int i = 0;
    while(capDiff > 0 )
    {
        // the new members stored in the array are booked for the new class
        MID = Array[i];
        i++;
        fitnessList.bookAClass( ID );
        capDiff--;
    }
    
    cout<<"\nClss split! ";
    temp = NULL;
    delete temp;
    
    
}

//sorts the classes
template<typename a>
void Dlist<a> :: sort()
{
    Node<a> * temp1 = new Node<a>;
    Node<a> * temp2 = new Node<a>;
    
    temp1 = head ->next;
    
    while (temp1 ->next != tail )
    {
        
        temp2 = temp1 -> next;
        
        while(temp2 != tail)
        {
            if(temp1->elem.getClassID() > temp2->elem.getClassID())
            {
                // swaps the two classes based on ids
                swap( temp1->elem , temp2->elem );
                
            }
            
            temp2 = temp2->next;
            
        }
        
        
        temp1 = temp1->next;
        
    }
    
    temp1 = NULL;
    temp2 = NULL;
    
    
}

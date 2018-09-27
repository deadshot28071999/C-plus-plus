#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Student
{
    private:int age;
    string first_name;
    string last_name;
    int standard;
    public:
    void set_age(int AGE)
    {   age=AGE; }
    void set_standard(int STA)
    {  standard=STA; }
    void set_first_name(string F)
    {   first_name=F; } 
    void set_last_name(string L)
    {  last_name=L; }

    int get_age()
    {   return age; }
    int get_standard()
    {   return standard; }

    string get_first_name()
    {   return first_name; }

     string get_last_name()
    {   return last_name; }
    
    void to_string()
    {       std::stringstream stream;
            int number = 14;
            stream <<age<<","<<first_name<<","<<last_name<<","<<standard;
            std::cout << stream.str();     
    }
    

};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    st.to_string();
    
    return 0;
}

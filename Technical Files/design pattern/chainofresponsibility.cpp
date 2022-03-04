class Query; //Forward declaration
/* Abstract Class */
class Staff
{
private:
    string m_name;
    Staff* m_boss;
public:
    Staff(string name)
    {
        m_name = name;
    }
    virtual void HandleQuery(Query q) = 0;
    virtual string getName()
    {
        return m_name;
    }
    virtual Staff* getBoss()
    {
        return m_boss;
    }
    virtual void setBoss(Staff* boss)
    {
        m_boss = boss;
    }
};
 
class Labour:public Staff
{
public:
    Labour(string name): Staff(name)
    {}
    virtual void HandleQuery(Query q)
    {
        if(q.getLevel() == LOW)
        {
            cout<<"Question Asked is: \""<<q.getQuestion()<<"\" is answered by "<<getName()<<endl;
            return;
        }
        cout<<"This is "<<getName()<<". Sorry I am unable to process your request. My Boss: "<< getBoss()->getName()<<" will process this request"<<endl; getBoss()->HandleQuery(q);
    }
};
 
class Supervisor:public Staff
{
public:
    Supervisor(string name): Staff(name)
    {}
    virtual void HandleQuery(Query q)
    {
        if(q.getLevel() == MEDIUM)
        {
            cout<<"Question Asked is: \""<<q.getQuestion()<<"\" is answered by "<<getName()<<endl;
            return;
        }
        cout<<"This is "<<getName()<<". Sorry I am unable to process your request. My Boss: "<< getBoss()->getName()<<" will process this request"<<endl; getBoss()->HandleQuery(q);
    }
};
 
class DepartmentHead:public Staff
{
public:
    DepartmentHead(string name): Staff(name)
    {}
    virtual void HandleQuery(Query q)
    {
        if(q.getLevel() == HIGH)
        {
            cout<<"Question Asked is: \""<<q.getQuestion()<<"\" is answered by "<<getName()<<endl;
            return;
        }
        cout<<"This is "<<getName()<<". Sorry We are unable to process your request" <<endl; 
    }
};


enum queryLevel_e{LOW, MEDIUM, HIGH};
 
class Query
{
private:
    queryLevel_e m_level;
    string m_question;
public:
    Query(string question, queryLevel_e level): m_question(question), m_level(level)
    {}
    queryLevel_e getLevel()
    {
        return m_level;
    }
    string getQuestion()
    {
        return m_question;
    }
};

int main()
{
    Labour l("Wayne Rooney");
    Supervisor s("Ryan Giggs");
    DepartmentHead d("Sir Alex Ferguson");
 
    l.setBoss(&s);
    s.setBoss(&d);
    d.setBoss(NULL);
 
    Query q1("can you finish the work?", LOW);
    Query q2("Can the team finish up the work on time?", MEDIUM);
    Query q3("Can the production department meets the target?", HIGH);
 
    l.HandleQuery(q1);
    l.HandleQuery(q2);
    l.HandleQuery(q3);
}


/*
Question Asked is: "can you finish the work?" is answered by Wayne Rooney
 
This is Wayne Rooney. Sorry I am unable to process your request. My Boss: Ryan G
iggs will process this request
Question Asked is: "Can the team finish up the work on time?" is answered by Rya
n Giggs
 
This is Wayne Rooney. Sorry I am unable to process your request. My Boss: Ryan G
iggs will process this request
This is Ryan Giggs. Sorry I am unable to process your request. My Boss: Sir Alex
 Ferguson will process this request
Question Asked is: "Can the production department meets the target?" is answered
 by Sir Alex Ferguson
 
 */
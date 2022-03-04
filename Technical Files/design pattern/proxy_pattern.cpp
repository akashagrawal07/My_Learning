/* Real Object Class */
class Election
{
public:
    void vote()
    {
        cout<<"Voting power exercised "<<endl;
    }
};
 
class Person
{
private:
    int m_age;
public:
    Person(int age): m_age(age){}
 
    int getAge()
    {
        return m_age;
    }
};

/* Proxy Class */
class ProxyElection
{
private:
    Election m_election;
    Person* m_person;
 
public:
    void castVote()
    {
        if (m_person->getAge() > 25 )
        {
            m_election.vote();
        }
        else
        {
            cout<<"Voter is too young to cast vote"<<endl;
        }
    }
    ProxyElection(Person* person): m_person(person)
    {}
};


int main()
{
    Person p1(21);
    Person p2(35);
    Person p3(46);
 
    ProxyElection pe1(&p1);
    ProxyElection pe2(&p2);
    ProxyElection pe3(&p3);
 
    pe1.castVote();
    pe2.castVote();
    pe3.castVote();
}
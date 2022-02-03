//Adeel Bhutta
//CS3520 - Fall 2021
//Last version updated: 11/8/2021
//this is code we wrote during lectures
#include <iostream>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h>
#include<limits>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include<array>
#include <cstring>
#include<typeinfo>
#include "f1.hpp"
using namespace std;
//using namespace adeel;
struct Student {
	string name = "SSSS";
	char grade = 'N';
	void print() const;
	bool operator==(const Student& o) const;
	bool operator+(const Student& o) const; //binary
	bool operator+() const; //unary
	//Student *abc;
	// int class_nums[40];
};
struct Course {
	string teacher;
	int year;
	Student std;
} cs3520, * ptr_c = &cs3520, fall2021[100];
void Student::print() const {
	cout << name << "," << grade << endl;
}
bool Student::operator==(const Student& o) const {
	return name == o.name && grade == o.grade;
}
enum class Direction { north, south, east, west };
string Dir_name(Direction d) {
	switch (d) {
	case Direction::north: return "North";
	case Direction::south: return "South";
	case Direction::east: return "East";
	case Direction::west: return "West";
	default: return "ERROR";
	}
}
//function objects (to be using in Lamdas and other higher-order 
functions)
bool is_even(int x) {
	return x % 2 == 0;
}
void print(int x) {
	cout << x << " ";
}
bool lt_three(int x) {
	return x < 3;
}
bool lt_five(int x) {
	return x < 5;
}
struct LessThan {
	int value;
	bool operator() (int x) const {
		return x < value;
	}
};
struct Accum {
	int accum = 0;
	void operator() (int x) {
		accum += x;
	}
};
//structures, unions, bit-fields
//struct abcstruct {int a, b; char c;} xxx; //size 12
//struct abcstruct {int a:24, b:2; char c;} xxx; //size 8
//union abcstruct {int a, b; char c;} xxx; //size 4
//struct abbstruct {int a:24, :0, b:2, :0; char c, :0;} xxy; //size 8
//typedef union int_or_float {int i; float f;} number;
/*
//structures with pointers
struct university {
string name;
int year;
char* location;
} neu = {"NEU", 1893, "Boston and evereywhere"}, *ptr_neu = &neu,
US_unis[7000], *ptr_unis = &US_unis[0];
*/
//double mpg (double miles, double gallons) noexcept {
double mpg(double miles, double gallons) {
	if (miles <= 0.0)
		throw invalid_argument("miles must be >0");
	if (gallons <= 0.0)
		throw invalid_argument("gallons must be >0");
	return miles / gallons;
}
double read_mpg() {
	cout << "Enter miles and gallons:" << endl;
	double miles, gallons;
	cin >> miles >> gallons;
	if (!cin) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw runtime_error("input error");
	}
	try {
		return mpg(miles, gallons);
	}
	catch (const invalid_argument& e) {
		cout << "there was a bad value input " << endl;
		throw;
	}
}
class DayOfYear {
	//private:
protected:
	int month; int day;
public:
	DayOfYear() : DayOfYear(1, 1) { cout << "default DayOfYear()" << endl; }
	DayOfYear(int m, int d) : month(m), day(d) {
		cout << "DayOfYear(int, int)" << endl;
	}
	~DayOfYear() { cout << "~DayOfYear():" << month << "/" << day << endl; }
	//void set_month(int m){ this->month = m;}
	//void set_day(int d){ this->day = d;}
	DayOfYear& set_month(int m) { this->month = m; return *this; }
	DayOfYear& set_day(int d) { this->day = d; return *this; }
	int get_month() { return month; }
	int get_day() { return day; }
	void set(int m, int d);
	void output() const;
	friend void double_members(DayOfYear&);
	friend std::ostream& operator<< (std::ostream&, DayOfYear&);
};
class Holidays : public DayOfYear {
public:
	void print() { cout << "Holiday:"; output(); }
};
std::ostream& operator<< (std::ostream& output, DayOfYear& d) {
	output << d.month << "-" << d.day << endl;
	return output;
};
void double_members(DayOfYear& d) {
	d.month *= 2;
	d.day *= 2;
};
void DayOfYear::set(int m, int d) {
	month = m;
	day = d;
}
void DayOfYear::output() const {
	cout << month << "/" << day << endl;
}
void doSoemthing() {
	throw runtime_error("something");
}
void func() {
	cout << "begin" << endl;
	DayOfYear tomorrowplus(11, 14);
	doSoemthing();
	cout << "end" << endl;
}
int main() {
	//DayOfYear today = {11,9};
	//today.month = 11;
	//today.day = 9 ;
	/*
	try{
	func();
	}
	catch(const exception & e){
	cout<<e.what()<<endl;
	}
	*/
	DayOfYear today;//(11, 12);
	//today.set_month(11);
	//today.set_day(12);
	today.set_month(11).set_day(12);
	double_members(today);
	today.output();
	cout << today << endl;
	/*
	if(true) {
	DayOfYear yesterday(11,11);
	}
	DayOfYear tomorrow(11, 13);
	//today.set(11, 9);
	today.output();
	*/
	Holidays hd;
	hd.print();
	/*
	try{
	//double  result = mpg(10, 0);
	//throw;
	double result = read_mpg();
	cout<<"mpg is "<<result<<endl;
	}
	catch(const invalid_argument & e){
	cout<<"invalid_argument: "<<e.what()<<endl;
	}
	catch(const runtime_error & e){
	cout<<"runtime_error: "<<e.what()<<endl;
	}
	catch(const exception & e) {
	cout<<"exception: "<<e.what()<<endl;
	}
	catch(...) {
	cout<<"error "<<endl;
	}
	cout<<"Hello world!"<<endl;
	*/
	/*
	//working with function objects and Lamdas
	vector<int> c = {7,6,5,4,3,2,1,0};
	//LessThan lt = {3};
	//Accum a;
	//a=for_each(c.begin(), c.end(), a);
	//cout<<a.accum<<endl;
	//cout<< count_if(c.begin(), c.end(), LessThan{4})<<endl;
	//Lamdas
	//captures []
	//bool .... (int x) {  return x<3; }
	//auto fn = [] (int x) -> bool {  return x<3; };
	int accum=0, accum_odds=0;
	auto fn = [&accum, &accum_odds] (int x) {
	accum+=x;
	if(x%2 !=0) accum_odds += x;
	};
	for_each(c.begin(), c.end(),fn);
	//for_each(c.begin(), c.end(),[&accum] (int x) { accum+=x; });
	cout<<accum<<" "<<accum_odds<<endl;
	//auto fn = [] (int x) {  return x<3; };
	//cout<< count_if(c.begin(), c.end(), fn)<<endl;
	//cout<< count_if(c.begin(), c.end(), [] (int x) {  return x<3; })<<endl;
	// for_each(c.begin(), c.end(), print);
	// cout<<endl;
	*/
	//using Heap
	/*
	vector<int> c = {17,93,22,0};
	make_heap(c.begin(), c.end());
	c.push_back(10);
	push_heap(c.begin(), c.end());
	c.push_back(104);
	push_heap(c.begin(), c.end());
	while(!c.empty()) {
	pop_heap(c.begin(), c.end());
	int i = c.back();
	c.pop_back();
	cout<<i<<endl;
	}
	*/
	//STL algorithms
	/*
	vector<int> c = {7,6,5,5,5,5,4,3,2,1,0};
	auto it = find_if(c.begin(), c.end(), is_even);
	if(it != c.end())
	cout<<"found:"<<*it<<endl;
	else
	cout<<"not found:"<<endl;
	for_each(c.begin(), c.end(), print);
	cout<<endl;
	auto it = find(c.begin(), c.end(), 3);
	if(it != c.end())
	cout<<"found:"<<*it<<endl;
	else
	cout<<"not found:"<<endl;
	*/
	//fill(c.begin(), c.end(),0);
	//replace(c.begin(), c.end(),0,3);
	//replace_if(c.begin(), c.end(),is_even,3);
	//sort(c.begin(), c.end());
	//auto it2 = remove(c.begin(), c.end(), 5);
	//c.erase(it2,c.end());
	//Working with STL
	/*
	//size(), empty(), insert(pos, val), insert(i, b, e)
	//erase(), clear()
	//caution:
	//front, back, push_back, pop_back, resize,
	//assign - replace
	//[b, e) //off the end
	list<int> nums1 {1,2,3,4,5};
	list<int> nums2 {5,6,7,8};
	list<int> nums3 {9, 10};
	cout<<nums1.size()<<" "<<nums2.size()<<endl;
	nums1.splice(nums1.begin(), nums2, ++nums2.begin(), --nums2.end());
	cout<<nums1.size()<<" "<<nums2.size()<<endl;
	list<int> nums1 {1,2,3,4,5};
	forward_list<int> nums2 {6,7,8,9};
	list<int> nums3 (nums1.begin(), nums1.end());
	cout<<&nums1<<" "<<&nums2<<endl;
	for (auto p :nums3)
	cout<<p<<" ";
	cout<<endl;
	set<string> states {"CA", "IL", "OH"};
	states.insert("IN");
	states.insert("NC");
	//states.insert("FL");
	auto iter = states.find("FL");
	if(iter == states.end())
	cout<<"not found"<<endl;
	else
	cout<<"found"<<endl;
	vector<int> nums {1,2,3,4,5};
	nums.insert(nums.begin(), 0);
	nums.insert(nums.begin(), 0);
	for(auto val : nums)
	cout<<val<<" ";
	cout<<endl;
	nums.erase(--nums.end());
	for(auto val : nums)
	cout<<val<<" ";
	cout<<endl<<"Queue"<<endl;
	queue<int> q;
	q.push(1);
	q.push(10);
	q.push(7);
	cout<<q.front()<<" "<<q.back()<<endl;
	cout<<endl<<"Map"<<endl;
	//map<string, int> states = {
	//  {"CA", 1850}, {"OR", 1859}, {"AK", 1959}
	//};
	multimap<string, int> states = {
	{"CA", 1850}, {"OR", 1859}, {"AK", 1959}
	};
	for(pair<string, int> p :states)
	cout<<p.first<<"("<<p.second<<") "<<endl;
	//states["IA"] = 1946;
	//states["IA"] = 1846;
	pair<string, int> flordia = {"FL", 1845};
	states.insert(flordia);
	states.insert(flordia);
	//int year = states["WA"];
	//cout<<endl<<year<<endl;
	for(pair<string, int> p :states)
	cout<<p.first<<"("<<p.second<<") "<<endl;
	//count()
	map<string, int> states1 {{"CA", 1850}, {"OR", 1859}, {"AK", 1959}};
	for(pair<string, int> p : states1)
	cout<<p.first<<"("<<p.second<<") ";
	states1["IA"] = 1946;
	states1["IA"] = 1846;
	pair<string, int> florida = {"FL", 1845};
	states1.insert(florida);
	states1.insert(florida);
	int year = states1["NC"];
	cout<<endl;
	for(pair<string, int> p : states1)
	cout<<p.first<<"("<<p.second<<") ";
	cout<<endl;
	auto it = states1.find("NC");
	if(it == states1.end())
	cout<<"not found"<<endl;
	else
	cout<<"found"<<endl;
	map<string, vector<int>> student_grades;
	student_grades["Adeel"] = {67, 33, 100};
	student_grades["Jacky"] = {100, 99, 100};
	for(auto grades:student_grades) {
	cout<<grades.first<<": ";
	for (auto grade : grades.second)
	cout<<grade<<",";
	cout<<endl;
	}
	*/
	//student_grades["Adeel"][1]
	//enums
	Direction d1 = Direction::north;
	cout << Dir_name(d1) << endl;
	cout << static_cast<int>(d1) << endl;
	cout << Dir_name(static_cast<Direction>(5)) << endl;
	//Structures
	/*
	Student s1;
	s1.name = "Cindy";
	s1.grade = 'A';
	s1.print();
	Student s2 = {"Adeel", 'F'};
	s2.print();
	Student s3 = s2;
	cout<<s3.name<<","<<s3.grade<<endl;
	if (s1==s1)//(s1.equals(s1)) //s1==s2
	cout<<"equal"<<endl;
	else
	cout<<"not equal"<<endl;
	*/
	//A structure instance is passed to a function by value of its members.
	//An array of structure instances
	/*
	Student students[10] = {};
	students[0] = s1;
	students[3] = s2;
	students[5] = s3;
	for (auto s:students)
	cout<<s.name<<","<<s.grade<<endl;
	string ss1 = "";
	cout<<"size str:"<<sizeof(ss1)<<endl;
	cout<<"size struct:"<<sizeof(s1)<<endl;
	cout<<"mem:"<<&students[0]<<","<<&students[1]<<endl;
	//a vector of structure instances
	vector<Student> v1(10);
	v1.push_back(s1);
	v1.push_back(s2);
	v1.push_back(s3);
	for (auto s:v1)
	cout<<s.name<<","<<s.grade<<endl;
	Student & s4 = s3;
	/*
	Course cs3520, *ptr_c = &cs3520, fall2021[100], *fall[10], (*one) [5];
	Course* pst = new Course {"Adeela", 2021};
	//pst->teacher = "Adeel";
	cout<<pst->teacher<<endl;
	Course* manyst = new Course[10];
	manyst[0].teacher="Adeel";
	(*(manyst+1)).teacher="Adeel";
	cout<<"size str:"<<sizeof(cs3520)<<endl;
	cout<< neu.name<<" "<<neu.year<<" "<<neu.location<<endl;
	//  cout<< neu->name<<" "<<neu->year<<" "<<neu->location<<endl;
	cout<< (*ptr_neu).name<<" "<<(*ptr_neu).year<<"
	"<<(*ptr_neu).location<<endl;
	cout<< ptr_neu->name<<" "<<ptr_neu->year<<" "<<ptr_neu->location<<endl;
	cout<<(*ptr_neu).location[7]<<endl;
	*/
	//fall2021[100], *fall[10];
	//fall2021[0].teacher = "AdeelB";
	//(*fall[0]).teacher= "AdeelC";
	//(*one)[0].teacher = "AdeelD";
	//cout<<s1<<endl;
	//students[0].class_nums[0]
	//unions
	numbers a, b, c;
	a.i = 4444;
	cout << a.i << " " << a.ch << endl;
	a.ch = 'A';
	cout << a.i << " " << a.ch << endl;
	cout << "size:" << sizeof(a) << endl;
	//bit fields
	struct abc { unsigned int aa : 1, bb : 16, cc : 8; } x;
	cout << sizeof(x) << endl;
	struct abcwo { unsigned int aa, bb, cc; } xx;
	cout << sizeof(xx) << endl;
	//cout<<"sizestr: "<<sizeof(xxx)<<endl;
	//cout<<"sizestr: "<<sizeof(xxy)<<endl;
	/*
	number a;
	a. i=444;
	cout<<a.i<<","<<a.f<<endl;
	a. f=444;
	cout<<a.i<<","<<a.f<<endl;
	*/
	//difference between array and &array
	int arr[5] = { 1,2,3,4 };
	printf("array=%p : &array=%p\n", arr, &arr);
	cout << "array+1 = " << (arr + 1) << " : &array + 1 = " << (&arr + 1) << endl;
	int* p = arr;
	cout << &arr << "," << &arr[0] << "," << arr << endl;
	cout << sizeof(arr) << "," << sizeof(*p) << endl;
	//array of pointers
	int* p1[5] = { arr, arr, arr, arr, arr };
	cout << *p1 << "," << &arr[0] << "," << p1 << endl;
	cout << sizeof(*arr) << "," << sizeof(*p1) << endl;
	//pointer to an array
	int(*p2)[5] = &arr;
	cout << *p2 << "," << &arr[0] << "," << p2 << endl;
	cout << sizeof(*arr) << "," << sizeof(*p2) << endl;
	int arr[5] = { 1,2,3,4,5 };
	cout << arr << " " << arr + 1 << endl;
	cout << &arr << " " << &arr + 1 << endl;
	int size_of_array = *(&arr + 1) - arr;
	cout << size_of_array << endl;
	//arr=&arr[0] is address of 1st integer
	//&arr is the address of array of 5 ints.
	int* pt0[5] = { arr, arr, arr, arr, arr }; //array of 5 integer pointers
	int(*pt1)[5] = &arr; //1 pointer to an array of 5 integers
	//double pointers
	const char* titles[] = { "A Tale of two world", "Wuthering Heights",
	"Hamlet", "Odyssey" };
	cout << **titles << endl; //A from A Tale
	cout << titles[2][2] << endl; //a from hamlet
	cout << *(*(titles + 1) + 4) << endl; // h from Wuthering
	//working with c-string
	//NULL character at the end .... '\0', ASCII num 0
	/*
	char ch = '\0'; //'A';
	char ch1[] = {0}; //NULL
	char ch2[] = {'\0'}; //NULL
	char chh[] = {'1','2','3','4','5'};
	char chhhh[] = "Hello";
	char chhhhh[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	char chhhhhh[15] = "Hello";
	cout<<"Sizes: "<<sizeof(chhhhhh)<<" "<<strlen(chhhhhh)<<endl;
	for (int i=0; i<sizeof(ch1); ++i)
	cout<< static_cast<int>(ch1[i]) <<" ";
	cout<<endl;
	cout<<endl;
	//reading with getline
	int x = 5;
	char str[8];
	cout<<x<<endl;
	//cin>>str;
	cin.getline(str, 8);
	cout<<str<<endl;
	cout<<x<<endl;
	//c-string functions
	char st1[] = "Hello";
	char st2[] = "Worldddddd";
	//char st3 = st1+st2;
	cout<<strncat(st1, st2, 3)<<endl;
	//cout<<strcmp(st2,st1)<<endl;
	//using cstring with pointer
	char strr[] = "Today is Friday, Yayyyyyy!";
	char *pp = strr;
	int i=0;
	while(strr[i] != '\0')
	{
	cout<< strr[i]<< " ";
	i++;
	}
	cout<<endl;
	while(*pp)
	{
	cout<< *pp<< " ";
	pp++;
	}
	const char *ppp = "Hello World" +3;
	cout<<ppp<<endl;
	//example of strtok
	cout<<endl;
	char sttt[] = "What's up people!";
	unsigned int len = strlen(sttt);
	cout<<sttt<<endl;
	const char delim[] = " ";
	char * tok = strtok(sttt, delim);
	while(tok){
	cout<<tok<<endl;
	tok = strtok(nullptr, delim);
	}
	*/
	//cout<<tok<<endl;
	//cout<<sttt<<endl;
	//cout<<tok<<endl;
	/*
	//pointer arithmetic
	int x=100;
	int &y = x; //reference variables
	cout<<x<<","<<y<<endl;
	cout<<&x<<","<<&y<<endl;
	int *p = &x;
	cout<<p<<endl;
	p+=2;
	cout<<p<<" "<<endl;
	//functions, methods, procedures
	//arrays vs vector
	int arr[6] = {1,2,3,4,5,69};
	array<int, 6> arr1 = {1,2,3,4,5,69};
	vector<int> v1 = {1,2,3,4,5,69};
	cout<<v1.size()<<endl;
	//using iterator
	for(auto it = v1.begin(); it != v1.end(); ++it)
	cout<<*it<<" ";
	cout<<endl;
	//using 3d array
	int mat[5][4][3] {};
	for(int i=0;i<5;i++)
	for(int j=0;j<4;j++)
	for(int k=0;k<3;k++)
	mat[i][j][k] = i+j+k;
	for(int i=0;i<5;i++) {
	for(int j=0;j<4;j++) {
	for(int k=0;k<3;k++)
	cout<<mat[i][j][k]<<" ";
	cout<<endl;
	}
	cout<<endl;
	}
	int *p = &mat[0][0][0];
	for(int i=0;i<5*4*3; i++)
	cout<< *(p+i) << " ";
	*/
	/*
	//using your own namespace
	adeel::f1();
	adeel::f1(1);
	//adeel::f1(1.0);
	max::f2(1);
	adeel::f2(1, "Helllllllllllllooooooo");
	*/
	/*
	//pass by reference
	int xyz=100;
	int *p = &xyz;
	cout<<"xyz:"<<&xyz<<endl;
	cout<<"Out:"<<myFunc(&xyz)<<endl;
	cout<<"xyz:"<<xyz<<endl;
	//passing array to function
	int aaa[5][4] = {1,2,3,4};
	print_me(aaa, 5);
	cout<<endl;
	for(int i=0;i<5;++i) cout<<aaa[i]<<" ";
	// arrays and addresses
	int arr[5] = {1,2,3,4,5};
	//cout<<&arr[0]<<" "<<arr<<endl;
	int* p_arr = arr;
	cout<<&arr[0]<<" "<<arr<<" "<<p_arr<<endl;
	cout<<arr[0]<<" "<<p_arr[0]<<" "<<*p_arr<<" "<<*arr<<endl;
	p_arr++;
	//arr++:
	cout<<arr[1]<<" "<<p_arr[1]<<" "<<*(p_arr+0)<<" "<<*(arr+1)<<endl;
	*/
	/*
	//using a vector
	vector<int> v1;
	vector<string> v2 = {"Hello", "Hi", "Bye", "Friday"};
	vector<char> v3(5);
	v1.push_back(1);
	v1.push_back(10);
	v1.push_back(23);
	cout<<v1.size()<<","<<v2.size()<<","<<v3.size()<<endl;
	v3.at(1) = 'A';
	v3[4] = 'b';
	for (auto i : v2)
	cout<<i<<" ";
	cout<<endl;
	v2.insert(v2.begin()+3,"Weekend");
	for (int i=0; i<v2.size(); ++i)
	cout<<v2.at(i)<<" ";
	cout<<endl;
	v1.resize(10,123);
	for (auto i : v1)
	cout<<i<<" ";
	cout<<endl;
	//for (int i=0; i<=v1.size(); ++i)
	// cout<<v1.at(i)<<" ";
	//cout<<endl;
	//Example of 2D arrays or vector of vectors
	int arr2[5][4] = { {1,2,3}, {4,5,6}, {12,9,10,11}};
	for(auto& row:arr2) {
	for(auto j:row)
	cout<<j<<" ";
	cout<<endl;
	}
	vector <vector<int>> vv;
	vector<int> v = {1,2,3,4};
	for(int ii=0;ii<5;++ii)
	vv.push_back(v);
	for(auto& row:vv) {
	for(auto j:row)
	cout<<j<<" ";
	cout<<endl;
	}
	for(int ii=0;ii<5;++ii) {
	for (int jj=0; jj<4; ++jj)
	cout<<vv[ii][jj]<<" ";
	cout<<endl;
	}
	*/
	//CPP Coersion Rules
	//1. char, short, unsigned char ...... are automatically promoted to 
	........ int
		//2. others go from lower ranking to higher ranking (promoted)
		//Ranking: int -> unsigned int -> long -> unsigned long -> float -> double 
		-> long double.
		//final value is converted to the type that it is being assigned to 
		(demote if needed).
		//{char} = {unsigned int} vs {int}
		//file reading options
		//fstream file_name;
		//file_name.open("in.txt", ios::in);
		//ios.in - read
		//ios.out - write
		//ios.app - apend
		/*
		//example reading and writing file
		ifstream infile("in.txt");
		if(!infile){
		cout<<"can't open the file in.txt"<<endl;
		return EXIT_FAILURE;
		}
		string line;
		while(getline(infile, line)) {
		cout<<line<<endl;
		}
		ofstream outfile("out.txt");
		if(!outfile){
		cout<<"can't open the file out.txt"<<endl;
		return EXIT_FAILURE;
		}
		while(outfile && getline(infile, line)) {
		cout<<line<<endl;
		outfile<<line<<endl;
		}
		//conversion between strings and stringstreams
		//istringstream istr("1 2 3 4");
		string str = "1 2 3 4";
		istringstream istr(str);
		int i;
		while(istr>>i) {cout<<i<<endl;}
		ostringstream ostr;
		for(int i=0;i<4;++i){
		ostr<<i<<(i+1<4?",":"");
		}
		cout<<"string is "<<ostr.str()<<endl;
		*/
		/*
		//preserving format flags/options and restoring them
		ios_base::fmtflags orig_flags = cout.flags();
		double x;
		cout<<fixed<<setprecision(2)<<setw(8);
		while(cin>>x){
		cout<<x<<endl;
		}
		cout.flags(orig_flags);
		*/
		/*
		//example of how to use error bits
		int x=0;
		while(true){
		cout<<"enter a number:"<<endl;
		cin>>x;
		if(cin.good()) {break;}
		else if (cin.bad()) {
		cout<<"unrecoverable error"<<endl;
		return EXIT_FAILURE;
		}
		else if (cin.eof()) {
		cout<<"goodbye!"<<endl;
		return EXIT_SUCCESS;
		}
		else if (cin.fail()) {
		cout<<"please try again"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//return EXIT_FAILURE;
		}
		else{
		cout<<"unknown error or state"<<endl;
		return EXIT_FAILURE;
		}
		}
		cout<<"number is :"<<x<<endl;
		*/
		//checking different error bits
		// cout<<cin.bad()<<cin.fail()<<cin.eof()<<cin.good()<<endl;
		// cin.good(); cin.eof(); cin.fail(); cin.bad();
		// cin.failbit; cin.goodbit
		/*
		// printing value,address and size of variable
		int x;
		cin>>x;
		cout << "Value: "<<x<<", Address: "<< &x <<endl;
		cout<<sizeof(int)<<endl;
		// intro to pointer, basic example
		int* ptrx;
		ptrx = &x;
		cout<<sizeof(int*)<<endl;
		cout<<&ptrx<<endl;//address or refere
		cout<<ptrx<<endl;//contents
		cout<<*ptrx<<endl;
		//Pointer is a container for memory address.
		//different ways of declaring pointer variable
		int* ptry;
		int *ptry;
		int*ptry
		int * ptry;
		*/
		/*
		//writing for loop with multiple iterators
		for(int i=20, j =10; i>0 &&j>0; i-=2, j-=2){
		cout<<--i<<" ";
		j--;
		}
		cout<<endl;
		*/
		/*
		//counting chars from input string
		string str = "";
		cin>>str;
		int i=0; char ch;
		while(i<str.size() && (ch= str.at(i)) != '\n')
		{
		cout<<ch<<" ";
		i++;
		}
		*/
		/*
		// printing chars from string with range-based loop
		cout<<endl;
		for (char ch : str)
		cout<<ch;
		*/
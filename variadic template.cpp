#include<iostream>
#include<string>

// �������� ���ø��� �׻� ����Լ� ���·� ����.

//template <typename T> //���⼭ �μ��� �ϳ��� ó���Ѵ�.
//void print(T arg) {
//	std::cout << arg << std::endl;
//}
//
//template <typename T, typename... Types>  // typename... ���� ...�� ���ø� �Ķ������ �̶�� �Ѵ�. ����Ͽ� �μ��� �ϳ��� �޴� �Լ��� ����(���) ����
//void print(T arg, Types... args) {
//	std::cout << arg << ", ";
//	print(args...);
//}

// ���� 1
//template <typename string>
//std::string StrCat(const string& s) {
//	return std::string(s);
//}
//template <typename string, typename... strings>
//std::string StrCat(const string& s, strings... strs) {
//	return std::string(s) + StrCat(strs...);
//}

//����2
//size_t GetStringSize(const char* s) { return strlen(s); } // ����Լ� ���Ḧ ���� �Լ�
//size_t GetStringSize(const std::string& s) { return s.size(); } //��������
//template<typename String, typename... Strings>
//size_t GetStringSize(const String& s, Strings... strs) {
//	return GetStringSize(s) + GetStringSize(strs...);
//}
//void AppendToString(std::string* concat_str) { return; } //��������
//template<typename String, typename... Strings>           // template�Ʒ����� �Ѱ��� �Լ��� ���� ����
//void AppendToString(std::string* concat_str, const String& s, Strings... strs) {
//	concat_str->append(s);
//	AppendToString(concat_str, strs...);
//}
//template<typename String, typename... Strings> 
//std::string StrCat(const String& s, Strings... strs) {
//	size_t total_size = GetStringSize(s, strs...);
//	std::string concat_str;
//	concat_str.reserve(total_size);
//	concat_str = s;
//	AppendToString(&concat_str, strs...);
//	return concat_str;
//}

//����3
//int sum_all() { return 0; } // ��������
//template<typename... Ints>
//int sum_all(int num, Ints... nums) {
//	return num + sum_all(nums...);
//}
//
//template<typename... Ints>
//double average(Ints... nums) {
//	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
//}

////���� 4
//// TMP ���ø���Ÿ���α׷���
//// ���α׷��� ����Ǵ� ������ �ƴ� ������ �ϴ� �κп��� ���ȴ�.
//// �̹� ������ �ϴ� ���� ���� ������ �ȴ�.
//// �� �Լ����� ��͸� �ϰ� �Ʒ��Լ����� ���������� ��Ÿ����. 
//template<int x, int y>
//struct GCD {
//	static const int value = GCD<y, x%y>::value;
//};
////��������
//// y�� 0�� �Ǿ��� ��쿡 ����ȴ�.
//template<int x>
//struct GCD<x,0>{
//	static const int value = x;
//};
////���� 4.5
//template<int N, int D=1>
//struct Ratio {
//	typedef Ratio<N, D> type; // ����Լ�
//	static const int num = N;
//	static const int den = D;
//};
//template <class R1, class R2>
//struct _Ratio_add {
//	typedef Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den>type; 
//};
//template <class R1, class R2>
//struct Ratio_add : _Ratio_add<R1,R2>::type{};

////using �� ����� ����
//template<int x, int y>
//struct GCD {
//	static const int value = GCD<y, x% y>::value; //���
//};
//template<int x>
//struct GCD<x, 0> {
//	static const int value = x;
//};
//template<int N, int D = 1>
//struct Ratio {
//private:
//	const static int _gcd = GCD<N, D>::value; // GCD �� value�� ����Ѵ�.
//public:
//	typedef Ratio<N/_gcd, D/_gcd> type; 
//	static const int num = N / _gcd;
//	static const int den = D / _gcd;
//};
//template <class R1, class R2> //add
//struct _Ratio_add {
//	using type = Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den>;
//};
//template <class R1, class R2>
//struct Ratio_add : _Ratio_add<R1, R2>::type {};
//template <class R1, class R2> // subtract
//struct _Ratio_subtract {
//	using type = Ratio<R1::num* R2::den - R2::num * R1::den, R1::den* R2::den>;
//};
//template <class R1, class R2>
//struct Ratio_subtrack : _Ratio_subtract<R1, R2>::type {};
//template <class R1, class R2> // multiply
//struct _Ratio_multiply {
//	using type = Ratio<R1::num* R2::num, R1::den* R2::den>;
//};
//template <class R1, class R2>
//struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};
//template <class R1, class R2> //divide
//struct _Ratio_divide {
//	using type = Ratio<R1::num* R2::den, R1::den* R2::num>;
//};
//template <class R1, class R2>
//struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

//�����غ���1
//template<int N>
//struct fib {
//	static const int result = fib<N - 1>::result + fib<N - 2>::result;
//};
//template<>
//struct fib<1>
//{
//	static const int result = 1;
//};
//template<>
//struct fib<2>
//{
//	static const int result = 1;
//};


//int main() {
//	// ���� 1,2
//	//std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"), " ", std::string("sentence")); 
//	
//	//���� 3
//	//std::cout << average(1, 23, 4, 5, 6) << std::endl; 
//	
//	//���� 4
//	//std::cout << "gcd (36,24) :: " << GCD<36, 24>::value << std::endl;
//	
//	// ���� 4.5
//	//typedef Ratio<2, 3> rat;
//	//typedef Ratio<3, 2> rat2;
//	//typedef Ratio_add<rat, rat2> rat3;
//	//std::cout << rat3::num << "/" << rat3::den << std::endl; 
//	
//	//using �� ����� ����
//	/*using r1 = Ratio<2, 3>;
//	using r2 = Ratio<3, 2>;
//	using r3 = Ratio_add<r1, r2>;
//	std::cout << "2/3 + 3/2 = " << r3::num << "/" << r3::den << std::endl;
//	using r4 = Ratio_subtrack<r1, r2>;
//	std::cout << "2/3 - 3/2 = " << r4::num << "/" << r4::den << std::endl;
//	using r5 = Ratio_multiply<r1, r2>;
//	std::cout << "2/3 * 3/2 = " << r5::num << "/" << r5::den << std::endl;
//	using r6 = Ratio_divide<r1, r2>;
//	std::cout << "2/3 / 3/2 = " << r6::num << "/" << r6::den << std::endl;*/
//
//	//�����غ���
//	/*std::cout << "6 ��° �Ǻ���ġ �� : " << fib<6>::result << std::endl;*/
//
//}
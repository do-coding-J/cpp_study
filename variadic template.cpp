#include<iostream>
#include<string>

// 가변길이 템플릿은 항상 재귀함수 형태로 구성.

//template <typename T> //여기서 인수를 하나씩 처리한다.
//void print(T arg) {
//	std::cout << arg << std::endl;
//}
//
//template <typename T, typename... Types>  // typename... 에서 ...은 템플릿 파라미터팩 이라고 한다. 재귀하여 인수를 하나만 받는 함수를 연속(재귀) 실행
//void print(T arg, Types... args) {
//	std::cout << arg << ", ";
//	print(args...);
//}

// 예시 1
//template <typename string>
//std::string StrCat(const string& s) {
//	return std::string(s);
//}
//template <typename string, typename... strings>
//std::string StrCat(const string& s, strings... strs) {
//	return std::string(s) + StrCat(strs...);
//}

//예시2
//size_t GetStringSize(const char* s) { return strlen(s); } // 재귀함수 종료를 위한 함수
//size_t GetStringSize(const std::string& s) { return s.size(); } //종료조건
//template<typename String, typename... Strings>
//size_t GetStringSize(const String& s, Strings... strs) {
//	return GetStringSize(s) + GetStringSize(strs...);
//}
//void AppendToString(std::string* concat_str) { return; } //종료조건
//template<typename String, typename... Strings>           // template아래에는 한가지 함수만 정의 가능
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

//예시3
//int sum_all() { return 0; } // 종료조건
//template<typename... Ints>
//int sum_all(int num, Ints... nums) {
//	return num + sum_all(nums...);
//}
//
//template<typename... Ints>
//double average(Ints... nums) {
//	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
//}

////예시 4
//// TMP 템플릿메타프로그래밍
//// 프로그램이 실행되는 도중이 아닌 컴파일 하는 부분에서 계산된다.
//// 이미 컴파일 하는 순간 값을 가지게 된다.
//// 위 함수에서 재귀를 하고 아래함수에서 종료조건을 나타낸다. 
//template<int x, int y>
//struct GCD {
//	static const int value = GCD<y, x%y>::value;
//};
////종료조건
//// y가 0이 되었을 경우에 실행된다.
//template<int x>
//struct GCD<x,0>{
//	static const int value = x;
//};
////예시 4.5
//template<int N, int D=1>
//struct Ratio {
//	typedef Ratio<N, D> type; // 재귀함수
//	static const int num = N;
//	static const int den = D;
//};
//template <class R1, class R2>
//struct _Ratio_add {
//	typedef Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den>type; 
//};
//template <class R1, class R2>
//struct Ratio_add : _Ratio_add<R1,R2>::type{};

////using 을 사용한 버전
//template<int x, int y>
//struct GCD {
//	static const int value = GCD<y, x% y>::value; //재귀
//};
//template<int x>
//struct GCD<x, 0> {
//	static const int value = x;
//};
//template<int N, int D = 1>
//struct Ratio {
//private:
//	const static int _gcd = GCD<N, D>::value; // GCD 의 value를 사용한다.
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

//생각해보기1
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
//	// 예시 1,2
//	//std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"), " ", std::string("sentence")); 
//	
//	//예시 3
//	//std::cout << average(1, 23, 4, 5, 6) << std::endl; 
//	
//	//예시 4
//	//std::cout << "gcd (36,24) :: " << GCD<36, 24>::value << std::endl;
//	
//	// 예시 4.5
//	//typedef Ratio<2, 3> rat;
//	//typedef Ratio<3, 2> rat2;
//	//typedef Ratio_add<rat, rat2> rat3;
//	//std::cout << rat3::num << "/" << rat3::den << std::endl; 
//	
//	//using 을 사용한 버전
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
//	//생각해보기
//	/*std::cout << "6 번째 피보나치 수 : " << fib<6>::result << std::endl;*/
//
//}
//#include<iostream>
//#include"utility.h"
//
//class Cell {
//protected:
//	int x, y;
//	Table* Table;
//
//	std::string data;
//
//public:
//	virtual std::string stringify() { return data; }
//	virtual int to_numeric() { return 0; }
//
//	Cell(std::string data, int x, int y, Table* table) :data(data), x(x), y(y), table(table) {}
//};
//
//class Table
//{
//protected:
//	int max_row_size, max_col_size;
//
//	Cell*** data_table;
//
//public:
//	Table(int max_row_size, int max_col_size);
//	~Table();
//
//	void reg_cell(Cell* c, int row, int col);
//
//	int to_numeric(const std::string& s);
//	int to_numeric(int row, int col);
//
//	std::string stringify(const std::string& s);
//	std::string stringify(int ros, int col);
//
//	virtual std::string print_table() = 0;
//
//};
//
//Table::Table(int max_row_size, int max_col_size) : max_row_size(max_row_size), max_col_size(max_col_size)
//{
//	data_table = new Cell * *[max_row_size];
//	for (int i = 0; i < max_row_size; i++) {
//		data_table[i] = new Cell * [max_col_size];
//		for (int j = 0; j < max_col_size; j++) {
//			data_table[i][j] = NULL;
//		}
//	}
//}
//
//Table::~Table()
//{
//	for (int i = 0; i < max_row_size; i++) {
//		for (int j = 0; j < max_col_size; j++) {
//			if (data_table[i][j]) delete data_table[i][j];
//		}
//	}
//	for (int i = 0; i < max_row_size; i++) {
//		delete[] data_table[i];
//	}
//	delete[] data_table;
//}
//
//void Table::reg_cell(Cell* c, int row, int col)
//{
//	if (!(row < max_row_size && col < max_col_size)) return;
//	if (data_table[row][col]) delete data_table[row][col];
//	data_table[row][col] = c;
//}
//
//int Table::to_numeric(const std::string& s)
//{
//	int col = s[0] - 'A';
//	int row = atoi(s.c_str() + 1) - 1;
//
//	if (row < max_row_size && col < max_col_size) {
//		if (data_table[row][col]) {
//			return data_table[row][col]->to_numeric();
//		}
//	}
//}
//
//int Table::to_numeric(int row, int col)
//{
//	if (row < max_row_size && col < max_col_size && data_table[row][col]) {
//		return data_table[row][col]->to_numeric();
//	}
//	return 0;
//}
//
//std::string Table::stringify(const std::string& s) {
//	int col = s[0] - 'A';
//	int row = atoi(s.c_str() + 1) - 1;
//
//	if (row < max_row_size && col < max_col_size) {
//		if (data_table[row][col]) {
//			return data_table[row][col]->stringify();
//		}
//	}
//	return 0;
//}
//std::string Table::stringify(int row, int col) {
//	if (row < max_row_size && col < max_col_size && data_table[row][col]) {
//		return data_table[row][col]->stringify();
//	}
//	return "";
//}
//
//std::ostream& operator<< (std::ostream& o, Table& table) {
//	o << table.print_table();
//	return o;
//}
//
//class TxtTable : public Table {
//	std::string repeat_char(int n, char c);
//	std::string col_num_to_str(int n);
//
//public:
//	TxtTable(int row, int col);
//	std::string print_table();
//};
//TxtTable::TxtTable(int row, int col) : Table(row, col) {}
//
//std::string TxtTable::print_table() {
//	std::string total_table;
//
//	int* col_max_wide = new int[max_col_size];
//	for (int i = 0; i < max_col_size; i++) {
//		unsigned int max_wide = 2;
//		for (int j = 0; j < max_row_size; j++) {
//			if (data_table[j][i] &&
//				data_table[j][i]->stringify().length() > max_wide) {
//				max_wide = data_table[j][i]->stringify().length();
//			}
//		}
//		col_max_wide[i] = max_wide;
//	}
//	total_table += "    ";
//	int total_wide = 4;
//	for (int i = 0; i < max_col_size; i++) {
//		if (col_max_wide[i]) {
//			int max_len = max(2, col_max_wide[i]);
//			total_table += " | " + col_num_to_str(i);
//			total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');
//
//			total_wide += (max_len + 3);
//		}
//	}
//
//	total_table += "\n";
//	for (int i = 0; i < max_row_size; i++) {
//		total_table += repeat_char(total_wide, '-');
//		total_table += "\n" + to_string(i + 1);
//		total_table += repeat_char(4 - to_string(i + 1).length(), ' ');
//
//		for (int j = 0; j < max_col_size; j++) {
//			if (col_max_wide[j]) {
//				int max_len = max(2, col_max_wide[j]);
//
//				std::string s = "";
//				if (data_table[i][j]) {
//					s = data_table[i][j]->stringify();
//				}
//				total_table += " | " + s;
//				total_table += repeat_char(max_len - s.length(), ' ');
//			}
//		}
//		total_table += "\n";
//	}
//
//	return total_table;
//}
//
//std::string TxtTable::repeat_char(int n, char c) {
//	std::string s = "";
//	for (int i = 0; i < n; i++) s.push_back(c);
//
//	return s;
//}
//
//std::string TxtTable::col_num_to_str(int n) {
//	std::string s = "";
//	if (n < 26) {
//		s.push_back('A' + n);
//	}
//	else {
//		char first = 'A' + n / 26 - 1;
//		char second = 'A' + n % 26;
//
//		s.push_back(first);
//		s.push_back(second);
//	}
//
//	return s;
//}
//
//int main() {
//	MyExcel::TxtTable table(5, 5);
//	std::ofstream out("test.txt");
//
//	table.reg_cell(new Cell("Hello~", 0, 0, &table), 0, 0);
//	table.reg_cell(new Cell("C++", 0, 1, &table), 0, 1);
//
//	table.reg_cell(new Cell("Programming", 1, 1, &table), 1, 1);
//	std::cout << std::endl << table;
//	out << table;
//}
#pragma once
#include <iostream>

class String
{
	char* _data;
	size_t _length;

	void copyFrom(const String& data);
	void free();
	explicit String(size_t capacity); 
public:
	String();
	String(const char* data);
	String(const String& other);
	String& operator=(const String& other);
	~String();
	String(String&& other) noexcept;
	String& operator=(String&& other) noexcept;
	size_t length() const;
	String& operator+=(const String& other);
	String substr(size_t begin, size_t howMany) const;
	char& operator[](size_t index);
	char operator[](size_t index) const;
	const char* c_str() const;
	friend String operator+(const String& lhs, const String& rhs);
	friend std::istream& operator>>(std::istream&, String& str);
};

std::ostream& operator<<(std::ostream& os, const String& str);
bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);


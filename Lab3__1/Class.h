struct Points {
	double x, y;
};

class Broken {
private:
	Points* data;
	int cap, n;
	void memory();

public:
	Broken();
	Broken(const int cap);
	~Broken();
	Broken(const Broken&);
	double len_broken();
	Broken operator +(const Broken&);
	void operator +=(const Broken&);
	bool operator ==(const Broken&);
	void operator <<(const Points&);
	void operator >>(const Points&);
	Points& operator [](int);
	int get_cap() const;
	int get_n() const;
	void operator =(const Broken&);
	void set_n();
};
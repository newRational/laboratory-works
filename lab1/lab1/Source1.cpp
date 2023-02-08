namespace lab1 {
	bool isValidNum(int &num) {
		return num > 0;
	}

	bool isGoodCin(std::istream &cin) {
		return cin.good();
	}

	bool isValidInput(std::istream &cin, int &num) {
		return isGoodCin(cin) && isValidInput(num);
	}

	void readInt(int &num) {
		int num;
		std::cin >> num;
	}

	int getInt() {
		int num;

		do readInt(num);
		while (!isValidInput(std::cin, num));
	}
}
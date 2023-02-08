#include <iostream>

namespace lab1 {
	struct Cell {
		int index;
		Cell *next;
		int value;
	};

	int getCellIndex(Cell* cell) {
		return cell->index;
	}

	int getCellValue(Cell* cell) {
		return cell->value;
	}

	struct Row {
		int index;
		Row* next;
		Cell* cells;
		int cellsCount;
	};

	struct Matrix {
		int m, n;
		Row *head;
		Row *tail;
	};

	void printCell(Cell* cell, int rowIndex) {
		std::cout << "(" << rowIndex << "," << cell->index << ": " << cell->value << ")\t" << std::flush;
	}

	void printRow(Row *row) {
		Cell* cell = row->cells;
		while (cell) {
			printCell(cell, row->index);
			cell = cell->next;
		}
		std::cout << std::endl;
	}

	void printMatrix(Matrix* matrix) {
		if (!matrix->head) {
			std::cout << "Empty matrix\n" << std::endl;
			return;
		}

		Row *row = matrix -> head;
		while (row) {
			printRow(row);
			row = row->next;
		}

		std::cout << std::endl;
	}

	Cell *createCell(int index, int value) {
		Cell *cell = new Cell;

		cell->index = index;
		cell->next = nullptr;
		cell->value = value;

		return cell;
	}

	Row* createRow(int index = 0) {
		Row *row = new Row;

		row->cells = nullptr;
		row->cellsCount = 0;
		row->index = index;
		row->next = nullptr;

		return row;
	}

	Matrix* createMatrix() {
		Matrix* matrix = new Matrix;

		matrix->head = nullptr;
		matrix->tail = nullptr;

		return matrix;
	}

	template <class T>
	void deleteInstance(T *instance) {
		delete instance;
	}

	template <class T>
	bool exists(T *element, int index) {
		return element->index == index;
	}

	template <class T>
	T *search(T* element, int index) {
		while (element->next && element->next->index <= index)
			element = element->next;
		return element;
	}

	Row *searchRowByIndex(Matrix *matrix, int rowIndex) {
		return search(matrix->head, rowIndex);
	}

	Cell *searchCellByIndex(Row* row, int columnIndex) {
		return search(row->cells, columnIndex);
	}

	Row *pushRow(Matrix* matrix, int rowIndex) {
		Row* newRow = createRow(rowIndex);

		if (!matrix->head) {
			matrix->head = matrix->tail = newRow;
			return newRow;
		}

		if (rowIndex < matrix->head->index) {
			newRow->next = matrix->head;
			matrix->head = newRow;
			return newRow;
		}

		Row *row = searchRowByIndex(matrix, rowIndex);

		if (exists(row, rowIndex)) {
			delete newRow;
			return row;
		}

		if (!row->next) {
			newRow->next = nullptr;
			row->next = newRow;
			matrix->tail = newRow;
			return newRow;
		}

		newRow->next = row->next;
		row->next = newRow;

		return newRow;
	}

	void pushCell(Row* row, int columnIndex, int value) {
		Cell* newCell = createCell(columnIndex, value);

		if (!row->cells) {
			newCell->next = row->cells;
			row->cells = newCell;
			row->cellsCount++;
			return;
		}

		if (columnIndex < row->cells->index) {
			newCell->next = row->cells;
			row->cells = newCell;
			row->cellsCount++;
			return;
		}

		Cell* cell = searchCellByIndex(row, columnIndex);

		if (exists(cell, columnIndex)) {
			delete newCell;
			throw "CellAlreadyExistsException";
		}

		newCell->next = cell->next;
		cell->next = newCell;
		row->cellsCount++;
	}

	void swapFirstCells(Row *row) {
		Cell *tmp = row->cells;
		row->cells = tmp->next;
		tmp->next = row->cells->next;
		row->cells->next = tmp;
	}

	void swapIntermediateCells(Cell *prevCell) {
		Cell* tmp = prevCell->next;
		prevCell->next = tmp->next;
		tmp->next = prevCell->next->next;
		prevCell->next->next = tmp;
	}

	int compareCells(Cell *cell, int(*keyExtractor)(Cell* cell)) {
		if (!cell->next) {
			std::cout << "here" << std::endl;
			return -1;
		}
		return keyExtractor(cell) - keyExtractor(cell->next);
	}

	Cell* getNthCell(Row* row, int n) {
		Cell* cell = row->cells;

		for (int i = 1; i < n; i++)
			cell = cell->next;

		return cell;
	}

	void sortCells(Row *row, int(*keyExtractor)(Cell *cell)) {
		Cell *cell = nullptr;

		for (int i = 0; i < row->cellsCount - 1; i++) {
			cell = row->cells;

			if (compareCells(cell, keyExtractor) > 0)
				swapFirstCells(row);

			for (int j = 1; j < row->cellsCount - 1 - i; j++) {
				cell = getNthCell(row, j);
				if (compareCells(cell->next, keyExtractor) > 0)
					swapIntermediateCells(cell);
			}
		}
	}  

	void sortMatrix(Matrix* matrix, int(*keyExtractor)(Cell* cell)) {
		Row* row = matrix->head;

		while (row) {
			sortCells(row, keyExtractor);
			row = row->next;
		}
	}

	bool haveCeilsSameValues(Cell* cell) {
		return cell->value == cell->next->value && cell->value != 0;
	}

	void pushBackRow(Matrix *matrix, Row *row) {
		if (!matrix->head)
			matrix->head = row;
		else
			matrix->tail->next = row;
		matrix->tail = row;
	}

	Row* cloneRow(Cell* cells, int rowIndex) {
		Row* newRow = createRow(rowIndex);
		Cell* cell = cells;
		bool isSame = false;

		while (cell->next) {
			if (haveCeilsSameValues(cell)) {
				pushCell(newRow, cell->index, cell->value);
				isSame = true;
			}
			else if (isSame) {
				pushCell(newRow, cell->index, cell->value);
				isSame = false;
			}
			cell = cell->next;
		} 
		if (isSame) {
			pushCell(newRow, cell->index, cell->value);
			isSame = false;
		}

		return newRow;
	}

	Matrix* cloneMatrix(Matrix* matrix) {
		Matrix *newMatrix = createMatrix();
		newMatrix->m = matrix->m;
		newMatrix->n = matrix->n;
		Row* row = matrix->head;
		Row* newRow;

		while (row) {
			newRow = cloneRow(row->cells, row->index);
			pushBackRow(newMatrix, newRow);
			row = row->next;
		}

		return newMatrix;
	}

	bool isValidInput(int& num, int min, int max) {
		return std::cin.good() && min <= num && num <= max;
	}

	void refreshCin() {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}

	int getInt(int min, int max, const char* message = "") {
		int num;
		std::cout << message;
		std::cin >> num;

		while (!isValidInput(num, min, max)) {
			refreshCin();
			std::cout << "Incorrect input\n\n" << message;
			std::cin >> num;
		}

		refreshCin();

		return num;
	}

	void setMatrixSize(Matrix* matrix) {
		matrix->m = getInt(1, INT_MAX, "Enter number of rows: ");
		matrix->n = getInt(1, INT_MAX, "Enter number of columns: ");
		std::cout << std::endl;
	}

	void getCellParams(Matrix* matrix, int *cellParams) {
		cellParams[0] = getInt(1, matrix->m, "Enter row index: ");
		cellParams[1] = getInt(1, matrix->n, "Enter column index: ");
		cellParams[2] = getInt(INT_MIN, INT_MAX, "Enter ceil value: ");
		std::cout << std::endl;
	}

	void eraseRow(Row* row) {
		Cell* cell = row->cells;
		if (!cell) return;

		Cell* nextCell = cell->next;

		while (cell) {
			nextCell = cell->next;
			delete cell;
			cell = nextCell;
		}
	}

	void eraseMatrix(Matrix* matrix) {
		Row* row = matrix->head;

		if (!row) {
			delete matrix;
			return;
		}

		Row* nextRow = row->next;

		while (row) {
			nextRow = row->next;
			delete row;
			row = nextRow;
		}

		delete matrix;
	}

	const char* actions[] = {
		"Finish work",
		"Add value to matrix",
		"Print matrix",
		"Create new matrix and finish work"
	};

	const int NUM_OF_ACTIONS = sizeof(actions) / sizeof(actions[0]);

	void printActions() {
		for (int i = 0; i < NUM_OF_ACTIONS; i++)
			std::cout << i << ". " << actions[i] << std::endl;
	}

	void addValue(Matrix* matrix) {
		int *cellParams = new int[3];
		getCellParams(matrix, cellParams);
		Row* row = pushRow(matrix, cellParams[0]);

		try {
			pushCell(row, cellParams[1], cellParams[2]);
		}
		catch (const char* message) {
			std::cout << message << std::endl;
		}

		delete[] cellParams;
	}

	void executeTask(Matrix* matrix) {
		if (!matrix->head) {
			std::cout << "Empty matrix\n" << std::endl;
			return;
		};

		sortMatrix(matrix, getCellValue);
		Matrix* newMatrix = cloneMatrix(matrix);
		sortMatrix(matrix, getCellIndex);

		std::cout << "origin matrix:" << std::endl;
		printMatrix(matrix);

		std::cout << "new matrix:" << std::endl;
		printMatrix(newMatrix);

		eraseMatrix(newMatrix);
	}

	void executeAction(int action, Matrix* matrix) {
		switch (action) {
		case 0:
			break;
		case 1:
			addValue(matrix);
			break;
		case 2:
			printMatrix(matrix);
			break;
		case 3:
			executeTask(matrix);
			break;
		default:
			break;
		}
	}

	void dialog(Matrix* matrix) {
		int action = 0;
		do {
			printActions();
			action = getInt(0, NUM_OF_ACTIONS, "Enter action number: ");
			std::cout << std::endl;
			executeAction(action, matrix);
		} while (action);
	}
}

using namespace std;
using namespace lab1;

int main() {
/*
	Matrix* matrix = createMatrix();
	setMatrixSize(matrix);
	dialog(matrix);
	eraseMatrix(matrix);*/

	int a;
	cin >> a;
	cout << cin.good();
	cin >> a;
	cout << cin.fail();

	return 0;
}

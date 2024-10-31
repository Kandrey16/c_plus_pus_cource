#include <iostream> 
#include <map>
#include <cctype> 

using namespace std;

class PolybiusSquare {
private:
    map<char, pair<int, int>> table;
    char square[5][5] = { 
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'K'},  
        {'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z'}
    };
    
    string getNeighborCoordinates(int row, int col, int dRow, int dCol) {
        int newRow = row + dRow;
        int newCol = col + dCol;

        // Убедимся, что не выходим за границы массива 5x5.
        if (newRow >= 0 && newRow < 5 && newCol >= 0 && newCol < 5) {
            return to_string(newRow + 1) + to_string(newCol + 1);
        }
        return "";
    }
public:
    PolybiusSquare() {
        for (int i = 0; i < 5; i++) { 
            for (int j = 0; j < 5; j++) { 
                table[square[i][j]] = {i + 1, j + 1};  
            }
        }
    }
    
    string encode(const string& text) {
        string result = "";
        for (char c : text) {
            c = toupper(c);
            if (c == 'J') c = 'I';  // J заменяем на I.
            if (table.find(c) != table.end()) {
                int row = table[c].first - 1;  // Получаем строку (индекс с 0).
                int col = table[c].second - 1;  // Получаем столбец (индекс с 0).
                
                // Основная координата символа.
                result += "Original: " + string(1, c) + " (" + to_string(row + 1) + ", " + to_string(col + 1) + ") ";
                
                // Выводим соседей: (-1,1), (1,1), (-1,-1), (1,-1).
                result += "Neighbors: ";
                
                // Сосед (-1, 1).
                string neighbor1 = getNeighborCoordinates(row, col, -1, 1);
                if (!neighbor1.empty()) result += neighbor1 + " ";
                
                // Сосед (1, 1).
                string neighbor2 = getNeighborCoordinates(row, col, 1, 1);
                if (!neighbor2.empty()) result += neighbor2 + " ";
                
                // Сосед (-1, -1).
                string neighbor3 = getNeighborCoordinates(row, col, -1, -1);
                if (!neighbor3.empty()) result += neighbor3 + " ";
                
                // Сосед (1, -1).
                string neighbor4 = getNeighborCoordinates(row, col, 1, -1);
                if (!neighbor4.empty()) result += neighbor4 + " ";
                
                result += "\n";  // Перевод строки после вывода символа и его соседей.
            }
        }
        return result;
    }
    
    void printSquare() {
        for (int i = 0; i < 5; i++) {  
            for (int j = 0; j < 5; j++) {  
                cout << square[i][j] << " ";  
            }
            cout << endl;  
        }
    }
};

int main()
{
    PolybiusSquare polybius;
    
    string text;
    cout << "Введите слово: ";
    getline(cin, text);
    
    cout << "Квадрат полибуса: " << endl;
    polybius.printSquare();
    
    cout << "Результат: " << polybius.encode(text) << endl;

    return 0;
}
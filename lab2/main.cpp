#include <iostream>
#include "../Common/queue.h"

using namespace std;

void removeNegatives(Queue<int>& queue) {
    int initialCount = queue.count();
    for (int i = 0; i < initialCount; ++i) {
        int num = queue.unqueue();
        if (num >= 0) {
            queue.queue(num);
        }
    }
}


int countOccurrences(Queue<int>& queue, int value) {
    int countMatch = 0;
    int total = queue.count();
    for (int i = 0; i < total; ++i) {
        int num = queue.unqueue();
        if (num == value) {
            countMatch++;
        }
        queue.queue(num);
    }
    return countMatch;
}


void insertBeforeNegatives(Queue<int>& queue) {
    int initialCount = queue.count();
    for (int i = 0; i < initialCount; ++i) {
        int num = queue.unqueue();
        if (num < 0) {
            queue.queue(1);
        }
        queue.queue(num);
    }
}

void clearInput() {
    cin.clear();
    while (cin.get() != '\n');
}


void displayMenu() 
{
    cout << "1. Добавить элемент в очередь" << endl;
    cout << "2. Извлечь элемент из очереди" << endl;
    cout << "3. Показать количество элементов в очереди" << endl;
    cout << "4. Очистить очередь" << endl;
    cout << "5. Вставить 1 перед каждым отрицательным числом" << endl;
    cout << "6. Удалить все отрицательные числа" << endl;
    cout << "7. Подсчитать количество вхождений числа" << endl;
    cout << "8. Выйти" << endl;
    cout << "Выберите действие: ";
}

int main() {
    Queue<int> queue;
    int choice;

    while (true) {
        displayMenu();

        if (!(cin >> choice)) {
            cout << "Ошибка: введите число от 1 до 8." << endl;
            clearInput();
            continue;
        }

        switch (choice) {
            case 1: {
                int num;
                cout << "Введите число: ";
                if (!(cin >> num)) {
                    cout << "Ошибка: некорректный ввод." << endl;
                    clearInput();
                } else {
                    queue.queue(num);
                    cout << "Элемент добавлен." << endl;
                }
                break;
            }

            case 2: {
                try {
                    int item = queue.unqueue();
                    cout << "Извлечённый элемент: " << item << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }

            case 3: {
                cout << "Количество элементов в очереди: " << queue.count() << endl;
                break;
            }

            case 4: {
                queue.clear();
                cout << "Очередь очищена." << endl;
                break;
            }

            case 5: {
                if (queue.count() == 0) {
                    cout << "Очередь пуста." << endl;
                } else {
                    insertBeforeNegatives(queue);
                    cout << "Вставка выполнена." << endl;
                }
                break;
            }

            case 6: {
                if (queue.count() == 0) {
                    cout << "Очередь пуста." << endl;
                } else {
                    removeNegatives(queue);
                    cout << "Удаление выполнено." << endl;
                }
                break;
            }

            case 7: {
                int value;
                cout << "Введите число для подсчёта: ";
                if (!(cin >> value)) {
                    cout << "Ошибка: некорректный ввод." << endl;
                    clearInput();
                } else {
                    int result = countOccurrences(queue, value);
                    cout << "Число " << value << " встречается " << result << " раз(а)." << endl;
                }
                break;
            }

            case 8:
                cout << "Выход из программы." << endl;
                return 0;

            default:
                cout << "Неверный выбор. Повторите попытку." << endl;
        }

        cout << endl;
    }

    return 0;
}
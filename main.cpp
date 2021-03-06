#include <tuple>
#include "SetsAndGraphs.h"

using namespace std;

///Множество M, образы которого находятся для соответствий A и B, и интервал его значений.
Set M;
const int aM = 25, bM = 30;
///Множество N, прообразы которого находятся для соответствий A и B, и интервал его значений.
Set N;
const int aN = 20, bN = 25;
///Множество W, на котором задаётся сужение соответствий A и В, и интервалы его значений.
Set W;
const int aW = 15, bW = 25;
///График Z, на котором задаётся продолжение соответствий A и B.
Graph Z;

///Объявления типа данных - соответствие.
typedef tuple<Graph, Set, Set> Accord;

///Предельная мощность графиков A и B.
const int graphCardinality = 30;

///Интервалы значений множеств X, Y, U, V.
const int aX = 1, bX = 30;
const int aY = 20, bY = 40;
const int aU = 15, bU = 50;
const int aV = 5, bV = 35;

///Прототипы используемых функций.
Accord accordIntersection(Accord, Accord);
Accord accordDifference(Accord, Accord);
Accord accordSymDiff(Accord, Accord);
Accord accordUnion(Accord, Accord);
Accord accordInversion(Accord);
Accord accordComposition(Accord, Accord);
Set accordImage(Accord);
Set accordPreimage(Accord);
Accord accordContraction(Accord);
Accord accordExtending(Accord);


/** Функция нахождения пересечения двух соответствий.
 *  Аргументы функции - два соответствия: A и B.
 *  Функция возвращает соответствие I.
 */
Accord accordIntersection(Accord A, Accord B)
{
    Accord I; ///Выделение памяти под пересечение

    ///Нахождение пересечения C графиков соответствий A и B
    Graph C;
    C = graphIntersection(get<0>(A), get<0>(B));
    get<0>(I) = C;

    ///Нахождение пересечения H областей отправления соответствий A и B
    Set H;
    H = setIntersection(get<1>(A), get<1>(B));
    get<1>(I) = H;

    ///Нахождение пересечения J областей прибытия соответствий A и B
    Set J;
    J = setIntersection(get<2>(A), get<2>(B));
    get<2>(I) = J;

    return I;
}

/** Функция нахождения объединения двух соответствий.
 *  Аргументы функции - два соответствия: A и B.
 *  Функция возвращает соответствие U.
 */
Accord accordUnion(Accord A, Accord B)
{
    Accord U; ///Выделение памяти под объединение

    ///Нахождение объединения D графиков соответствий A и B
    Graph D;
    D = graphUnion(get<0>(A), get<0>(B));
    get<0>(U) = D;

    ///Нахождение объединения K областей отправления соответствий A и B
    Set K;
    K = setUnion(get<1>(A), get<1>(B));
    get<1>(U) = K;

    ///Нахождение объединения L областей прибытия соответствий A и B
    Set L;
    L = setUnion(get<2>(A), get<2>(B));
    get<2>(U) = L;

    return U;
}

/** Функция нахождения разности двух соответствий.
 *  Аргументы функции - два соответствия: A и B.
 *  Функция возвращает соответствие D.
 */
Accord accordDifference(Accord A, Accord B)
{
    Accord D; ///Выделение памяти под разность

    ///Нахождение разности R графиков соответствий A и B
    Graph R;
    R = graphDifference(get<0>(A), get<0>(B));
    get<0>(D) = R;

    ///Нахождение разности T областей отправления соответствий A и B
    Set T;
    T = setDifference(get<1>(A), get<1>(B));
    get<1>(D) = T;

    ///Нахождение разности Q областей прибытия соответствий A и B
    Set Q;
    Q = setDifference(get<2>(A), get<2>(B));
    get<2>(D) = Q;

    return D;
}

/** Функция нахождения симметрической разности двух соответствий.
 *  Аргументы функции - два соответствия: A и B.
 *  Функция возвращает соответствие J.
 */
Accord accordSymDiff(Accord A, Accord B)
{
    Accord J; ///Выделение памяти под симметрическую разность

    ///Нахождение симметрической разности G графиков соответствий A и B
    Graph S;
    S = graphSymDiff(get<0>(A), get<0>(B));
    get<0>(J) = S;

    ///Нахождение симметрической разности O областей отправления соответствий A и B
    Set O;
    O = setSymDiff(get<1>(A), get<1>(B));
    get<1>(J) = O;

    ///Нахождение симметрической разности H областей прибытия соответствий A и B
    Set H;
    H = setSymDiff(get<2>(A), get<2>(B));
    get<2>(J) = H;

    return J;
}

/** Функция нахождения композиции двух соответствий.
 *  Аргументы функции - два соответствия: A и B.
 *  Функция возвращает соответствие С.
 */
Accord accordComposition(Accord A, Accord B)
{
    Accord C; ///Выделение памяти под композицию

    ///Нахождение композиции K графиков соответствий A и B
    Graph K;
    K = graphComposition(get<0>(A), get<0>(B));
    get<0>(C) = K;

    ///Определение области отправления композиции
    get<1>(C) = get<1>(A);

    ///Определение области прибытия композиции
    get<2>(C) = get<2>(B);

    return C;
}

/** Функция нахождения инверсии соответствия.
 *  Аргумент функции - соответствие А.
 *  Функция возвращает соответствие E.
 */
Accord accordInversion(Accord A)
{
    Accord E; ///Выделение памяти под инверсию

    ///Нахождение инверсии I графика соответствия A
    Graph I;
    I = graphInversion(get<0>(A));
    get<0>(E) = I;

    ///Определение области отправления инверсии
    get<1>(E) = get<2>(A);

    ///Определение области прибытия инверсии
    get<2>(E) = get<1>(A);

    return E;
}


/** Функция нахождения образа множества M при соответствии.
 *  Аргумент функции - соответствие А.
 *  Функция возвращает множество O.
 */
Set accordImage(Accord A)
{
    Set O; ///Выделение памяти для образа

    Graph& g = get<0>(A);

    if (g.empty()) ///Если график соответствия пустой
        return O;  ///возвращаем пустой график

    for (size_t i = 0; i < g.size(); i++) ///обход по всем элементам графика соответствия
    {
        if (contains(M, g[i].first)) ///Если первая компонента кортежа принадлежит множеству M
            O.push_back(g[i].second); ///добавляем вторую компоненту в образ O
    }

    return O;
}

/** Функция нахождения прообраза множества N при соответствии.
 *  Аргумент функции - соответствие А.
 *  Функция возвращает множество P.
 */
Set accordPreimage(Accord A)
{
    Set P; ///Выделение памяти для прообраза

    Graph& g = get<0>(A);

    if (g.empty()) ///Если график соответствия пустой
        return P;  ///возвращаем пустой график

    for (size_t i = 0; i < g.size(); i++) ///обход по всем элементам графика соответствия
    {
        if (contains(N, g[i].second)) ///Если вторая компонента кортежа принадлежит множеству N
            P.push_back(g[i].first); ///добавляем первую компоненту в прообраз P
    }

    return P;
}

/** Функция нахождения сужения соответствия A на множестве W.
 *  Аргумент функции - соответствие А.
 *  Функция возвращает соответствие S.
 */
Accord accordContraction(Accord A)
{
    Accord S; ///Выделение памяти под сужение

    ///Нахождения пересечения H графика и декартова произведения множеств W и Y
    Graph H;
    H = graphIntersection(get<0>(A), setCartesian(W, get<2>(A)));
    get<0>(S) = H;

    ///Определение области отправления сужения
    get<1>(S) = get<1>(A);
    ///Определение области прибытия сужения
    get<2>(S) = get<2>(A);

    return S;
}

/** Функция нахождения продолжения соответствия A на графике Z.
 *  Аргумент функции - соответствие А.
 *  Функция возвращает соответствие P.
 */
Accord accordExtending(Accord A)
{
    int zSize;
    cout<<"Введите мощность графика продолжения Z: ";
    readInteger(zSize);
    Z.reserve(zSize);
    cout<<"Введите элементы графика Z: "<<endl;
    for (int i = 0; i < zSize; i++)
    {
        cout<<"№"<<i+1<<" ";
        readPair(Z[i]);
    }
    cout<<endl;

    Accord P; ///Выделение памяти под продолжение

    ///Определение графика продолжения
    get<0>(P) = Z;
    ///Определение области отправления продолжения
    get<1>(P) = get<1>(A);
    ///Определение области прибытия продолжения
    get<2>(P) = get<2>(A);

    return P;
}

///Функция вывода на экран соответствия
void printAccord(Accord& acc, string title)
{
    ///Очистка консоли
    if (system("CLS"))
        system("clear");

    cout<<title<<":"<<endl;
    cout << "-----------------------------------------------------------------" << endl;
    ///Вывод всех элементов графика соответствия
    cout << "График: ";
    if (get<0>(acc).empty())
        cout<<"---"<<endl;
    else
    {
        for (auto i: get<0>(acc))
            cout << "<" << i.first << "," << i.second << "> ";
        cout<<endl;
    }

    ///Вывод всех элементов области отправления
    cout << "Область отправления: ";
    if (get<1>(acc).empty())
        cout<<"---"<<endl;
    else
    {
        for (auto j: get<1>(acc))
            cout<<j<<" ";
        cout<<endl;
    }

    ///Вывод всех элементов области прибытия
    cout << "Область прибытия: ";
    if (get<2>(acc).empty())
        cout<<"---"<<endl;
    else
    {
        for (auto k: get<2>(acc))
            cout<<k<<" ";
        cout<<endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
}

///Функция освобождения памяти из-под графика
template<class T>
void deleteVector(vector<T> vec)
{
    vec.clear();
    vec.shrink_to_fit();
}

///Функция освобождения памяти из-под соответствия
void deleteAccord(Accord& acc)
{
    deleteVector(get<0>(acc));
    deleteVector(get<1>(acc));
    deleteVector(get<2>(acc));
}

///Функция заполнения областей отправления и прибытия соответствий A и B, а также множеств M, N, W
void fillSets(Accord& A, Accord& B)
{
    for (int i = aM; i <= bM; i++) ///Заполнение множества M
        M.push_back(i);
    for (int j = aN; j <= bN; j++) ///Заполнение множества N
        N.push_back(j);
    for (int k = aW; k <= bW; k++) ///Заполнение множества W
        W.push_back(k);

    Set& X = get<1>(A);
    Set& Y = get<2>(A);
    Set& U = get<1>(B);
    Set& V = get<2>(B);

    for (int i = aX; i <= bX; i++) ///Заполнение множества X
        X.push_back(i);
    for (int i = aY; i <= bY; i++) ///Заполнение множества Y
        Y.push_back(i);
    for (int i = aU; i <= bU; i++) ///Заполнение множества U
        U.push_back(i);
    for (int i = aV; i <= bV; i++) ///Заполнение множества V
        V.push_back(i);
}

int main()
{
    setlocale(0,"");

    Accord A; ///выделение памяти под соответствие A
    Accord B; ///выделение памяти под соответствие B
    int numA; ///мощность графика G
    int numB; ///мощность графика F
    pair<int,int> temp; ///вспомогательная переменная

    ///ввод мощности графика G с проверкой соответствия значения мощности условию
    do
    {
        cout << "Введите мощность графика первого соответствия: ";
        readInteger(numA); ///ввод мощности графика G
        if (numA < 0)
            cout<<"Мощность графика не может быть отрицательной!"<<endl;
        if (numA > graphCardinality)
            cout<<"Мощность графика превышает максимально допустимую("<<graphCardinality<<")!"<<endl;
    }
    while (numA < 0 || numA > graphCardinality);

    ///ввод мощности графика F с проверкой соответствия значения мощности условию
    do
    {
        cout << "Введите мощность графика второго соответствия: ";
        readInteger(numB); ///ввод мощности графика F
        if (numB < 0)
            cout<<"Мощность графика не может быть отрицательной!"<<endl;
        if (numB > graphCardinality)
            cout<<"Мощность графика превышает максимально допустимую("<<graphCardinality<<")!"<<endl;
    }
    while (numB < 0 || numB > graphCardinality);

    ///Вызов функции заполнения множеств M, N, W, X, Y, U, V
    fillSets(A, B);

    if(numA != 0) ///если мощность графика G не равна нулю
    {
        cout << "Введите элементы графика G:" << endl;
        for (int i = 0; i < numA; i++) ///то для каждого элемента
        {
            ///ввод значения с проверкой на повторное вхождение элементов в график
            bool exists;
            bool proper1 = false, proper2 = false;
            do
            {
                cout << "Элемент №" << i+1 << " - ";
                readPair(temp);
                if (exists = contains(get<0>(A), temp))
                {
                    cout<<"Элемент уже содержится в множестве! Введите другое значение."<<endl;
                    continue;
                }
                if (!(proper1 = contains(get<1>(A), temp.first)))
                    cout<<"Первая компонента не принадлежит области отправления!"<<endl;
                if (!(proper2 = contains(get<2>(A), temp.second)))
                    cout<<"Вторая компонента не принадлежит области прибытия!"<<endl;
            }
            while (exists || !proper1 || !proper2);
            get<0>(A).push_back(temp); ///добавление значения в график
        }
    }
    else ///иначе, выводим информацию о том, что G - пустой график
        cout << "G - пустой график." << endl << endl;

    printAccord(A, "Соответствие A");

    if(numB != 0) ///если мощность графика F не равна нулю
    {
        cout << "Введите элементы графика F:" << endl;
        for (int i = 0; i < numB; i++) ///то для каждого элемента
        {
            ///ввод значения с проверкой на повторное вхождение элементов в график
            bool exists;
            bool proper1 = false, proper2 = false;
            do
            {
                cout << "Элемент №" << i+1 << " - ";
                readPair(temp);
                if (exists = contains(get<0>(B), temp))
                {
                    cout<<"Элемент уже содержится в множестве! Введите другое значение."<<endl;
                    continue;
                }
                if (!(proper1 = contains(get<1>(B), temp.first)))
                    cout<<"Первая компонента не принадлежит области отправления!"<<endl;
                if (!(proper2 = contains(get<2>(B), temp.second)))
                    cout<<"Вторая компонента не принадлежит области прибытия!"<<endl;
            }
            while (exists || !proper1 || !proper2);
            get<0>(B).push_back(temp); ///добавление значения в график
        }
        cout << endl;
    }
    else ///иначе, выводим информацию о том, что F - пустой график
        cout << "F - пустой график." << endl << endl;

    printAccord(B, "Соответствие B");

    int choice; ///переменная, отвечающая за выбор пользователя
    while(true) ///бесконечный цикл вывода меню
    {
        cout << "Выберите операцию:"                           << endl
             << "1)Пересечение соответствий A и B"             << endl
             << "2)Объединение соответствий A и B"             << endl
             << "3)Разность соответствий A и B"                << endl
             << "4)Разность соответствий B и A"                << endl
             << "5)Симметрическая разность соответствий A и B" << endl
             << "6)Инверсия соответствия A"                    << endl
             << "7)Инверсия соответствия B"                    << endl
             << "8)Композиция соответствий A и B"              << endl
             << "9)Композиция соответствий B и A"              << endl
             << "10)Образ множества M при соответствии A"      << endl
             << "11)Прообраз множества N при соответствии A"   << endl
             << "12)Образ множества M при соответствии B"      << endl
             << "13)Прообраз множества N при соответствии B"   << endl
             << "14)Сужение соответствия A"                    << endl
             << "15)Продолжение соответствия A"                << endl
             << "16)Сужение соответствия B"                    << endl
             << "17)Продолжение соответствия B"                << endl
             << "0)Выход из программы"                         << endl
             << "Ваш выбор: ";
        readInteger(choice); ///ввод номера операции
        if (choice < 0 || choice > 17)
        {
            if (system("CLS")) ///очистка консоли
                system("clear");
            cout<<"Введите число от 0 до 17..."<<endl;
        }

        switch (choice) ///Выполнение операции в зависимости от выбора пользователя
        {
        case 1: ///если было выбрано пересечение
        {
            ///вызов функции нахождения пересечения соответствий
            Accord intersect = accordIntersection(A, B);
            ///вывод пересечения соответствий на экран
            printAccord(intersect, "Пересечение");
            ///высвобождение памяти из-под пересечения
            deleteAccord(intersect);
            break;
        }
        case 2: ///если было выбрано объединение
        {
            ///вызов функции нахождения объединения соответствий
            Accord un = accordUnion(A, B);
            ///вывод объединения соответствий на экран
            printAccord(un, "Объединение");
            ///высвобождение памяти из-под объединения
            deleteAccord(un);
            break;
        }
        case 3: ///если была выбрана разность A и B
        {
            ///вызов функции нахождения разности соответствий A и B
            Accord differenceAB = accordDifference(A, B);
            ///вывод разности соответствий А и В на экран
            printAccord(differenceAB, "Разность A и B");
            ///высвобождение памяти из-под разности
            deleteAccord(differenceAB);
            break;
        }
        case 4: ///если была выбрана разность B и A
        {
            ///вызов функции нахождения разности соответствий B и A
            Accord differenceBA = accordDifference(B, A);
            ///вывод разности соответствий В и А на экран
            printAccord(differenceBA, "Разность B и A");
            ///высвобождение памяти из-под разности
            deleteAccord(differenceBA);
            break;
        }
        case 5: ///если была выбрана симметрическая разность A и B
        {
            ///вызов функции нахождения симметрической разности соответствий A и B
            Accord symdiff = accordSymDiff(A, B);
            ///вывод симметрической разности соответствий А и В на экран
            printAccord(symdiff, "Симметрическая разность");
            ///высвобождение памяти из-под симметрической разности
            deleteAccord(symdiff);
            break;
        }
        case 6: ///если была выбрана инверсия соответствия A
        {
            ///вызов функции нахождения инверсии соответствия A
            Accord inversion = accordInversion(A);
            ///вывод инверсии соответствия А на экран
            printAccord(inversion, "Инверсия A");
            ///высвобождение памяти из-под инверсии
            deleteAccord(inversion);
            break;
        }
        case 7: ///если была выбрана инверсия соответствия B
        {
            ///вызов функции нахождения инверсии соответствия B и вывод его на экран
            Accord inversion = accordInversion(B);
            ///вывод инверсии соответствия B на экран
            printAccord(inversion, "Инверсия B");
            ///высвобождение памяти из-под инверсии
            deleteAccord(inversion);
            break;
        }
        case 8: ///если была выбрана композиция соответствий A и B
        {
            ///вызов функции нахождения композиции соответствий A и B и вывод её на экран
            Accord composition = accordComposition(A, B);
            ///вывод композиции соответствий А и В на экран
            printAccord(composition, "Композиция A и B");
            ///высвобождение памяти из-под композиции
            deleteAccord(composition);
            break;
        }
        case 9: ///если была выбрана композиция соответствий B и А
        {
            ///вызов функции нахождения композиции соответствий B и А
            Accord composition = accordComposition(B, A);
            ///вывод композиции соответствий B и А на экран
            printAccord(composition, "Композиция B и A");
            ///высвобождение памяти из-под композиции
            deleteAccord(composition);
            break;
        }
        case 10: ///если был выбран образ для соответствия A
        {
            ///вызов функции нахождения образа множества M при соответствии A
            Set image = accordImage(A);
            ///вывод образа множества M на экран
            ///Очистка консоли
            if (system("CLS"))
                system("clear");
            cout<<"Образ при соответствии A:"<<endl;
            if (image.empty())
                cout<<"---";
            for (const auto i : image)
                cout<<endl<<i<<" ";
            cout<<endl;
            ///высвобождение памяти из-под образа
            deleteVector(image);
            break;
        }
        case 11: ///если был выбран прообраз для соответствия A
        {
            ///вызов функции нахождения прообраза множества N при соответствии A
            Set preimage = accordPreimage(A);
            ///вывод прообраза множества N на экран
            ///Очистка консоли
            if (system("CLS"))
                system("clear");
            cout<<"Прообраз при соответствии A:"<<endl;
            if (preimage.empty())
                cout<<"---";
            for (const auto i : preimage)
                cout<<endl<<i<<" ";
            cout<<endl;
            ///высвобождение памяти из-под прообраза
            deleteVector(preimage);
            break;
        }
        case 12: ///если был выбран образ для соответствия A
        {
            ///вызов функции нахождения образа множества M при соответствии B
            Set image = accordImage(B);
            ///вывод образа множества M на экран
            ///Очистка консоли
            if (system("CLS"))
                system("clear");
            cout<<"Образ при соответствии B:"<<endl;
            if (image.empty())
                cout<<"---";
            for (const auto i : image)
                cout<<endl<<i<<" ";
            cout<<endl;
            ///высвобождение памяти из-под образа
            deleteVector(image);
            break;
        }
        case 13: ///если был выбран прообраз для соответствия B
        {
            ///вызов функции нахождения прообраза множества N при соответствии B
            Set preimage = accordPreimage(B);
            ///вывод прообраза множества N на экран
            ///Очистка консоли
            if (system("CLS"))
                system("clear");
            cout<<"Прообраз при соответствии B:"<<endl;
            if (preimage.empty())
                cout<<"---";
            for (const auto i : preimage)
                cout<<endl<<i<<" ";
            cout<<endl;
            ///высвобождение памяти из-под прообраза
            deleteVector(preimage);
            break;
        }
        case 14: ///если было выбрано сужения соответствия A
        {
            ///вызов функции нахождения сужения соответствия A
            Accord contr = accordContraction(A);
            ///вывод сужения соответствия A на экран
            printAccord(contr, "Сужение A");
            ///высвобождение памяти из-под сужения
            deleteAccord(contr);
            break;
        }
        case 15: ///если было выбрано продолжение соответствия A
        {
            ///вызов функции нахождения продолжения соответствия A
            Accord ext = accordExtending(A);
            ///вывод продолжения соответствия A на экран
            printAccord(ext, "Продолжение A");
            ///высвобождение памяти из-под продолжения
            deleteAccord(ext);
            break;
        }
        case 16: ///если было выбрано сужения соответствия B
        {
            ///вызов функции нахождения сужения соответствия B
            Accord contr = accordContraction(B);
            ///вывод сужения соответствия A на экран
            printAccord(contr, "Сужение B");
            ///высвобождение памяти из-под сужения
            deleteAccord(contr);
            break;
        }
        case 17: ///если было выбрано продолжение соответствия B
        {
            ///вызов функции нахождения продолжения соответствия B
            Accord ext = accordExtending(B);
            ///вывод продолжения соответствия B на экран
            printAccord(ext, "Продолжение B");
            ///высвобождение памяти из-под продолжения
            deleteAccord(ext);
            break;
        }
        case 0: ///если был выбран выход из программы
            return 0; ///закрываем программу
        }
    }
    return 0;
}

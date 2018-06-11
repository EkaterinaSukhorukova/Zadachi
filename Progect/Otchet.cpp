

\documentclass[a4paper,11pt]{article}
\usepackage[T1]{fontenc}
\usepackage[utf8]{inputenc}
\usepackage{lmodern}

\usepackage{amsfonts}
\usepackage{hyperref}
\usepackage{graphicx}
\usepackage[english, russian]{babel}


\begin{document}

\maketitle
\Huge {Проект по программированию}
\\
\\
\\
\huge \textbf {"Построение скелета многоугольника"}
\\
\\
\\
\\
\\
\\
\\
\\
\\
\\
\author{Автор: студентка 151 группы}
\\
\author{Сухоруковой Екатерины}



\newpage

\maketitle
\tableofcontents


\newpage
\huge {\chapter{Постановка задачи}}
\\
Построить скелет многоугольника по заданным точкам.
\\Все точки задаются случайным образом. В качестве многоугольника рассматривается миниимальная выпуклая оболочка множества заданных точек. 

\section {Определения:}
\subsection {Минимальная выпуклая оболочка множества точек} 
- это минимальная по длинне замкнутая линия, заключающая в себе (или проходящая через) все точки исходного множества.

\subsection {Скелет многоугольника}
- это множество точек, равноудаленных от сторон многоуольника.

\subsection {Узлы скелета многоугольника }
- a) Точки "слияния" вершин многоугольном при равномерном сжимании многоугольника к его центру. (Все стороны многоугольника начинат движение к центру фигуры с одной скоростью. точки, в которые сливаются вершины - узлы.)
\\- b) Центры максимальных по радиусу вписанных в фигуру окружностей. (представляем точку, двигающуюся по бисектриссе сообтетствующего угла. окружност, вписанная в угол расширяется до тех пор, пока не "наткнется" на сторону многоугольника, не принадлежащую исходному углу.)


\chapter {Решение}
\section {Алгоритмы}
\subsection {План работы програмы:}

1. Создание структур Точка (Point) и Прямая (Direct)

2. Определение функций:

\begin{itemize}
\item Обмена точек (swap)
\item Ближайший к вершине (NextToTop)
\item Проверка на левую тройку вектоов (orientation)
\item Компановки (compare)
\item Функции поворота (за счет определения правой/левой тройти векторов)
\item Алгоритм Грэхема формирования минимальной выпуклой оболочки (GrahamScan)
\\ - Находим самую нижнюю точку, выбираем самую левую, в случае совпадения.
\\ - Помещаем данную точку с самое начало очереди
\\ - Сортируем оставшиеся точки по полярному углу 
\\ - По отсортированному массиву точек строим выпуклую оболочку (Если рассматривается правая тройка, то точка входит в оболоку, если левая - то нет. Оболочка формирется только из точек, которые образуют правые повороты.)
\item Алгоритм генерации множества точек (genRandPointVariety)
\item Алгоритм генерации выпуклого многоугольника (genLargeRectangle)
\item Заполнение массива структур, определяющих уравления прямых, проходящих через точку (вершину), а также вывод уравнения биссектрисы соответствующего внутреннего угла (PointDirection)
\item Нахождение узлов скелета (Skelet)
\end{itemize}
3. Поочередный вызов определенных ранее функций (main)


\subsection {Описание работы програмы}
\\
На вход программа получает натуральное число. Это число обозначает количество точек, задающихся рандомным образом. Каждая точка характеризуется двумя координатами (X и Y). Каждая точка - структура, с соответствующими параметрами. Все точки записываются в массив структур. Массив сортируется, а также удаляются одинаковые точки, если они есть. По данным массива формируется минимальная выпуклая оболочка (для этого используется алгоритм Грэхема). В конце в массиве остаются только те точки, которые принадлежат оболочке.
\\
После того, как сформирован массив точек оболочки, формируется второй массив структур. В данном массиве хранятся данные по тем прямым, которые содержат стороны получившегося вногоугольника. Каждая прямая характеризуется тремя числами: A, B, C. Коэффициенты при X, Y и свободном члене, соответственно. Коэффициенты находятся исходя из основного уравнения построения прямой в Евклидовом пространстве: (X-X1)(Y2-Y1)=(Y-Y1)(X2-X1), где X1, X2, Y1, Y2 - координаты точек, прринадлежащих прямой. 
\\
Также в данный массив запиываются координаты прямой, содержащей бисектриссу соответствующего внутреннего угла многоугольника (к примеру: в ячейке под номеом 3, соответствующей 3 точке в массиве точек оболочки, содержатся структуры, соответствующие прямым 23, 34 и бисектриссе угла 234, где цифры - номера соответствующих точек.)
\\
Бисктрисса угла ищется следущим образом: находятся координаты векторов, изходящих из точки оболочки к двум соседним. Эти вектора нормаруются и складываютя (покоординатно). Получившиеся координаты - координаты векторы бисектриссы, что проверяется элементарнойгеометрией. 
\\
Все точки, лежащие на прямой, содержащей бисектриссу параметризуются (прямая задается в параметрическом виде). Далее ищется точка, которая принадлежит прямой, содержащей бисектриссу, равноудалена от трех сторон многоугольника, а расстояние до всех остальных сторон больше, чем до трех прямых, упомянутых ранее. Это реализуется перебором и подсчетом расстояния от точки до прямой.
\\
Таким образом ищутся узлы скелета. Все подходящие точки записываются в новый массив.
\\ 
Программа выводит на экрам коэффициенты узлов скелета многоугольника.




\end{document}

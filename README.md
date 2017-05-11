# UnixPthread
Задание 4
Разработать программу, вычисляющую f(x)=Exp(-x2/2)/Sqrt(2*Пи).

Для нахождения Пи и Exp(-x2/2) программа должна создать 2 потока, которые выполняются параллельно. По завершении обоих потоков программа должна вычислить результирующее выражение.

Требования к реализации:

	•	Вычисление Pi и Exp(-x2/2) должно производиться с использованием библиотеки pthreads в отдельных потоках (потоки должны выполняться параллельно, без блокировок); 
  
	•	Результат должен быть вычислен после завершения обоих потоков; 
  
	•	В потоках необходимо использовать барьер

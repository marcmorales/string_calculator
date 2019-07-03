This program reads a string and to be evaluated into a numerical expression.
For example:
	5 plus 2 - 1
	1 + 2 * 3
	(7 divided by 2) times 20

The calculator MUST follow general math computation rule. Multiplication/Division first before Addition/Subtraction. PADMAS
	It can and cannot accept unknown value not meant for computation.
	The user can enter whatever they want when asked what to compute but the calculator must respond with detailed explanation
	why its not acceptable such as plus or add is equal to + but dog gives back an error message.

This program is a trial phase for when we create a program that automatically construct sentences.
Context-free grammar is what we are trying to develop.

TODO, rough idea how the program will function:
	
	Layman's term regarding the program:

	* Introduction about the program, showing the user its functions and current limits
		limits are a must as we need to have a starting point. Once we have a decent logic running is when we will add
		more features.

	* Ask the user to enter a string expression to be evaluated.
		The catch of this calculator is that it can detect and translate string literals into their numeric values.
			ex: 1 = one, plus/add = +, divided by = /, etc.
	
	* The string will be scanned and translated into a readable numerical expression
		* Develop a context-free grammar rule (Term grammar)
			E = expression, T = term, F = factor, n = number
				E -> T + or - E
				E -> T
				T -> F / or * T
  				T -> F
				F -> (E)
				F -> n
		
		* Develop a filter that can extract whatever the user enter (either a funciton or hash tables)
		* Develop a tokenizer to extract string values
		* Create a toekn evaluator 
	
	* Returns an answer or an error if the user entered unknwon values.
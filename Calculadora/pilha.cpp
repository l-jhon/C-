#include "pilha.h"

Pilha::Pilha()
{

	topo = NULL;
}

void Pilha::push(char x) 
{
	Node *no = new Node();
	no->x = x;
	no->prox = topo;
	topo = no;

}

char Pilha::pop() 
{
	char x;

	if (topo)
	{
		Node *aux = topo;
		x = aux->x;
		topo = topo->prox;
		delete (aux);
		return x;

	}
	return 0;
}


char Pilha::get_top() 
{
	if (topo)
	{
		return topo->x;
	}
	return 0;
}

string Pilha::posfixa(string exp)
{

	string pos;

	exp = "(" + exp + ")";
		
	for (int i = 0; i<exp.size(); i++)
	{
		if (exp[i] == '(' || exp[i] == ')' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
		{
			if (exp[i] == '(')
			{
				push(exp[i]);
			}
			else
			{
				if (topo->x == '(' && (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')) //  [i]posição de algum char
				{
					push(exp[i]);
				}

				else
				{

					if ((topo->x == '+' || topo->x == '-') && (exp[i] == '*' || exp[i] == '/' || exp[i] == '^'))
					{
						push(exp[i]);
					}

					else
					{
						if ((topo->x == '*' || topo->x == '/' || topo->x == '^') && (exp[i] == '+' || exp[i] == '-'))
						{
							pos += pop();
							push(exp[i]);
						}
						else
						{
							if (topo->x == '(' && (exp[i] == '-' || exp[i] == '+'))
							{
								push(exp[i]);
							}
							else
							{
								if (topo->x == '(' && (exp[i] == '*' || exp[i] == '/'))
								{
									push(exp[i]);
								}
								else
								{
									if ((topo->x == '^') && (exp[i] == '^'))
									{
										pos = pos + pop();
										push(exp[i]);
									}
									else
									{
										if (topo->x == '(' && (exp[i] == '^'))
										{
											push(exp[i]);
										}
										else
										{
											if ((topo->x == '*' || topo->x == '/') && (exp[i] == '*' || exp[i] == '/'))
											{
												pos += pop();
												push(exp[i]);
											}
											else
											{
												if ((topo->x == '+' || topo->x == '-') && (exp[i] == '+' || exp[i] == '-'))
												{
													push(exp[i]);
												}
												else
												{
													if ((topo->x == '*' || topo->x == '/') && (exp[i] == '^'))
													{
														push(exp[i]);
													}
													else
													{
														if (exp[i] == ')')
														{

															while (topo->x != '(')
															{
																pos += pop();
															}
															pop();
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}

			}
		}
			else
			pos += exp[i];
	}
return pos;

}













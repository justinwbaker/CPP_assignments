// ConsoleApplication1.cpp : Defines the entry point for the console application.
// Author: Justin Baker
// input: the answer to a question(yes/no)
// output: the name of the person they are guessing or another question

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*
// question 
cout << "Does the person have ?" << endl;
cin >> answer;

// if answere is invalid ask again
while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
	cout << answer << " not a valid entry, please enter again..." << endl;
	cin >> answer;
}

//has a beard
if (answer.compare("yes") == 0) {
	
}
//not beard
else if (answer.compare("no") == 0) {
	
}

*/


int main() {
	string answer("");

	// question 1
	cout << "Does the person have dark hair?" << endl;
	cin >> answer;

	// if answere is invalid ask again
	while (!(answer.compare("yes") == 0  || answer.compare("no") == 0)) {
		cout << answer << " not a valid entry, please enter again..." << endl;
		cin >> answer;
	}

	// has dark hair
	if (answer.compare("yes") == 0) {
		// question 2
		cout << "Does the person have dark skin?" << endl;
		cin >> answer;

		// if answere is invalid ask again
		while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
			cout << answer << " not a valid entry, please enter again..." << endl;
			cin >> answer;
		}

		// has dark skin
		if (answer.compare("yes") == 0) {
			// question 3
			cout << "Does the person have a mustache?" << endl;
			cin >> answer;

			// if answere is invalid ask again
			while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
				cout << answer << " not a valid entry, please enter again..." << endl;
				cin >> answer;
			}

			// has mustache
			if (answer.compare("yes") == 0) {
				// question 4
				cout << "Does the person have a beard?" << endl;
				cin >> answer;

				// if answere is invalid ask again
				while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
					cout << answer << " not a valid entry, please enter again..." << endl;
					cin >> answer;
				}

				// has beard
				if (answer.compare("yes") == 0) {
					cout << "The person is Paul" << endl;
				}
				// not beard
				else if (answer.find("no") == 0) {
					cout << "The person is Jules" << endl;
				}

			}
			// not mustahce
			else if (answer.find("no") == 0) {
				cout << "The person is Marvin" << endl;
			}

		}
		// not dark skin
		else if (answer.find("no") == 0) {
			// question 3
			cout << "Does the person have glasses?" << endl;
			cin >> answer;

			// if answere is invalid ask again
			while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
				cout << answer << " not a valid entry, please enter again..." << endl;
				cin >> answer;
			}

			//has glasses
			if (answer.compare("yes") == 0) {
				cout << "Person is Buddy" << endl;
			}
			//not glasses
			else if (answer.compare("no") == 0) {
				// question 4
				cout << "Does the person have a beard?" << endl;
				cin >> answer;

				// if answere is invalid ask again
				while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
					cout << answer << " not a valid entry, please enter again..." << endl;
					cin >> answer;
				}

				//has a beard
				if (answer.compare("yes") == 0) {
					cout << "Person is Maynard" << endl;
				}
				//not beard
				else if (answer.compare("no") == 0) {
					// question 5
					cout << "Does the person have long hair?" << endl;
					cin >> answer;

					// if answere is invalid ask again
					while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
						cout << answer << " not a valid entry, please enter again..." << endl;
						cin >> answer;
					}

					//has long hair
					if (answer.compare("yes") == 0) {
						//question 6
						cout << "is the person male?" << endl;
						cin >> answer;

						// if answere is invalid ask again
						while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
							cout << answer << " not a valid entry, please enter again..." << endl;
							cin >> answer;
						}

						//male
						if (answer.compare("yes") == 0) {
							cout << "the person is Vincent" << endl;
						}
						//female
						else if (answer.compare("no") == 0) {
							// question 7
							cout << "Does the person have big red lips?" << endl;
							cin >> answer;

							// if answere is invalid ask again
							while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
								cout << answer << " not a valid entry, please enter again..." << endl;
								cin >> answer;
							}

							//has big red lips
							if (answer.compare("yes") == 0) {
								cout << "the person is Esmeralda" << endl;
							}
							//not big red lips
							else if (answer.compare("no") == 0) {
								// qestion 8
								cout << "Does the person have a confused expression?" << endl;
								cin >> answer;

								// if answere is invalid ask again
								while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
									cout << answer << " not a valid entry, please enter again..." << endl;
									cin >> answer;
								}

								//has a confused expression
								if (answer.compare("yes") == 0) {
									cout << "the person is Trudy" << endl;
								}
								//not confused expression
								else if (answer.compare("no") == 0) {
									// question 9
									cout << "Does the person have brown hair?" << endl;
									cin >> answer;

									// if answere is invalid ask again
									while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
										cout << answer << " not a valid entry, please enter again..." << endl;
										cin >> answer;
									}

									//has brown hair
									if (answer.compare("yes") == 0) {
										cout << "the person is Tudi" << endl;
									}
									//not brown hair
									else if (answer.compare("no") == 0) {
										// question 10
										cout << "Does the person have a serious expression?" << endl;
										cin >> answer;

										// if answere is invalid ask again
										while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
											cout << answer << " not a valid entry, please enter again..." << endl;
											cin >> answer;
										}

										//has a serious expression
										if (answer.compare("yes") == 0) {
											cout << "The person is Mia" << endl;
										}
										//not serious expression
										else if (answer.compare("no") == 0) {
											cout << "The person is Fabienne" << endl;
										}
									}
								}
							}
						}
					}
					//not long hair
					else if (answer.compare("no") == 0) {
						// question 6
						cout << "Does the person have messy hair?" << endl;
						cin >> answer;

						// if answere is invalid ask again
						while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
							cout << answer << " not a valid entry, please enter again..." << endl;
							cin >> answer;
						}

						//has messy hair
						if (answer.compare("yes") == 0) {
							cout << "The person is Jimmie" << endl;
						}
						//not messy hair
						else if (answer.compare("no") == 0) {
							// question 7
							cout << "Does the person have a dead serious expression?" << endl;
							cin >> answer;

							// if answere is invalid ask again
							while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
								cout << answer << " not a valid entry, please enter again..." << endl;
								cin >> answer;
							}

							//has messy hair
							if (answer.compare("yes") == 0) {
								cout << "The person is Captain Koons" << endl;
							}
							//not messy hair
							else if (answer.compare("no") == 0) {
								// question 8
								cout << "Does the person have almost no hair?" << endl;
								cin >> answer;

								// if answere is invalid ask again
								while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
									cout << answer << " not a valid entry, please enter again..." << endl;
									cin >> answer;
								}

								//has almost no hair
								if (answer.compare("yes") == 0) {
									cout << "The person is Butch" << endl;
								}
								//not almost no hair
								else if (answer.compare("no") == 0) {
									// question 9
									cout << "Does the person have a mustache?" << endl;
									cin >> answer;

									// if answere is invalid ask again
									while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
										cout << answer << " not a valid entry, please enter again..." << endl;
										cin >> answer;
									}

									//has a mustache
									if (answer.compare("yes") == 0) {
										cout << "The person is Winston" << endl;
									}
									//not mustache
									else if (answer.compare("no") == 0) {
										cout << "The person is Brett" << endl;
									}
								}
							}
						}
					}
				}
			}
		}

	}
	// not dark hair
	else if (answer.find("no") == 0) {
		// question 2
		cout << "Does the person have hair?" << endl;
		cin >> answer;

		// if answere is invalid ask again
		while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
			cout << answer << " not a valid entry, please enter again..." << endl;
			cin >> answer;
		}

		//has a beard
		if (answer.compare("yes") == 0) {
			// question 3
			cout << "Does the person have a beard?" << endl;
			cin >> answer;

			// if answere is invalid ask again
			while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
				cout << answer << " not a valid entry, please enter again..." << endl;
				cin >> answer;
			}

			//has a beard
			if (answer.compare("yes") == 0) {
				cout << "The person is Lance" << endl;
			}
			//not beard
			else if (answer.compare("no") == 0) {
				// question 4
				cout << "Does the person have light blond hair?" << endl;
				cin >> answer;

				// if answere is invalid ask again
				while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
					cout << answer << " not a valid entry, please enter again..." << endl;
					cin >> answer;
				}

				//has a beard
				if (answer.compare("yes") == 0) {
					// question 5
					// question 
					cout << "is the person male?" << endl;
					cin >> answer;

					// if answere is invalid ask again
					while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
						cout << answer << " not a valid entry, please enter again..." << endl;
						cin >> answer;
					}

					//has a beard
					if (answer.compare("yes") == 0) {
						cout << "The person is Zed" << endl;
					}
					//not beard
					else if (answer.compare("no") == 0) {
						cout << "The person is Jody" << endl;
					}
				}
				//not beard
				else if (answer.compare("no") == 0) {
					// question 5
					cout << "Does the person have orange hair?" << endl;
					cin >> answer;

					// if answere is invalid ask again
					while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
						cout << answer << " not a valid entry, please enter again..." << endl;
						cin >> answer;
					}

					//has orange hair
					if (answer.compare("yes") == 0) {
						cout << "The person is Yolanda" << endl;
					}
					//not orange hair
					else if (answer.compare("no") == 0) {
						//question 6
						cout << "is the person male?" << endl;
						cin >> answer;

						// if answere is invalid ask again
						while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
							cout << answer << " not a valid entry, please enter again..." << endl;
							cin >> answer;
						}

						//has a beard
						if (answer.compare("yes") == 0) {
							// question 7
							cout << "Does the person have long bangs?" << endl;
							cin >> answer;

							// if answere is invalid ask again
							while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
								cout << answer << " not a valid entry, please enter again..." << endl;
								cin >> answer;
							}

							//has a long bangs
							if (answer.compare("yes") == 0) {
								cout << "The person is Roger" << endl;
							}
							//not long bangs
							else if (answer.compare("no") == 0) {
								cout << "Ther person is Ringo" << endl;
							}
						}
						//not beard
						else if (answer.compare("no") == 0) {
							cout << "The person is Raquel" << endl;
						}
					}
				}
			}
		}
		//not beard
		else if (answer.compare("no") == 0) {
			// question 3
			cout << "Does the person have a mask?" << endl;
			cin >> answer;

			// if answere is invalid ask again
			while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
				cout << answer << " not a valid entry, please enter again..." << endl;
				cin >> answer;
			}

			//has a beard
			if (answer.compare("yes") == 0) {
				cout << "Person is The Gimp" << endl;
			}
			//not beard
			else if (answer.compare("no") == 0) {
				cout << "Marcellus" << endl;
			}
		}
	}

	
	return 0;
}


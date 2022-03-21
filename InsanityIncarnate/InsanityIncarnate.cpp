#include <iostream>
#include<vector>
#include <ctime>
#include <chrono>
using namespace std;


int solutions = 0;
//goes up once everytime a solution is found

int check = 1;
//goes up once every time a solution is checked 

bool Display = true;


int ticker = 0;
//goes up once for every tower checked 


//DISPLAY WITH CHECKS OPTIMIZED FOR COMPARISON
void display(int cube1[6], int cube2[6], int cube3[6], int cube4[6])
{
	int counter = 0;

	cout << "cube 1 is: ";           //displays all the cube arrays

	while (counter < 6)
	{
		cout << cube1[counter] << ", ";


		counter++;
	}
	counter = 0;
	cout << "cube 2 is: ";

	while (counter < 6)
	{
		cout << cube2[counter] << ", ";


		counter++;
	}
	counter = 0;

	cout << "cube 3 is: ";

	while (counter < 6)
	{
		cout << cube3[counter] << ", ";


		counter++;
	}
	counter = 0;

	cout << "cube 4 is: ";

	while (counter < 6)
	{
		cout << cube4[counter] << ", ";


		counter++;
	}

	cout << "     check # " << check << endl;


}

//flips a cube forward
void forwardFlip(int arr[6])
{

	swap(arr[0], arr[1]);

	swap(arr[1], arr[3]);

	swap(arr[0], arr[2]);



}

//flips a cube backward
void backFlip(int arr[6])
{

	swap(arr[2], arr[3]);

	swap(arr[0], arr[2]);

	swap(arr[1], arr[3]);





}

//cube rolls left
void leftFlip(int arr[6])
{

	swap(arr[4], arr[5]);

	swap(arr[0], arr[4]);

	swap(arr[1], arr[5]);



}

//cube rolls right
void rightFlip(int arr[6])
{
	swap(arr[0], arr[1]);

	swap(arr[0], arr[4]);

	swap(arr[1], arr[5]);




}

//cube top becomes cube bottom 
void fullFlip(int arr[6]) //
{

	swap(arr[0], arr[1]);

	swap(arr[2], arr[3]);





}

//rotate cube clockwise(bottom and top stay same)
void rotateClockwise(int arr[6])
{

	swap(arr[4], arr[5]);

	swap(arr[2], arr[4]);

	swap(arr[3], arr[5]);







}

// SOLUTION VIEWER
void viewSolutions(vector<int> VectorSolutions)
{

	int solutionNumber = 1;

	int counter = 0;

	int value = 2;

	while (solutionNumber < solutions + 1)
	{

		cout << endl << "................................................................................................." << endl;

		cout << "cube 1 is: ";

		while (counter < 4)
		{

			cout << VectorSolutions.at(value) << ", ";

			counter++;
			value++;
		}
		counter = 0;
		value += 2;


		cout << "cube 2 is: ";

		while (counter < 4)
		{

			cout << VectorSolutions.at(value) << ", ";

			counter++;
			value++;
		}
		counter = 0;
		value += 2;

		cout << "cube 3 is: ";

		while (counter < 4)
		{

			cout << VectorSolutions.at(value) << ", ";

			counter++;
			value++;
		}
		counter = 0;
		value += 2;

		cout << "cube 4 is: ";

		while (counter < 4)
		{

			cout << VectorSolutions.at(value) << ", ";

			counter++;
			value++;
		}
		counter = 0;
		value += 2;

		solutionNumber++;
	}




}






int rotateChecks(int cube1[6], int cube2[6], int cube3[6], int cube4[6], vector<int>& VectorSolutions)
{
	int rotations = 1;

	while (rotations < 5)
	{
		rotateClockwise(cube4);
		//this is the really long condition for success
		if ((cube1[2] != cube2[2] && cube1[2] != cube3[2] && cube1[2] != cube4[2]) && (cube2[2] != cube3[2] && cube2[2] != cube4[2]) && (cube3[2] != cube4[2]) && (cube1[3] != cube2[3] && cube1[3] != cube3[3] && cube1[3] != cube4[3]) && (cube2[3] != cube3[3] && cube2[3] != cube4[3]) && (cube3[3] != cube4[3]) && (cube1[4] != cube2[4] && cube1[4] != cube3[4] && cube1[4] != cube4[4]) && (cube2[4] != cube3[4] && cube2[4] != cube4[4]) && (cube3[4] != cube4[4]) && (cube1[5] != cube2[5] && cube1[5] != cube3[5] && cube1[5] != cube4[5]) && (cube2[5] != cube3[5] && cube2[5] != cube4[5]) && (cube3[5] != cube4[5]))
		{
			if (Display == true)
				display(cube1, cube2, cube3, cube4);

			//display as soon as solution is found

			//then save solution to dynamic vector
			int counter = 0;
			while (counter < 6) // saving cube 1 
			{

				VectorSolutions.push_back(cube1[counter]);


				counter++;



			}
			//	Savedsolutions[solutions][0][counter] = 0;
			counter = 0;

			while (counter < 6) // saving cube 2
			{

				VectorSolutions.push_back(cube2[counter]);
				counter++;



			}
			//	Savedsolutions[solutions][1][counter] = 0;
			counter = 0;

			while (counter < 6) // saving cube 3
			{

				VectorSolutions.push_back(cube3[counter]);
				counter++;



			}
			//Savedsolutions[solutions][2][counter] = 0;
			counter = 0;

			while (counter < 6) // saving cube 4
			{

				VectorSolutions.push_back(cube4[counter]);

				counter++;



			}



			counter = 0;




			solutions++;


		}

		check++;
		rotations++;


	}


	return(solutions);
}

int fourthCube(int cube1[6], int cube2[6], int cube3[6], int cube4[6], vector<int>& VectorSolutions)
{
	int flips = 0; //5 of these in total, front front front left, full


	int rotations = 1; //each flip involving 4 rotate-checks

 //this counts how many times the orientation was checked


	while (flips < 6) //all flips and rotate checks for an entire cube
	{

		if (flips == 4)  //left flip and 4 rotatechecks
		{
			leftFlip(cube4);
			flips++;

			rotateChecks(cube1, cube2, cube3, cube4, VectorSolutions);


		}
		else if (flips == 5) //full flip and 4 rotatechecks
		{



			//do a full flip
			fullFlip(cube4);
			flips++;

			rotateChecks(cube1, cube2, cube3, cube4, VectorSolutions);
		}
		else //4 front flips each with 4 rotatechecks
		{

			//do a front flip
			forwardFlip(cube4);
			flips++;

			rotateChecks(cube1, cube2, cube3, cube4, VectorSolutions);


		}



	}

	return(solutions);
}

int thirdCube(int cube1[6], int cube2[6], int cube3[6], int cube4[6], vector<int>& VectorSolutions)
{

	int flips = 0;
	int rotations = 0;

	while (flips < 6)
	{
		if (flips == 4)  //left flip and 4 rotatechecks
		{
			leftFlip(cube3);
			flips++;

			while (rotations < 4)
			{


				rotateClockwise(cube3);
				fourthCube(cube1, cube2, cube3, cube4, VectorSolutions);
				rotations++;
			}
			rotations = 0;

		}
		else if (flips == 5) //full flip and 4 rotatechecks
		{



			//do a full flip
			fullFlip(cube3);
			flips++;



			while (rotations < 4)
			{


				rotateClockwise(cube3);
				fourthCube(cube1, cube2, cube3, cube4, VectorSolutions);
				rotations++;
			}
			rotations = 0;
		}
		else //4 front flips each with 4 rotatechecks
		{

			//do a front flip
			forwardFlip(cube3);
			flips++;

			while (rotations < 4)
			{


				rotateClockwise(cube3);
				fourthCube(cube1, cube2, cube3, cube4, VectorSolutions);
				rotations++;
			}
			rotations = 0;



		}





	}




	return(solutions);
}

int secondcube(int cube1[6], int cube2[6], int cube3[6], int cube4[6], vector<int>& VectorSolutions)
{
	int flips = 0;
	int rotations = 0;

	while (flips < 6)
	{
		if (flips == 4)  //left flip and 4 rotatechecks
		{
			leftFlip(cube2);
			flips++;

			while (rotations < 4)
			{


				rotateClockwise(cube2);
				thirdCube(cube1, cube2, cube3, cube4, VectorSolutions);
				rotations++;
			}
			rotations = 0;

		}
		else if (flips == 5) //full flip and 4 rotatechecks
		{



			//do a full flip
			fullFlip(cube2);
			flips++;



			while (rotations < 4)
			{


				rotateClockwise(cube2);
				thirdCube(cube1, cube2, cube3, cube4, VectorSolutions);
				rotations++;
			}
			rotations = 0;
		}
		else //4 front flips each with 4 rotatechecks
		{

			//do a front flip
			forwardFlip(cube2);
			flips++;

			while (rotations < 4)
			{


				rotateClockwise(cube2);
				thirdCube(cube1, cube2, cube3, cube4, VectorSolutions);
				rotations++;
			}
			rotations = 0;



		}





	}



	return(solutions);
}

void Starter(int cube1[6], int cube2[6], int cube3[6], int cube4[6], vector<int>& VectorSolutions)
{








	secondcube(cube1, cube2, cube3, cube4, VectorSolutions);
	forwardFlip(cube1);
	secondcube(cube1, cube2, cube3, cube4, VectorSolutions);
	rightFlip(cube1);
	secondcube(cube1, cube2, cube3, cube4, VectorSolutions);















}

void Initialize(int cube1[6], int cube2[6], int cube3[6], int cube4[6], int Bigcube1[6], int Bigcube2[6], int Bigcube3[6], int Bigcube4[6])
{

	int counter = 0;


	while (counter < 6)
	{
		cube1[counter] = Bigcube1[counter]; 




		counter++; 
	}
	counter = 0;
	while (counter < 6)
	{
		cube2[counter] = Bigcube2[counter];




		counter++;
	}
	counter = 0;
	while (counter < 6)
	{
		cube3[counter] = Bigcube3[counter];




		counter++;
	}
	counter = 0;
	while (counter < 6)
	{
		cube4[counter] = Bigcube4[counter];




		counter++;
	}




}



void Combinations1(int cube[6], int cube1[6], int cube2[6], int cube3[6], int cube4[6], vector<int>& VectorSolutions, int Bigcube1[6], int Bigcube2[6], int Bigcube3[6], int Bigcube4[6], vector<int>& Nightmare)
{
	int front = 1;
	int back = 1;
	int left = 1;
	int right = 1;

	while (front < 5)
	{
		
		
		cube[2] = front;



		while (back < 5)
		{
			cube[3] = back;



			while (left < 5)
			{
				cube[4] = left;


				while (right < 5)
				{
					cube[5] = right;
					check = 0;
					
					VectorSolutions.clear();
					Initialize(cube1, cube2, cube3, cube4, Bigcube1, Bigcube2, Bigcube3, Bigcube4);
					Starter(cube1, cube2, cube3, cube4, VectorSolutions);
					
					if (solutions == 1)
					{
						int counter = 0;
						while (counter < 6) // saving cube 1 
						{
							Nightmare.push_back(cube1[counter]);
							counter++;
						}
						counter = 0;
						while (counter < 6) // saving cube 2
						{
							Nightmare.push_back(cube2[counter]);
							counter++;
						}
						counter = 0;
						while (counter < 6) // saving cube 3
						{
							Nightmare.push_back(cube3[counter]);
							counter++;
						}
						counter = 0;
						while (counter < 6) // saving cube 4
						{
							Nightmare.push_back(cube4[counter]);
							counter++;
							cout << "found one   ";
							cout << "size of nightmare is " << Nightmare.size() << endl; 
						}
						counter = 0;

					}

					solutions = 0;
					ticker++;
					if (ticker == 1)
					{
						std::time_t t = std::time(0);   // get time now
						
					
						cout << "first tower checked at " << time(0) << endl;
					}
					if (ticker == 100)
					{
						std::time_t t = std::time(0);   // get time now


						cout << "hundred tower checked at " << time(0) << endl;
					}
					if (ticker == 1000)
					{
						std::time_t t = std::time(0);   // get time now


						cout << "thousand tower checked at " << time(0) << endl;
					}
					if (ticker == 1000000)
					{

						std::time_t t = std::time(0);
						cout << "one million towers checked " << endl;
					}
					if (ticker == 10000000)
					{
						std::time_t t = std::time(0);
						cout << "ten million towers checked " << endl;
					}
					if (ticker == 100000000)
					{
						std::time_t t = std::time(0);
						cout << "hundred million towers checked " << endl;
					}
					if (ticker == 1000000000)
					{
						std::time_t t = std::time(0);
						cout << "one billion towers checked " << endl;
					}
					if (ticker == 10000000000)
					{
						std::time_t t = std::time(0);
						cout << "ten billion towers checked " << endl;
					}
					if (ticker == 100000000000)
					{
						std::time_t t = std::time(0);
						cout << "hundred billion towers checked " << endl;
					}
					if (ticker == 1000000000000)
					{
						std::time_t t = std::time(0);
						cout << "one trillion towers checked " << endl;
					}

					right++;
				}


				right = 1; 
				left++;
			}



			left = 1;
			back++;
		}

		back = 1;
		front++;
	}








}


//vector<int> Nightmare;
// vector<int>& Nightmare;
//first thing is edited cube
void Combinations2(int cube[6], int cube1[6], int cube2[6], int cube3[6], int cube4[6], vector<int>& VectorSolutions, int Bigcube1[6], int Bigcube2[6], int Bigcube3[6], int Bigcube4[6], vector<int>& Nightmare)
{
	int front = 1;
	int back = 1;
	int left = 1;
	int right = 1;

	while (front < 5)
	{


		cube[2] = front;



		while (back < 5)
		{
			cube[3] = back;



			while (left < 5)
			{
				cube[4] = left;


				while (right < 5)
				{
					cube[5] = right;
					Combinations1(Bigcube1, cube1, cube2, cube3, cube4, VectorSolutions, Bigcube1, Bigcube2, Bigcube3, Bigcube4, Nightmare);


					right++;
				}


				right = 1;
				left++;
			}



			left = 1;
			back++;
		}

		back = 1;
		front++;
	}



}

void Combinations3(int cube[6], int cube1[6], int cube2[6], int cube3[6], int cube4[6], vector<int>& VectorSolutions, int Bigcube1[6], int Bigcube2[6], int Bigcube3[6], int Bigcube4[6], vector<int>& Nightmare)
{
	int front = 1;
	int back = 1;
	int left = 1;
	int right = 1;

	while (front < 5)
	{


		cube[2] = front;



		while (back < 5)
		{
			cube[3] = back;



			while (left < 5)
			{
				cube[4] = left;


				while (right < 5)
				{
					cube[5] = right;
					Combinations2(Bigcube2, cube1, cube2, cube3, cube4, VectorSolutions, Bigcube1, Bigcube2, Bigcube3, Bigcube4, Nightmare);


					right++;
				}


				right = 1;
				left++;
			}



			left = 1;
			back++;
		}

		back = 1;
		front++;
	}



}


void combinations4(int cube[6], int cube1[6], int cube2[6], int cube3[6], int cube4[6], vector<int>& VectorSolutions, int Bigcube1[6], int Bigcube2[6], int Bigcube3[6], int Bigcube4[6], vector<int>& Nightmare)
{
	int front = 1;
	int back = 1;
	int left = 1;
	int right = 1;

	while (front < 5)
	{


		cube[2] = front;



		while (back < 5)
		{
			cube[3] = back;



			while (left < 5)
			{
				cube[4] = left;


				while (right < 5)
				{
					cube[5] = right;
					Combinations3(Bigcube3, cube1, cube2, cube3, cube4, VectorSolutions, Bigcube1, Bigcube2, Bigcube3, Bigcube4, Nightmare);


					right++;
				}


				right = 1;
				left++;
			}



			left = 1;
			back++;
		}

		back = 1;
		front++;
	}



}



int main()
{

	//array for each cube
   //each array organized as follows:  top, bottom,   front, back,    left, right
   //colors are represented as numbers
   //1-4
   //1 = yellow
   //2 = blue
   // 3 = green
   // 4 = red


   // top,bottom,front,back,left,right


	int cube1[6] = { 1, 2, 4, 4, 4, 3 }; // DEFAULT 1
	//int cube1[6] = { 1, 2, 3, 4, 4, 3 }; // 10 SOL 1
	///int cube1[6] = { 1, 2, 3, 4, 5, 6 };  //ALL SOL 1


	int cube2[6] = { 1, 3, 1, 4, 4, 2 }; // DEFAULT 2
	//int cube2[6] = { 1, 3, 1, 4, 4, 2 };  // 10 SOL 2
	//int cube2[6] = { 7, 8, 9, 10, 11, 12 }; //ALL SOL 2


	int cube3[6] = { 2, 1, 3, 3, 2, 4 }; // DEFAULT 3
	//int cube3[6] = { 2, 1, 1, 3, 2, 4 }; // 10 SOL 3
	///////int cube3[6] = { 13, 14, 15, 16, 17, 18 };  //ALL SOL 3

	int cube4[6] = { 1, 3, 1, 2, 3, 4 }; // DEFAULT 4
	//int cube4[6] = { 1, 3, 2, 2, 3, 4 }; // 10 SOL 4
	///int cube4[6] = { 19, 20, 21, 22, 23, 24 }; //ALL SOL 4








	//vector that increases in size with each solution
	vector<int> VectorSolutions;
	Display = false;


	

	//viewSolutions(VectorSolutions);

	//so a solution is 24 integers (4 cubes of 6 int)





	//the beginning of madness.....................................................................................................................................


	vector<int> Nightmare;


	int Bigcube1[6] = { 1, 1, 1, 1, 1, 1 };
	int Bigcube2[6] = { 1, 1, 1, 1, 1, 1 };
	int Bigcube3[6] = { 1, 1, 1, 1, 1, 1 };
	int Bigcube4[6] = { 1, 1, 1, 1, 1, 1 };



	bool first = true;
	bool second = true;
	bool third = true; 
	bool fourth = true; 
	

	//this below would find every possible tower for changing all numbers in one cube 

	//mmmm if my math is correct, then it will take 254 days to complete this program 
	//new estimate says 745 days 
	//hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm

	//complexity is 4^4 ^4 * 24^4 ish more or less
	//1 400 000 000 000 000
	//uhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
	//hm
	// thats 1.4 quadrillion things to do (and thats really still a slight underestimate)



	//(4^4)^4 towers
	//4^16 towers 
	//4294967296 towers 
	//3 seconds for a hundred  (1491 days)
	//17 for a thousand (845 days) 
	



	combinations4(Bigcube4, cube1, cube2, cube3, cube4, VectorSolutions, Bigcube1, Bigcube2, Bigcube3, Bigcube4, Nightmare);

	cout << ticker; 

	//th things you do everytime the tower orientation is changed at all
	/*
	check = 0;
	solutions = 0;
	VectorSolutions.clear();
	Initialize(cube1, cube2, cube3, cube4, Bigcube1, Bigcube2, Bigcube3, Bigcube4);
	Starter(cube1, cube2, cube3, cube4, VectorSolutions);

	*/


	//the starting arrays that will not change throughout a single tower solution finding sequence




































	//fun thing to compare every possible cube starting orientation
	// interesting..... 
	// 
	// so for four color, there are 4^6 ways for a single cube to be aligned
	// then (4 cubes) so (4^6)^4 ????
	// except that towers where cubes have swapped are essentially the same 
	// there are 4! duplicate towers so id overcount by 24 times 
	// do i want to overcount or eliminate beforehand.....
	// im not sure how i would
	// again its equivalnecy statement but it involves moving cubes.
	// i could brute force check 
	// i could do it 
	// maybe I create the entire "database" of towers first
	// 
	//cycle though ech cube possible makeup 
	//with general program
	//and generate big ol table
	//ONLY SAVE THE ONES WITH 8 SOLUTIONS

	//grab everything that has 8 solutions then other prgamr comparison 


	//PRINT TO FILE THEN GRAB FILE IN OTHER PROGRAM 
	// divide by 8 doesnt catch every duplicate 
	// then see if all sides are the same as eachiter literally identical 
	//make another program that runs after this 








	/*
	long long int hey1 = 0;
	while (hey1 < 4294967296)
	{

		hey1++;
		//300,000,000,000,000
		// (2.8147498e+14)
		//this is how many things the computers gotta do...........
		//(4^6)^4 =4^24 because there are 4 possible numbers and 6 places, then four cubes
		//i think thats simply too big 
		//so im going to only worry about changing the last 4 numbers 
		//4^4^4? = 4^16 = 4294967296
		//mmmmmm but does that lose some solutions......?
		//some starting orientations.....that hmmmmmmmm. 
		//no I dont think I will. If I get everything different on the outside, then the inside can be dealt with later
		//pretty sure but should talk about how to prove that


	}


	*/





	//what do we want
	///what we tried
	//why it didnt work, what worked why
	//finding false methods is valuable 
	//future work (what should be tried, or next steps)
}